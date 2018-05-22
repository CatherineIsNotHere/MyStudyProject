#include "workMan.h"



workMan::workMan(){

};

workMan::workMan(int w_iLocationX, int w_iLocationY)
:w_iLocationX(w_iLocationX)
, w_iLocationY(w_iLocationY)
{
};

workMan::~workMan(){
	/*delete w_pName;
	w_pName = nullptr;*/
}

char* workMan::getPName(){
	return w_pName;
}
char workMan::getCGender(){
	return w_cGender;
}
int workMan::getIAge(){
	return w_iAge;
}
int workMan::getILocationX(){
	return w_iLocationX;
}
int workMan::getILocationY(){
	return w_iLocationY;
}
char workMan::getCAvatar(){
	return w_cAvatar;
}
void workMan::setPname(char* pName){
	this->w_pName = pName;
}
void workMan::setCGender(char cGender){
	this->w_cGender = cGender;
}
void workMan::setIAge(int iAge){
	this->w_iAge = iAge;
}
void workMan::setCAvatar(char avatar){
	this->w_cAvatar = avatar;
}
void workMan::setILocationX(int x){
	this->w_iLocationX = x;
}
void workMan::setILocationY(int y){
	this->w_iLocationY = y;
}


void workMan::Move(Direction drc, int map[][14]){
	map[this->w_iLocationY][this->w_iLocationX] -= player;
	gotoxy(2 * this->w_iLocationX, this->w_iLocationY);
	if (map[this->w_iLocationY][this->w_iLocationX] == destination){
		printf("��");
	}
	else{
		printf("  ");
	}
	switch (drc)
	{
	case dirUp:
		this->w_iLocationY -= 1;
		break;
	case dirDown:
		this->w_iLocationY += 1;
		break;
	case dirLeft:
		this->w_iLocationX -= 1;
		break;
	case dirRight:
		this->w_iLocationX += 1;
		break;
	default:
		break;
	}
	map[w_iLocationY][w_iLocationX] += player;
	gotoxy(2 * (w_iLocationX), w_iLocationY);
	printf("��");

}