#pragma once;
#include "allSysInclude.h"
#include "pushBoxEnum.h"
#include "sysTools.h"


class workMan{
private:
	char* w_pName;//工人姓名
	char w_cGender;//工人性别
	unsigned int w_iAge;//工人年龄
	unsigned int w_iLocationX;//工人所在x轴位置
	unsigned int w_iLocationY;//工人所在Y轴位置
	char w_cAvatar;//工人头像
public:
	workMan();
	workMan(int w_iLocationX, int w_iLocationY);
	~workMan();
	char* getPName();
	char getCGender();
	int getIAge();
	int getILocationX();
	int getILocationY();
	char getCAvatar();
	void setPname(char* pName);
	void setCGender(char cGender);
	void setIAge(int iAge);
	void setILocationY(char avatar);
	void setILocationX(int x);
	void setILocationY(int y);
	void Move(Direction drc, int map[][14]);
};

