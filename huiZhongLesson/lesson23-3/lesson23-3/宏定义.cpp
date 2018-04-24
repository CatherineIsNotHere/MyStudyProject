#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415926//宏定义命令 可定义常量（不常用）
const float pi = 3.1415926;//用来定义常量
#define ADD(a,b) (a+b)

//#ifdef //预编译指令 一般应用于修正不同平台的代码替换
//#endif //预编译指令 一般应用于修正不同平台的代码替换


void main(){
	float z = 2.f*PI*10.f;
	float x = 2.f*pi*10.f;

	int d = ADD(ADD(1,2) > ADD(2,3) ? 2 : 3, ADD(2, 3));

	system("pause");
}