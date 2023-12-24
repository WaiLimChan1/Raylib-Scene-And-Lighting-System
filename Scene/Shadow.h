#pragma once
#include "Header.h"
#include "LightSource.h"

class Shadow
{
private:
	Vector2 pos;
	float width;
	float height;
	Color color;

public:
	Shadow();
	Shadow(Vector2 pos, float width, float height, Color color);

	Vector2 getCenterPos();
	void setColor(Color color);

	void draw(Vector2 cameraPos = { 0,0 });

	Color combineColors(std::vector<Color>& colors, std::vector<float>& intensities);
	void handleLightSourceInfluenceColor(Vector2 cameraPos, std::vector<LightSource*>& lightSources);
	void handleLightSourceInfluenceAlpha(Vector2 cameraPos, std::vector<LightSource*>& lightSources);
	void checkAlphaBound(unsigned char minAlpha, unsigned char maxAlpha);
};