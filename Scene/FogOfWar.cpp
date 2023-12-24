#include "FogOfWar.h"
//FogOfWar::FogOfWar() {}
FogOfWar::FogOfWar(Color originalColor, unsigned char minAlpha, unsigned char maxAlpha, int numRows, int numCols)
	: originalColor(originalColor), minAlpha(minAlpha), maxAlpha(maxAlpha)
{ 
	createShadows(colorShadows, numRows, numCols);
	createShadows(alphaShadows, numRows, numCols); 
	resetShadow();
}

void FogOfWar::createShadows(std::vector<std::vector<Shadow*>>& shadows, int numRows, int numCols)
{
	clearShadows(shadows);

	Vector2 pos = { 0,0 };
	float width = (float) SCREEN_WIDTH / (float) numCols;
	float height = (float) SCREEN_HEIGHT / (float) numRows;

	for (int row = 0; row < numRows; row++)
	{
		pos.x = 0;
		std::vector<Shadow*> rowOfShadows;
		for (int col = 0; col < numCols; col++)
		{
			rowOfShadows.push_back(new Shadow(pos, width, height, originalColor));
			pos.x += width;
		}
		pos.y += height;
		shadows.push_back(rowOfShadows);
	}
}
void FogOfWar::clearShadows(std::vector<std::vector<Shadow*>>& shadows)
{
	for (auto& rowOfShadows : shadows)
		for (auto& shadow : rowOfShadows)
			delete shadow;
	shadows.clear();
}

void FogOfWar::draw()
{
	for (auto& rowOfShadows : colorShadows)
		for (auto& shadow : rowOfShadows)
			shadow->draw();

	for (auto& rowOfShadows : alphaShadows)
		for (auto& shadow : rowOfShadows)
			shadow->draw();
}

void FogOfWar::resetShadow()
{
	for (auto& rowOfShadows : colorShadows)
		for (auto& shadow : rowOfShadows)
			shadow->setColor({originalColor.r, originalColor.g, originalColor.b, minAlpha });

	for (auto& rowOfShadows : alphaShadows)
		for (auto& shadow : rowOfShadows)
			shadow->setColor({ originalColor.r, originalColor.g, originalColor.b, maxAlpha });
}
void FogOfWar::handleLightSourceInfluence(Vector2 cameraPos, std::vector<LightSource*>& lightSources)
{
	for (auto& rowOfShadows : colorShadows)
		for (auto& shadow : rowOfShadows)
			shadow->handleLightSourceInfluenceColor(cameraPos, lightSources);

	for (auto& rowOfShadows : alphaShadows)
		for (auto& shadow : rowOfShadows)
			shadow->handleLightSourceInfluenceAlpha(cameraPos, lightSources);
}
void FogOfWar::checkAlphaBound()
{
	for (auto& rowOfShadows : colorShadows)
		for (auto& shadow : rowOfShadows)
			shadow->checkAlphaBound(minAlpha, maxAlpha);

	for (auto& rowOfShadows : alphaShadows)
		for (auto& shadow : rowOfShadows)
			shadow->checkAlphaBound(minAlpha, maxAlpha);
}

FogOfWar::~FogOfWar()
{
	clearShadows(colorShadows);
	clearShadows(alphaShadows);
}