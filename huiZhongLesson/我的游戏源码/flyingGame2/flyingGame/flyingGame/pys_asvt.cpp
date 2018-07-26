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
//ÓÒÅö×²
//x1<=xx2 x2>=xx2 &&((y1<=yy1 && y2>=yy1)||(y1<=yy2 && y2>=yy2))
//×óÅö×²
//x1<=xx1 x2>=xx1 &&((y1<=yy1 && y2>=yy1)||(y1<=yy2 && y2>=yy2))
//ÏÂÅö×²
//y1<=yy2 y2>=yy2 &&((x1<=xx2 x2>=xx2)||(x1<=xx1 x2>=xx1))
//ÉÏÅö×²
//y1<=yy1 && y2>=yy1 && ((x1<=xx2 x2>=xx2)||(x1<=xx1 x2>=xx1))
int myIntersect(const hgeRect* other, const hgeRect *rects)
{
	float x1 = rects->x1 + 10.0f;
	float x2 = rects->x2 - 10.0f;
	float y1 = rects->y1 + 10.0f;
	float y2 = rects->y2 - 10.0f;
	float xx1 = other->x1;
	float xx2 = other->x2;
	float yy1 = other->y1;
	float yy2 = other->y2;
	if (x1 - 10.0f <= xx2&&x2 + 10.0f >= xx2 && ((y1 <= yy1&&y2 >= yy1) || (y1 <= yy2&&y2 >= yy2))){
		return IM_RIGHT;
	}
	if (x1 - 10.0f <= xx1&&x2 + 10.0f >= xx1 && ((y1 <= yy1&&y2 >= yy1) || (y1 <= yy2&&y2 >= yy2))){
		return IM_LEFT;
	}
	if (y1 - 10.0f <= yy2&&y2 + 10.0f >= yy2 && ((x1 <= xx2&&x2 >= xx2) || (x1 <= xx1&&x2 >= xx1))){
		return IM_DOWN;
	}
	if (y1 - 10.0f <= yy1&&y2 + 10.0f >= yy1 && ((x1 <= xx2&&x2 >= xx2) || (x1 <= xx1&&x2 >= xx1))){
		return IM_UP;
	}
	return IM_NONE;
}
/*
²é¿´ÊÇ·ñÔÚÕÏ°­ÎïÄÚ
*/
int inRectLR(const hgeRect* other, const hgeRect* rects)
{
	float x1 = rects->x1;
	float x2 = rects->x2;
	float xx1 = other->x1;
	float xx2 = other->x2;
	if (xx2 > x1&&xx2<x2){//ÓÒ±ßÇ¶Èë
		return IN_RIGHT + (xx2 - x1);
	}
	if (xx1>x1&&xx1 < x2){//×ó±ßÇ¶Èë
		return IN_LEFT + (x2 - xx1);
	}
	return IN_NONE;
}

int inRectUD(const hgeRect* other, const hgeRect* rects)
{
	float y1 = rects->y1;
	float y2 = rects->y2;
	float yy1 = other->y1;
	float yy2 = other->y2;
	if (yy2 > y1&&yy2<y2){
		return IN_DOWN + (yy2 - y1);
	}
	if (yy1>y1&&yy1 < y2){
		return IN_UP + (y2 - yy1)*100;
	}
}

