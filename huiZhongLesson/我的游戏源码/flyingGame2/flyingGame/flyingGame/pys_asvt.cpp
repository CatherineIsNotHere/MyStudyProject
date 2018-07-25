#pragma once
#include "pys_asvt.h"

float getVelocity(float v0,float a, float t)
{
	return v0+a*t;
}

float getDistanceY(float velocity, float t)
{
	return velocity*t;
}

float getDistanceX(float velocity, float t)
{
	return velocity*t;
}
