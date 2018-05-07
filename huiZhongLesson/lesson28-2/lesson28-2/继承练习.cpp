#include <stdio.h>

class vehicle{
public:
	char* name;
	int speed;
	char num[12];
	char color[8];

	void startMove(){
		printf("交通工具启动");
	}
};

class car:public vehicle{
public:
	char carNum[12];
	void onTheWay(){
		printf("车在路上");
	}

	void parking(){
		printf("车已停靠在停车场");
	}
};

class sheep :public vehicle{
public:
	void inTheWater(){
		printf("航行中");
	}
	void enterPort(){
		printf("已经进港");
	}
};

class amphicar:public sheep,car{

	char onWitchWay[4];

};