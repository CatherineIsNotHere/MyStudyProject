#pragma once
#include "config.h"
#include "hgesprite.h"

float getVelocity(float v0,float a, float t);//��ȡ�ٶ�

float getDistanceY(float velocity, float t);//��ȡ·��y

float getDistanceX(float velocity, float t);//��ȡ·��x

int myIntersect(const hgeRect* other,const hgeRect* rects);

int inRectLR(const hgeRect* other, const hgeRect* rects);

int inRectUD(const hgeRect* other, const hgeRect* rects);