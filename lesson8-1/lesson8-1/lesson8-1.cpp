#include "stdio.h"

/*
	输入一个半径值，分别计算圆周长，圆面积，球体积
*/
void main(){
	const float pi = 3.14;
	float r = 0;
	float perimeter = 0;//周长
	float acreage = 0;//面积
	float sphereAcreage = 0;//面积
	float volume = 0;//体积
	printf("请输入一个半径：");
	scanf_s("%f",&r);
	perimeter = 2 * pi*r;
	acreage = pi*r*r;
	sphereAcreage = 4 * pi*r*r;
	volume = 4 / 3 * pi*r*r*r;
	printf("圆周长为%.3f\n",perimeter);
	printf("圆面积为%.3f\n", acreage);
	printf("球面积为%.3f\n", sphereAcreage);
	printf("球体积为%.3f\n", volume);
}