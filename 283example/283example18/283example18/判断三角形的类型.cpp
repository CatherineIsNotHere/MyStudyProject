#include "stdio.h"
#include "math.h"

void main(){
	float a = 0;
	float b = 0;
	float c = 0;
	float s = 0;
	float area = 0;
	printf("���������������ߣ�");
	scanf_s("%f%f%f",&a,&b,&c);
	if (a+b>c&&b+c>a&&a+c>b){
		s = (a + b + c) / 2;
		area = (float)sqrt(s*(s - a)*(s - b)*(s - c));
		printf("���������Ϊ��%.3f\n",area);
		if(a==b&&b==c&&a==c){
			printf("��������Ϊ�ȱ�������");
		}else if(a==b||a==c||b==c){
			printf("��������Ϊ����������");
		}
		else if ((a*a+b*b==c*c)||(b*b+c*c==a*a)||(a*a+c*c==b*b)){
			printf("��������Ϊֱ��������");
		}
		else{
			printf("��������Ϊ��ͨ������");
		}
	}
	else{
		printf("����Ĳ���������");
	}
}