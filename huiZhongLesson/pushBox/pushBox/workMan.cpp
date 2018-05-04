#include <stdio.h>
#include "workMan.h"

class workMan{
private:
	char* w_pName;
	char w_cGender;
	int w_iAge;
	int w_iLocationX;
	int w_iLocationY;
	char w_cAvatar;


public:

	workMan();
	~workMan(){
		delete[] w_pName;
		w_pName = nullptr;
	}


	void Move(workManDirection drc,int map[][14],workMan& workman){
		switch (drc)
		{
		case up:

			break;
		case down:
			
			break;
		case left:
			
			break;
		case right:
			
			break;
		default:
			break;
		}
		
	}

	char* getPName(){
		return w_pName;
	}
	char getCGender(){
		return w_cGender;
	}
	int getIAge(){
		return w_iAge;
	}
	int getILocationX(){
		return w_iLocationX;
	}
	int getILocationY(){
		return w_iLocationY;
	}
	char getCAvatar(){
		return w_cAvatar;
	}
	void setPname(char* pName){
		this->w_pName = pName;
	}
	void setCGender(char cGender){
		this->w_cGender = cGender;
	}
	void setIAge(int iAge){
		this->w_iAge = iAge;
	}
	void setILocationY(char avatar){
		this->w_cAvatar = avatar;
	}
	void setILocationX(int x){
		this->w_iLocationX = x;
	}
	void setILocationY(int y){
		this->w_iLocationY = y;
	}

};