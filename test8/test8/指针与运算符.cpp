#include "stdio.h"

/*
	见到某某++先把++运算符放到最后运算
*/
void main(){
	int x[] = {10,20,30};
	int* px = x;
	printf("++*px为：%d\n",++*px);//11
	printf("*px为：%d\n",*px);//11
	px = x;
	printf("(*px)++为：%d\n",(*px)++);//12是错的应该是11
	printf("*px为：%d\n",*px);//11是错的应该是12
	px = x;
	printf("*px++为：%d\n",*px++);//12
	printf("*px为：%d\n",*px);//12是错的应该是20
	px = x;
	printf("*++px为：%d\n",*++px);//20
	printf("*px为：%d\n",*px);//20

}