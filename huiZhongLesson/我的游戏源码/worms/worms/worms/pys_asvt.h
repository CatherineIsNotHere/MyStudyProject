#pragma once
#include "config.h"
#include "hgesprite.h"

float getVelocity(float v0,float a, float t);//获取速度

float getDistanceY(float velocity, float t);//获取路程y

float getDistanceX(float velocity, float t);//获取路程x

int myIntersect(const hgeRect* other,const hgeRect* rects);

int inRectLR(const hgeRect* other, const hgeRect* rects);

int inRectUD(const hgeRect* other, const hgeRect* rects);