#include "LightSource.h"

LightSource::LightSource() {}
LightSource::LightSource(Vector2 pos, float originalRange, float originalIntensity, Color color, LightSourceMode mode, float modeValue, Vector2 rangeShiftBound, Vector2 intensityShiftBound)
	: pos(pos), color(color), mode(mode), modeValue(modeValue), rangeShiftBound(rangeShiftBound), intensityShiftBound(intensityShiftBound)
{ 
	setOriginalRange(originalRange);
	this->range = this->originalRange;
	setOriginalIntensity(originalIntensity);
	this->intensity = this->originalIntensity;

	if (rangeShiftBound.x < 0) rangeShiftBound.x = 0;
	if (intensityShiftBound.x < 0) intensityShiftBound.x = 0;
}

Vector2 LightSource::getPos() { return pos; }
float LightSource::getOriginalRange() { return originalRange; }
float LightSource::getOriginalIntensity() { return originalIntensity; }
float LightSource::getRange() { return range; }
float LightSource::getIntensity() { return intensity; }
Color LightSource::getColor() { return color; }

void LightSource::setPos(Vector2 pos) { this->pos = pos; }
void LightSource::setOriginalRange(float originalRange) 
{ 
	this->originalRange = originalRange; 
	if (this->originalIntensity < 0) this->originalIntensity = 0;
}
void LightSource::setOriginalIntensity(float originalIntensity)
{
	this->originalIntensity = originalIntensity;
	if (this->originalIntensity < 0) this->originalIntensity = 0;
}
void LightSource::setRange(float range) 
{ 
	this->range = range; 
	if (this->range < 0) this->range = 0;
}
void LightSource::setIntensity(float intensity) 
{ 
	this->intensity = intensity; 
	if (this->intensity < 0) this->intensity = 0;
}
void LightSource::setColor(Color color) { this->color = color; }

void LightSource::draw(Vector2 cameraPos, float radius, Color color) { DrawCircle(pos.x - cameraPos.x, pos.y - cameraPos.y, radius, color); }

void LightSource::checkBound(float& value, Vector2 bound)
{
	if (value < bound.x) value = bound.x;
	if (value > bound.y) value = bound.y;
}
void LightSource::influenceByMode()
{
	float dt = GetFrameTime();

	switch (mode)
	{

	case NONE: //Light source parameters stay constant.
		break;

	case FADE_OUT: //Both range and intensity shift toward zero. At the speed of modeValue.
		setRange(range - abs(modeValue) * dt);
		setIntensity(intensity - abs(modeValue) * dt);
		break;

	case RANGE_SHIFT: //Range shifts back and forth between zero and original range. At the speed of modeValue.
		if (range >= rangeShiftBound.y) modeValue = abs(modeValue) * -1;
		else if (range <= rangeShiftBound.x) modeValue = abs(modeValue);
		setRange(range + modeValue * dt);
		checkBound(range, rangeShiftBound);
		break;

	case INTENSITY_SHIFT: //Intensity shifts back and forth between zero and original intensity. At the speed of modeValue.
		if (intensity >= intensityShiftBound.y) modeValue = abs(modeValue) * -1;
		else if (intensity <= intensityShiftBound.x) modeValue = abs(modeValue);
		setIntensity(intensity + modeValue * dt);
		checkBound(intensity, intensityShiftBound);
		break;

	case RANGE_AND_INTENSITY_SHIFT: //Both RANGE_SHIFT and INTENSITY_SHIFT. They will wait for each other before shifting towards the opposite direction.
		if (range >= rangeShiftBound.y && intensity >= intensityShiftBound.y) modeValue = abs(modeValue) * -1;
		else if (range <= rangeShiftBound.x && intensity <= intensityShiftBound.x) modeValue = abs(modeValue);
		setRange(range + modeValue * dt);
		setIntensity(intensity + modeValue * dt);
		checkBound(range, rangeShiftBound);
		checkBound(intensity, intensityShiftBound);
		break;

	case FLICKER: //Range flickers randomly between {original range - modeValue / 2, original range + modeValue / 2}
		if (modeValue != 0)
			setRange(originalRange + (rand() % (int)abs(modeValue)) - ((int)abs(modeValue) / 2));
		break;
	}
}