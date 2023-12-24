#pragma once
#include "Header.h"

class LightSource
{
public:
	static enum LightSourceMode {NONE, FADE_OUT, RANGE_SHIFT, INTENSITY_SHIFT, RANGE_AND_INTENSITY_SHIFT, FLICKER};

private:
	float originalRange;
	float originalIntensity;

	Vector2 pos;
	float range;
	float intensity;
	Color color; 

	LightSourceMode mode;
	float modeValue;
	Vector2 rangeShiftBound; //{min, max}
	Vector2 intensityShiftBound; //{min, max}

public:
	LightSource();
	LightSource(Vector2 pos, float range, float intensity, Color color = WHITE, LightSourceMode mode = NONE, float modeValue = 50, Vector2 rangeShiftBound = {0, 300}, Vector2 intensityShiftBound = {0, 255});

	Vector2 getPos();
	float getOriginalRange();
	float getOriginalIntensity();
	float getRange();
	float getIntensity();
	Color getColor();

	void setRange(float range);
	void setOriginalRange(float originalRange);
	void setOriginalIntensity(float originalIntensity);
	void setIntensity(float intensity);
	void setPos(Vector2 pos);
	void setColor(Color color);

	void draw(Vector2 cameraPos, float radius = 10, Color color = WHITE);

	void checkBound(float& value, Vector2 bound);
	void influenceByMode();
};