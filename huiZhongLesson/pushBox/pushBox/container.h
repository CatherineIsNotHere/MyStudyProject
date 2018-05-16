#pragma once
#include "allSysInclude.h"
#include "pushBoxEnum.h"
#include "sysTools.h"

class container{
private:
	unsigned int c_iContainerNum;//箱号
	char* c_cKind;//箱子类型
	float c_fWeight;//箱子重量
	unsigned int c_iLocationX;//坐标X
	unsigned int c_iLocationY;//坐标Y
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