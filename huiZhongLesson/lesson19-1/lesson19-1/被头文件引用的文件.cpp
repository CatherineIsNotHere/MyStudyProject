#include "stdio.h"
#include "头文件练习.h"

int g = 100;
extern int j;
void Myprint(){
	printf("这个是新函数%d\n",j);
}