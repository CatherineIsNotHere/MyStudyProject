#include "stdio.h"

void main(){
	float* p = new float[3];
	p[0] = 1.2f;
	p[1] = 2.3f;
	p[2] = 3.4f;
	int p1 = (int)&p[0];//��ַǿת��ʮ����
	int* p3 = (int*)&p[0];//float������ʹ��ǿת��ȡֵ�����ǻ�ʧ��
	int p4 = (int)p[0];
	void* p2 = (void*)&p[0];//���ڻ�ȡ��ַ��һ��ʹ�������ͻ�ȡ

	delete[] p;
	p = nullptr;
}