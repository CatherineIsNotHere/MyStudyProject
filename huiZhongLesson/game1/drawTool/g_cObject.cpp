#include "g_cObject.h"

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
	����������
*/

cObject::cObject(){

}
cObject::~cObject(){

}