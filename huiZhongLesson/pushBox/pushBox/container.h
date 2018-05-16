#pragma once
#include "allSysInclude.h"
#include "pushBoxEnum.h"
#include "sysTools.h"

class container{
private:
	unsigned int c_iContainerNum;//���
	char* c_cKind;//��������
	float c_fWeight;//��������
	unsigned int c_iLocationX;//����X
	unsigned int c_iLocationY;//����Y
public:
	container();
	container(int x, int y);
	~container();
	void setIContainerNum(int num);
	void setCKind(char* k);
	void setFWeight(float w);
	void setILocationX(int x);
	void setIlocationY(int y);
	int getIContainerNum();
	char* getCKind();
	float getFWeight();
	int getILocationX();
	int getILocationY();
	void Move(Direction drc, int map[][14]);
};