#pragma once
#include "pys_asvt.h"

float getVelocity(float v0, float a, float t)
{
	return v0 + a*t;
}

float getDistanceY(float velocity, float t)
{
	return velocity*t;
}

float getDistanceX(float velocity, float t)
{
	return velocity*t;
}

int myIntersect(const hgeRect* other, const hgeRect *rects)
{
	for (int i = 0; i < O_NUM; i++){
		if (other->x1 >= rects->x1&&other->x1 <= rects->x2){
			return IM_RIGHT;
		}
		if (other->x2 >= rects->x1&&other->x2 <= rects->x2){
			return IM_LEFT;
		}
		if (other->y1 >= rects->y1&&other->y1 <= rects->y2){
			return IM_DOWN;
		}
		if (other->y2 >= rects->y1&&other->y2 <= rects->y2){
			return IM_UP;
		}
		rects++;
	}
}
