#include "stdio.h"

void main(){
	float* p = new float[3];
	p[0] = 1.2f;
	p[1] = 2.3f;
	p[2] = 3.4f;
	int p1 = (int)&p[0];//地址强转成十进制
	int* p3 = (int*)&p[0];//float类型想使用强转获取值，但是会失败
	int p4 = (int)p[0];
	void* p2 = (void*)&p[0];//用于获取地址，一般使用无类型获取

	delete[] p;
	p = nullptr;
}