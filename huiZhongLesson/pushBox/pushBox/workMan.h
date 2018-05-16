#pragma once;
#include "allSysInclude.h"
#include "pushBoxEnum.h"
#include "sysTools.h"


class workMan{
private:
	char* w_pName;//��������
	char w_cGender;//�����Ա�
	unsigned int w_iAge;//��������
	unsigned int w_iLocationX;//��������x��λ��
	unsigned int w_iLocationY;//��������Y��λ��
	char w_cAvatar;//����ͷ��
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

