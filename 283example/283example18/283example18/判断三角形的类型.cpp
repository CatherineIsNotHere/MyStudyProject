#include "stdio.h"
#include "math.h"

void main(){
	float a = 0;
	float b = 0;
	float c = 0;
	float s = 0;
	float area = 0;
	printf("请输入三角形三边：");
	scanf_s("%f%f%f",&a,&b,&c);
	if (a+b>c&&b+c>a&&a+c>b){
		s = (a + b + c) / 2;
		area = (float)sqrt(s*(s - a)*(s - b)*(s - c));
		printf("三角形面积为：%.3f\n",area);
		if(a==b&&b==c&&a==c){
			printf("该三角形为等边三角形");
		}else if(a==b||a==c||b==c){
			printf("该三角形为等腰三角形");
		}
		else if ((a*a+b*b==c*c)||(b*b+c*c==a*a)||(a*a+c*c==b*b)){
			printf("该三角形为直角三角形");
		}
		else{
			printf("该三角形为普通三角形");
		}
	}
	else{
		printf("输入的不是三角形");
	}
}