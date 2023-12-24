#pragma once
#include "Header.h"
#include "Shadow.h"

class FogOfWar
{
private:
	Color originalColor;
	unsigned char minAlpha;
	unsigned char maxAlpha;

	std::vector<std::vector<Shadow*>> colorShadows;
	std::vector<std::vector<Shadow*>> alphaShadows;

public:
	//FogOfWar();
	FogOfWar(Color originalColor = { 0,0,0,255 }, unsigned char minAlpha = 0, unsigned char maxAlpha = 255, int numRows = 100, int numCols = 100);

	void createShadows(std::vector<std::vector<Shadow*>>& shadows, int numRows, int numCols);
	void clearShadows(std::vector<std::vector<Shadow*>>& shadows);

	void draw();

	void resetShadow();
	void handleLightSourceInfluence(Vector2 cameraPos, std::vector<LightSource*>& lightSources);
	void checkAlphaBound();

	~FogOfWar();
};