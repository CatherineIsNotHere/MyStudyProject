#pragma once

class container{
private:
	int c_iContainerNum;
	char* c_cKind;
	float c_fWeight;
	int c_iLocationX;
	int c_iLocationY;
public:
	container();
	container(int x, int y);
	~container();
	void setIContainerNum(int num);
	void setCKind(char k[20]);
	void setFWeight(float w);
	void setILocationX(int x);
	void setIlocationY(int y);
	int getIContainerNum();
	char* getCKind();
	float getFWeight();
	int getILocationX();
	int getILocationY();

};