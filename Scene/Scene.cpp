#include "Scene.h"

Scene::Scene() {}
Scene::Scene(float topOfGround, float bottomOfGround) 
	: topOfGround(topOfGround), bottomOfGround(bottomOfGround) {}

float Scene::getTopOfGround() { return topOfGround; }
float Scene::getBottomOfGround() { return bottomOfGround; }
std::vector<Background*>& Scene::getBackgroundLayers() { return backgroundLayers; }
std::vector<Background*>& Scene::getGroundLayers() { return groundLayers; }
std::vector<Background*>& Scene::getForegroundLayers() { return foregroundLayers; }

void Scene::setTopOfGround(float topOfGround) { this->topOfGround = topOfGround; }
void Scene::setBottomOfGround(float bottomOfGround) { this->bottomOfGround = bottomOfGround; }
void Scene::addBackgroundLayer(Background* backgroundLayer) { backgroundLayers.push_back(backgroundLayer); }
void Scene::addGroundLayer(Background* groundLayer) { groundLayers.push_back(groundLayer); }
void Scene::addForegroundLayer(Background* foreground) { foregroundLayers.push_back(foreground); }

void Scene::setAllLayersAboveLine(std::vector<Background*>& layers, float y) { for (auto& layer : layers) layer->setPosAboveLine(y); }
void Scene::setAllLayersBelowLine(std::vector<Background*>& layers, float y) { for (auto& layer : layers) layer->setPosBelowLine(y); }

void Scene::draw(Vector2 cameraPos, bool removeVerticalShift, int backgroundPadding, Color tintColor, Color foregroundColor)
{
	for (auto& backgroundLayer : backgroundLayers) backgroundLayer->draw(cameraPos, removeVerticalShift, backgroundPadding, tintColor);
	for (auto& ground : groundLayers) ground->draw(cameraPos, removeVerticalShift, backgroundPadding, tintColor);
	for (auto& foreground : foregroundLayers) foreground->draw(cameraPos, removeVerticalShift, backgroundPadding, foregroundColor);
}

void Scene::drawGroundBorders(Vector2 cameraPos, float thick, Color topColor, Color bottomColor)
{
	DrawLineEx({ 0, topOfGround - cameraPos.y }, { SCREEN_WIDTH , topOfGround - cameraPos.y }, thick, topColor);
	DrawLineEx({ 0, bottomOfGround - cameraPos.y }, { SCREEN_WIDTH, bottomOfGround - cameraPos.y }, thick, bottomColor);
}

void Scene::deleteLayers(std::vector<Background*>& layers)
{
	for (auto& layer : layers) delete layer;
	layers.clear();
}
Scene::~Scene()
{
	deleteLayers(backgroundLayers);
	deleteLayers(groundLayers);
	deleteLayers(foregroundLayers);
}