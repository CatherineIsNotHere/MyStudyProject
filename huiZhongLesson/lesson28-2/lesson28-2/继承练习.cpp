#include <stdio.h>

class vehicle{
public:
	char* name;
	int speed;
	char num[12];
	char color[8];

	void startMove(){
		printf("��ͨ��������");
	}
};

class car:public vehicle{
public:
	char carNum[12];
	void onTheWay(){
		printf("����·��");
	}

	void parking(){
		printf("����ͣ����ͣ����");
	}
};

class sheep :public vehicle{
public:
	void inTheWater(){
		printf("������");
	}
	void enterPort(){
		printf("�Ѿ�����");
	}
};

class amphicar:public sheep,car{

	char onWitchWay[4];

};