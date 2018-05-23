#include "container.h"

container::container(){
	
}

container::container(int x, int y){
	this->c_iLocationX = x;
	this->c_iLocationY = y;
}
container::~container(){

}
void container::setIContainerNum(int num){
	this->c_iContainerNum = num;
}
void container::setCKind(char* k){
	this->c_cKind = k;
}
void container::setFWeight(float w){
	this->c_fWeight = w;
}
void container::setILocationX(int x){
	this->c_iLocationX = x;
}
void container::setIlocationY(int y){
	this->c_iLocationY = y;
}
int container::getIContainerNum(){
	return c_iContainerNum;
}
char* container::getCKind(){
	return c_cKind;
}
float container::getFWeight(){
	return c_fWeight;
}
int container::getILocationX(){
	return c_iLocationX;
}
int container::getILocationY(){
	return c_iLocationY;
}
void container::Move(Direction drc, int map[][16]){
	map[this->c_iLocationY][this->c_iLocationX] -= box;
	gotoxy(2 * this->c_iLocationX, this->c_iLocationY);
	if (map[this->c_iLocationY][this->c_iLocationX] == destination){
		printf("¡î");
	}
	else if (map[this->c_iLocationY][this->c_iLocationX] == space){
		printf("  ");
	}
	switch (drc)
	{
	case dirUp:
		this->c_iLocationY -= 1;
		break;
	case dirDown:
		this->c_iLocationY += 1;
		break;
	case dirLeft:
		this->c_iLocationX -= 1;
		break;
	case dirRight:
		this->c_iLocationX += 1;
		break;
	default:
		break;
	}
	map[this->c_iLocationY][this->c_iLocationX] += box;
	gotoxy(2 * c_iLocationX, c_iLocationY);
	if (map[c_iLocationY][c_iLocationX] == destination + box) {
		printf("¡ï");
	}
	else {
		printf("¡õ");
	}
	
}

