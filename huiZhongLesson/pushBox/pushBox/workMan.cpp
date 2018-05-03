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
	typedef enum w_enDirection
	{
		none,
		up,
		down,
		left,
		right,
	}workManDirection;

public:

	workMan();
	~workMan(){
		delete[] w_pName;
		w_pName = nullptr;
	}


	void Move(int map[][14]){
		
		
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
	int getILocationX(){
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
	void setILocationX(int x){
		this->w_iLocationX = x;
	}
	void setILocationY(int y){
		this->w_iLocationY = y;
	}

};