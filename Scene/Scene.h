#pragma once
#include "Header.h"
#include "Background.h"

class Scene
{
private:
	float topOfGround;
	float bottomOfGround;

	std::vector<Background*> backgroundLayers;
	std::vector<Background*> groundLayers;
	std::vector<Background*> foregroundLayers;

public:
	Scene();
	Scene(float topOfGround, float bottomOfGround);

	float getTopOfGround();
	float getBottomOfGround();
	std::vector<Background*>& getBackgroundLayers();
	std::vector<Background*>& getGroundLayers();
	std::vector<Background*>& getForegroundLayers();

	void setTopOfGround(float topOfGround);
	void setBottomOfGround(float bottomOfGround);
	void addBackgroundLayer(Background* backgroundLayer);
	void addGroundLayer(Background* ground);
	void addForegroundLayer(Background* foreground);

	void setAllLayersAboveLine(std::vector<Background*>& layers, float y);
	void setAllLayersBelowLine(std::vector<Background*>& layers, float y);

	void draw(Vector2 cameraPos, bool removeVerticalShift = false, int backgroundPadding = 2, Color tintColor = WHITE, Color foregroundColor = WHITE);
	void drawGroundBorders(Vector2 cameraPos, float thick = 5, Color topColor = RED, Color bottomColor = BLUE);

	void deleteLayers(std::vector<Background*>& layers);
	~Scene();
};