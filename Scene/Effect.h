#pragma once
#include "Header.h"
#include "AnimationPro.h"
#include "LightSource.h"

class Effect
{
public:
	static enum SpecialEffectEnum { BLUE_BALL_EFFECT, RED_ORANGE_PURPLE_SQUARES_EFFECT, BLUE_CROSS_EFFECT};

private:
	static AnimationPro StaticBlueBallEffectAnimation;
	static AnimationPro StaticRedOrangePurpleSquaresEffectAnimation;
	static AnimationPro StaticBlueCrossEffectAnimation;

private:
	AnimationPro animation;
	LightSource* lightSource;
	Vector2 pos;
	bool facingLeft;
	float scale;

public:
	static void LoadAnimations();
	static void UnloadAnimations();

	Effect();
	Effect(SpecialEffectEnum specialEffect, Vector2 centerPos, bool facingLeft, float scale);
	void setAnimationAndLightSource(SpecialEffectEnum specialEffect);

	LightSource* getLightSource();
	Vector2 getPos();
	Vector2 getHitBoxCenterPos();
	bool getFacingLeft();
	float getScale();
	float getWidth();
	float getHeight();

	void setPos(Vector2 pos);
	void setHitBoxCenterPos(Vector2 pos);

	Rectangle getHitBox(Vector2 cameraPos);
	void drawHitBox(Vector2 cameraPos, Color color = { 230, 41, 55, 150 });

	void draw(Vector2 cameraPos, Color colorTint = WHITE);

	bool finishedAnimation();

	~Effect();
};