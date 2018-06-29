#include "g_cObject.h"


BOOL cObject::Init(LPTSTR fname, int framew, int frameh, int frames, int x, int y, float sscw,float ssch){
	o_spr.Load(fname);
	o_spr.setSprite(framew, frameh, frames);
	o_spr.setScale(sscw, ssch);
	o_nX = x;
	o_nY = y;
	return true;
}


BOOL cObject::Update()
{
	return true;
}


BOOL cObject::Draw(HDC hdc)
{
	o_spr.Draw(hdc, o_nX, o_nY, RGB(255, 255, 255));
	return true;
}

BOOL cObject::Draw(HDC hdc, COLORREF col)
{
	o_spr.Draw(hdc, o_nX, o_nY, col);
	return true;
}

/*
	get and set
*/
int cObject::getNX(){
	return o_nX;
}
int cObject::getNY(){
	return o_nY;
}
OBJSTATE cObject::getOState(){
	return o_state;
}

CSprite cObject::getSpr()
{
	return o_spr;
}

void cObject::setNX(int x){
	this->o_nX = x;
}
void cObject::setNY(int y){
	this->o_nY = y;
}
void cObject::setOState(OBJSTATE os){
	this->o_state = os;
}

void cObject::setSpr(CSprite spr)
{
	this->o_spr = spr;
}

/*
	构造与析构
*/

cObject::cObject(){

}
cObject::~cObject(){

}