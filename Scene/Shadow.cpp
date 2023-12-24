#include "Shadow.h"

Shadow::Shadow() {}
Shadow::Shadow(Vector2 pos, float width, float height, Color color)
	: pos(pos), width(width), height(height), color(color) {}

Vector2 Shadow::getCenterPos() { return { pos.x - width / 2, pos.y - height / 2 }; }
void Shadow::setColor(Color color) { this->color = color; }

void Shadow::draw(Vector2 cameraPos) { DrawRectangle(pos.x - cameraPos.x, pos.y - cameraPos.y, width, height, color); }

Color Shadow::combineColors(std::vector<Color>& colors, std::vector<float>& weights)
{
	Color result;
	float r = 0, g = 0, b = 0;

	float totalWeight = 0;
	for (auto& weight : weights) totalWeight += weight;

	for (int i = 0; i < colors.size(); i++)
	{
		r += (float)colors.at(i).r * (float)weights.at(i);
		g += (float)colors.at(i).g * (float)weights.at(i);
		b += (float)colors.at(i).b * (float)weights.at(i);
	}

	r /= totalWeight;
	g /= totalWeight;
	b /= totalWeight;

	result.r = static_cast<unsigned char>(r);
	result.g = static_cast<unsigned char>(g);
	result.b = static_cast<unsigned char>(b);
	result.a = 0;

	return result;
}
void Shadow::handleLightSourceInfluenceColor(Vector2 cameraPos, std::vector<LightSource*>& lightSources)
{
	Vector2 centerPos = getCenterPos();
	std::vector<Color> colors;
	std::vector<float> weights;
	for (auto& lightSource : lightSources)
	{
		float distance = Vector2Length(Vector2Subtract(Vector2Subtract(lightSource->getPos(), cameraPos), centerPos));
		if (distance <= lightSource->getRange())
		{
			colors.push_back(lightSource->getColor());

			int newAlpha = (1 - distance / lightSource->getRange()) * lightSource->getIntensity();
			weights.push_back(newAlpha);
			if (newAlpha > 255) newAlpha = 255;
			if (color.a < newAlpha) color.a = newAlpha;
		}
	}
	int oldAlpha = color.a;
	color = combineColors(colors, weights);
	color.a = oldAlpha;
}
void Shadow::handleLightSourceInfluenceAlpha(Vector2 cameraPos, std::vector<LightSource*>& lightSources)
{
	Vector2 centerPos = getCenterPos();
	for (auto& lightSource : lightSources)
	{
		float distance = Vector2Length(Vector2Subtract(Vector2Subtract(lightSource->getPos(), cameraPos), centerPos));
		if (distance <= lightSource->getRange())
		{
			color.a *= distance / lightSource->getRange();
		}
	}
}
void Shadow::checkAlphaBound(unsigned char minAlpha, unsigned char maxAlpha)
{
	if (color.a < minAlpha) color.a = minAlpha;
	if (color.a > maxAlpha) color.a = maxAlpha;
}