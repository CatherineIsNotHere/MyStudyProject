#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415926//�궨������ �ɶ��峣���������ã�
const float pi = 3.1415926;//�������峣��
#define ADD(a,b) (a+b)

//#ifdef //Ԥ����ָ�� һ��Ӧ����������ͬƽ̨�Ĵ����滻
//#endif //Ԥ����ָ�� һ��Ӧ����������ͬƽ̨�Ĵ����滻


void main(){
	float z = 2.f*PI*10.f;
	float x = 2.f*pi*10.f;

	int d = ADD(ADD(1,2) > ADD(2,3) ? 2 : 3, ADD(2, 3));

	system("pause");
}