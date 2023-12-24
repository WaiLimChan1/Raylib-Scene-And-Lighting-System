#include "Header.h"

#include "MyCamera.h"
#include "Scene.h"
#include "Effect.h"
#include "FogOfWar.h"

//Global Variables
//--------------------------------------------------------------------
MyCamera camera;
Vector2 verticalBound = { 0 - 500, SCREEN_HEIGHT + 500};
//--------------------------------------------------------------------

std::vector<Scene*> scenes;
int sceneIndex;

std::vector<Effect*> effects;
std::vector<LightSource*> lightSources;
FogOfWar* fogOfWar;
bool showFogOfWar;


void SetUpDarkForest()
{
	Scene* scene = new Scene();
	Vector2 pos = { 0,0 };
	float scale = 1.8;

	scene->setTopOfGround(SCREEN_HEIGHT - 115);
	scene->setBottomOfGround(SCREEN_HEIGHT);

	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Dark Forest/Layer_0.png"), pos, { 0,0 }, 2.4, scale));
	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Dark Forest/Layer_1.png"), pos, { 0,0 }, 2.2, scale));
	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Dark Forest/Layer_2.png"), pos, { 0,0 }, 2.0, scale));
	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Dark Forest/Layer_3.png"), pos, { 0,0 }, 1.8, scale));
	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Dark Forest/Layer_4.png"), pos, { 0,0 }, 1.6, scale));
	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Dark Forest/Layer_4_Lights.png"), pos, { 0,0 }, 1.6, scale));
	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Dark Forest/Layer_5.png"), pos, { 0,0 }, 1.4, scale));
	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Dark Forest/Layer_6.png"), pos, { 0,0 }, 1.2, scale));
	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Dark Forest/Layer_7.png"), pos, { 0,0 }, 1, scale));
	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Dark Forest/Layer_7_Lights.png"), pos, { 0,0 }, 1, scale));

	scene->addGroundLayer(new Background(LoadTexture("textures/Backgrounds/Dark Forest/Layer_8.png"), pos, { 0,0 }, 1, scale));
	scene->addGroundLayer(new Background(LoadTexture("textures/Backgrounds/Dark Forest/Layer_9.png"), pos, { 0,0 }, 1, scale));

	scene->setAllLayersAboveLine(scene->getBackgroundLayers(), scene->getBottomOfGround());
	scene->setAllLayersAboveLine(scene->getGroundLayers(), scene->getBottomOfGround());

	scenes.push_back(scene);
}
void SetUpSunnyHill()
{
	Scene* scene = new Scene();
	Vector2 pos = { 0,0 };
	float scale = 4;

	scene->setTopOfGround(SCREEN_HEIGHT - 65);
	scene->setBottomOfGround(SCREEN_HEIGHT);

	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Sunny Hill/Hills Layer 01.png"), pos, { 0,0 }, 1.8, scale));
	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Sunny Hill/Hills Layer 02.png"), pos, { 0,0 }, 1.6, scale));
	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Sunny Hill/Hills Layer 03.png"), pos, { 0,0 }, 1.4, scale));
	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Sunny Hill/Hills Layer 04.png"), pos, { 0,0 }, 1.2, scale));

	scene->addGroundLayer(new Background(LoadTexture("textures/Backgrounds/Sunny Hill/Hills Layer 05.png"), pos, { 0,0 }, 1, scale));

	scene->addForegroundLayer(new Background(LoadTexture("textures/Backgrounds/Sunny Hill/Hills Layer 06.png"), pos, { 0,0 }, 0.8, scale));

	scene->setAllLayersAboveLine(scene->getBackgroundLayers(), scene->getBottomOfGround());
	scene->setAllLayersAboveLine(scene->getGroundLayers(), scene->getBottomOfGround());
	scene->setAllLayersAboveLine(scene->getForegroundLayers(), scene->getBottomOfGround());

	scenes.push_back(scene);
}
void SetUpCave()
{
	Scene* scene = new Scene();
	Vector2 pos = { 0,0 };
	float scale = 5;

	scene->setTopOfGround(SCREEN_HEIGHT);
	scene->setBottomOfGround(SCREEN_HEIGHT);

	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Cave/7.png"), pos, { 0,0 }, 5, scale));
	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Cave/6.png"), pos, { 0,0 }, 4, scale));
	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Cave/5.png"), pos, { 0,0 }, 3, scale));
	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Cave/4.png"), pos, { 0,0 }, 2, scale));
	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Cave/3.png"), pos, { 0,0 }, 1, scale));

	scene->addForegroundLayer(new Background(LoadTexture("textures/Backgrounds/Cave/2.png"), pos, { 0,0 }, 0.8, scale));
	scene->addForegroundLayer(new Background(LoadTexture("textures/Backgrounds/Cave/1.png"), pos, { 0,0 }, 0.6, scale));

	scene->setAllLayersAboveLine(scene->getBackgroundLayers(), scene->getBottomOfGround());
	scene->setAllLayersAboveLine(scene->getGroundLayers(), scene->getBottomOfGround());
	scene->setAllLayersAboveLine(scene->getForegroundLayers(), scene->getBottomOfGround());

	scenes.push_back(scene);
}
void SetUpPlains()
{
	Scene* scene = new Scene();
	Vector2 pos = { 0,0 };
	float scale = 5;

	scene->setTopOfGround(SCREEN_HEIGHT);
	scene->setBottomOfGround(SCREEN_HEIGHT);

	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Plains/8.png"), pos, { 0,0 }, 11, scale));
	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Plains/7.png"), pos, { 0,0 }, 9, scale));
	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Plains/6.png"), pos, { 0,0 }, 7, scale));
	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Plains/5.png"), pos, { 0,0 }, 5, scale));
	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Plains/4.png"), pos, { 0,0 }, 3, scale));
	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Plains/3.png"), pos, { 0,0 }, 2, scale));

	scene->addGroundLayer(new Background(LoadTexture("textures/Backgrounds/Plains/2.png"), pos, { 0,0 }, 1, scale));

	scene->addForegroundLayer(new Background(LoadTexture("textures/Backgrounds/Plains/1.png"), pos, { 0,0 }, 0.6, scale));

	scene->setAllLayersAboveLine(scene->getBackgroundLayers(), scene->getBottomOfGround());
	scene->setAllLayersAboveLine(scene->getGroundLayers(), scene->getBottomOfGround());
	scene->setAllLayersAboveLine(scene->getForegroundLayers(), scene->getBottomOfGround());

	scenes.push_back(scene);
}
void SetUpSnowyMountains()
{
	Scene* scene = new Scene();
	Vector2 pos = { 0,0 };
	float scale = 5;

	scene->setTopOfGround(SCREEN_HEIGHT);
	scene->setBottomOfGround(SCREEN_HEIGHT);

	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Snowy Mountains/5.png"), pos, { 0,0 }, 5, scale));
	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Snowy Mountains/4.png"), pos, { 0,0 }, 4, scale));
	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Snowy Mountains/3.png"), pos, { 0,0 }, 3, scale));
	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Snowy Mountains/2.png"), pos, { 0,0 }, 2, scale));

	scene->addGroundLayer(new Background(LoadTexture("textures/Backgrounds/Snowy Mountains/1.png"), pos, { 0,0 }, 1, scale));

	scene->setAllLayersAboveLine(scene->getBackgroundLayers(), scene->getBottomOfGround());
	scene->setAllLayersAboveLine(scene->getGroundLayers(), scene->getBottomOfGround());

	scenes.push_back(scene);
}
void SetUpDeadForest()
{
	Scene* scene = new Scene();
	Vector2 pos = { 0,0 };
	float scale = 5;

	scene->setTopOfGround(SCREEN_HEIGHT - 340);
	scene->setBottomOfGround(SCREEN_HEIGHT);

	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Dead Forest/6.png"), pos, { 0,0 }, 5, scale));
	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Dead Forest/5.png"), pos, { 0,0 }, 4, scale));
	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Dead Forest/4.png"), pos, { 0,0 }, 3, scale));
	scene->addBackgroundLayer(new Background(LoadTexture("textures/Backgrounds/Dead Forest/3.png"), pos, { 0,0 }, 2, scale));

	scene->addGroundLayer(new Background(LoadTexture("textures/Backgrounds/Dead Forest/2.png"), pos, { 0,0 }, 1, scale));

	scene->addForegroundLayer(new Background(LoadTexture("textures/Backgrounds/Dead Forest/1.png"), pos, { 0,0 }, 0.7, scale));

	scene->setAllLayersAboveLine(scene->getBackgroundLayers(), scene->getBottomOfGround());
	scene->setAllLayersAboveLine(scene->getGroundLayers(), scene->getBottomOfGround());
	scene->setAllLayersAboveLine(scene->getForegroundLayers(), scene->getBottomOfGround());

	scenes.push_back(scene);
}

void SetUp()
{
	camera = MyCamera({ 0,0 }, 800, false);

	SetUpDarkForest();
	SetUpSunnyHill();
	SetUpCave();
	SetUpPlains();
	SetUpSnowyMountains();
	SetUpDeadForest();
	sceneIndex = 0;

	Effect::LoadAnimations();
	fogOfWar = new FogOfWar();
	showFogOfWar = true;
}

void PrintMousePos()
{
	Vector2 pos = { 10, 10 };
	int fontSize = 30;
	char message[100];

	strcpy_s(message, "Mouse World Pos: ");
	strcat_s(message, std::to_string((int)(GetMousePosition().x + camera.getPos().x)).c_str());
	strcat_s(message, ", ");
	strcat_s(message, std::to_string((int)(GetMousePosition().y + camera.getPos().y)).c_str());
	DrawText(message, pos.x, pos.y, fontSize, YELLOW);
	pos.y += fontSize;

	strcpy_s(message, "Mouse Screen Pos: ");
	strcat_s(message, std::to_string((int)GetMousePosition().x).c_str());
	strcat_s(message, ", ");
	strcat_s(message, std::to_string((int)GetMousePosition().y).c_str());
	DrawText(message, pos.x, pos.y, fontSize, YELLOW);
	pos.y += fontSize;
}

void Draw()
{
	BeginDrawing();

	ClearBackground(BLACK);

	if (sceneIndex >= 0 && sceneIndex < scenes.size())
	{
		scenes.at(sceneIndex)->draw(camera.getPos(), true, 2);
		//scenes.at(sceneIndex)->drawGroundBorders(camera.getPos());
	}
	for (auto& effect : effects) effect->draw(camera.getPos());
	if (showFogOfWar) fogOfWar->draw();
	PrintMousePos();

	EndDrawing();
}

void TakeInputForSwappingBetweenScenes()
{
	if (IsMouseButtonPressed(1))
	{
		sceneIndex++;
		if (sceneIndex >= scenes.size())
		{
			if (scenes.size() > 0) sceneIndex = 0;
			else sceneIndex = -1;
		}
	}
}
void TakeInputForSpawingEffects()
{
	Vector2 pos = Vector2Add(GetMousePosition(), camera.getPos());
	bool facingLeft = false;
	float scale = 3;
	if (IsKeyPressed(KEY_ONE)) effects.push_back(new Effect(Effect::BLUE_BALL_EFFECT, pos, facingLeft, scale));
	if (IsKeyPressed(KEY_TWO)) effects.push_back(new Effect(Effect::RED_ORANGE_PURPLE_SQUARES_EFFECT, pos, facingLeft, scale));
	if (IsKeyPressed(KEY_THREE)) effects.push_back(new Effect(Effect::BLUE_CROSS_EFFECT, pos, facingLeft, scale));
}
void Input()
{
	TakeInputForSwappingBetweenScenes();
	TakeInputForSpawingEffects();
	if (IsMouseButtonPressed(0)) showFogOfWar = !showFogOfWar;
	camera.takeInput();
}

void Logic()
{
	//Effect Logic
	for (int i = 0; i < effects.size(); i++)
	{
		if (effects.at(i)->finishedAnimation())
		{
			delete effects.at(i);
			effects.erase(effects.begin() + i);
			i--;
		}
	}
	for (auto& effect : effects)
	{
		if (effect->getLightSource() != nullptr)
			lightSources.push_back(effect->getLightSource());
	}

	//Light source logic
	for (auto& lightSource : lightSources) lightSource->influenceByMode();

	//Fog of war logic
	fogOfWar->resetShadow();
	fogOfWar->handleLightSourceInfluence(camera.getPos(), lightSources);
	fogOfWar->checkAlphaBound();

	lightSources.clear();

	//camera.checkTopDownBound(verticalBound);
}

void ReleaseResources()
{
	//Release scenes resources
	for (auto& scene : scenes) delete scene;
	scenes.clear();

	//Release Effect resources
	for (auto& effect : effects) delete effect;
	effects.clear();
	Effect::UnloadAnimations();

	//Release LightSource resources

	delete fogOfWar;
}

int main()
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Scene");
	SetWindowState(FLAG_VSYNC_HINT);
	srand(time(0));

	SetUp();
	while (!WindowShouldClose())
	{
		Draw();
		Input();
		Logic();
	}
	ReleaseResources();
	return 0;
}