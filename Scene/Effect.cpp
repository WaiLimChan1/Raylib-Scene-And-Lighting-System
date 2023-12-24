#include "Effect.h"

AnimationPro Effect::StaticBlueBallEffectAnimation;
AnimationPro Effect::StaticRedOrangePurpleSquaresEffectAnimation;
AnimationPro Effect::StaticBlueCrossEffectAnimation;

void Effect::LoadAnimations()
{
	StaticBlueBallEffectAnimation = AnimationPro(LoadTexture("textures/Effects/Blue Ball.png"), 1, 1.0f / 48.0f, 17);
	StaticRedOrangePurpleSquaresEffectAnimation = AnimationPro(LoadTexture("textures/Effects/Red Orange Purple Squares.png"), 1, 1.0f / 48.0f, 15);
	StaticBlueCrossEffectAnimation = AnimationPro(LoadTexture("textures/Effects/Blue Cross.png"), 1, 1.0f / 48.0f, 18);
}
void Effect::UnloadAnimations()
{
	StaticBlueBallEffectAnimation.unloadTexture();
	StaticRedOrangePurpleSquaresEffectAnimation.unloadTexture();
	StaticBlueCrossEffectAnimation.unloadTexture();
}

Effect::Effect() {}
Effect::Effect(SpecialEffectEnum specialEffect, Vector2 centerPos, bool facingLeft, float scale)
	: lightSource(nullptr), facingLeft(facingLeft), scale(scale)
{
	setAnimationAndLightSource(specialEffect);
	setHitBoxCenterPos(centerPos);
	if (lightSource != nullptr) lightSource->setPos(centerPos);
}
void Effect::setAnimationAndLightSource(SpecialEffectEnum specialEffect)
{
	if (specialEffect == BLUE_BALL_EFFECT)
	{
		animation = StaticBlueBallEffectAnimation;
		lightSource = new LightSource(pos, scale * 100, 200, BLUE, LightSource::FADE_OUT, scale * 100);
	}
	else if (specialEffect == RED_ORANGE_PURPLE_SQUARES_EFFECT)
	{
		animation = StaticRedOrangePurpleSquaresEffectAnimation;
		lightSource = new LightSource(pos, scale * 100, 200, PURPLE, LightSource::FADE_OUT, scale * 100);
	}
	else if (specialEffect == BLUE_CROSS_EFFECT)
	{
		animation = StaticBlueCrossEffectAnimation;
		lightSource = new LightSource(pos, scale * 100, 200, BLUE, LightSource::FADE_OUT, scale * 100);
	}
	animation.reScale(scale);
}

LightSource* Effect::getLightSource() { return lightSource; }
Vector2 Effect::getPos() { return pos; }
Vector2 Effect::getHitBoxCenterPos()
{
	Rectangle hitBox = getHitBox({ 0,0 });
	return { hitBox.x + hitBox.width / 2, hitBox.y + hitBox.height / 2 };
}
bool Effect::getFacingLeft() { return facingLeft; }
float Effect::getScale() { return scale; }
float Effect::getWidth() { return animation.getWidth(); }
float Effect::getHeight() { return animation.getHeight(); }

void Effect::setPos(Vector2 pos) { this->pos = pos; }
void Effect::setHitBoxCenterPos(Vector2 pos)
{
	Vector2 changeVector = Vector2Subtract(pos, getHitBoxCenterPos());
	this->pos = Vector2Add(this->pos, changeVector);
}

Rectangle Effect::getHitBox(Vector2 cameraPos) { return Rectangle{ pos.x - cameraPos.x, pos.y - cameraPos.y, animation.getWidth(), animation.getHeight() }; }
void Effect::drawHitBox(Vector2 cameraPos, Color color) { DrawRectangleRec(getHitBox(cameraPos), color); }

void Effect::draw(Vector2 cameraPos, Color colorTint)
{
	animation.draw({ pos.x - cameraPos.x, pos.y - cameraPos.y }, facingLeft, colorTint);
	animation.updateFrame();
}

bool Effect::finishedAnimation() { return animation.finishedAnimation(); }

Effect::~Effect() { if (lightSource != nullptr) delete lightSource; }