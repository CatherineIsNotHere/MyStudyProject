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
//右碰撞
//x1<=xx2 x2>=xx2 &&((y1<=yy1 && y2>=yy1)||(y1<=yy2 && y2>=yy2))
//左碰撞
//x1<=xx1 x2>=xx1 &&((y1<=yy1 && y2>=yy1)||(y1<=yy2 && y2>=yy2))
//下碰撞
//y1<=yy2 y2>=yy2 &&((x1<=xx2 x2>=xx2)||(x1<=xx1 x2>=xx1))
//上碰撞
//y1<=yy1 && y2>=yy1 && ((x1<=xx2 x2>=xx2)||(x1<=xx1 x2>=xx1))
int myIntersect(const hgeRect* other, const hgeRect *rects)
{
	float x1 = rects->x1;
	float x2 = rects->x2;
	float y1 = rects->y1 + 10.0f;
	float y2 = rects->y2 - 10.0f;
	float xx1 = other->x1;
	float xx2 = other->x2;
	float yy1 = other->y1;
	float yy2 = other->y2;
	if (x1  <= xx2&&x2  >= xx2 && ((y1 <= yy1&&y2 >= yy1) || (y1 <= yy2&&y2 >= yy2))){
		return IM_RIGHT;
	}else if (x1 <= xx1&&x2 >= xx1 && ((y1 <= yy1&&y2 >= yy1) || (y1 <= yy2&&y2 >= yy2))){
		return IM_LEFT;
	}else if (y1 - 10.0f <= yy2&&y2 + 10.0f >= yy2 && ((x1 <= xx2&&x2 >= xx2) || (x1 <= xx1&&x2 >= xx1))){
		return IM_DOWN;
	}else if (y1 - 10.0f <= yy1&&y2 + 10.0f >= yy1 && ((x1 <= xx2&&x2 >= xx2) || (x1 <= xx1&&x2 >= xx1))){
		return IM_UP;
	}
	return IM_NONE;
}
///*
//查看是否在障碍物内
//*/
//int inRectLR(const hgeRect* other, const hgeRect* rects)
//{
//	float x1 = rects->x1;
//	float x2 = rects->x2;
//	float xx1 = other->x1;
//	float xx2 = other->x2;
//	if (xx2 > x1&&xx2<x2){//右边嵌入
//		return IN_RIGHT + (xx2 - x1);
//	}
//	if (xx1>x1&&xx1 < x2){//左边嵌入
//		return IN_LEFT + (x2 - xx1);
//	}
//	return IN_NONE;
//}
//
//int inRectUD(const hgeRect* other, const hgeRect* rects)
//{
//	float y1 = rects->y1;
//	float y2 = rects->y2;
//	float yy1 = other->y1;
//	float yy2 = other->y2;
//	if (yy2 > y1&&yy2<y2){
//		return IN_DOWN + (yy2 - y1)*1000;//下边嵌入
//	}
//	if (yy1>y1&&yy1 < y2){
//		return IN_UP + (y2 - yy1)*1000;//上边嵌入
//	}
//}
//
