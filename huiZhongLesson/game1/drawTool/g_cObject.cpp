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
void cObject::setNX(int x){
	this->o_nX = x;
}
void cObject::setNY(int y){
	this->o_nY = y;
}
void cObject::setOState(OBJSTATE os){
	this->o_state = os;
}

/*
	构造与析构
*/

cObject::cObject(){

}
cObject::~cObject(){

}