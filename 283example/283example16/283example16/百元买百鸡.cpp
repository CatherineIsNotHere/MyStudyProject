#include "stdio.h"

/*
	����һֵǮ�壬��ĸһֵǮ����������ֵǮһ����Ǯ��ټ����ʼ��̡���ĸ������������
*/
void main(){
	int cock, hen, chicken;
	for (cock = 0; cock <= 20;cock++)
	for (hen = 0; hen <= 33;hen++)
	for (chicken = 0; chicken < 99;chicken+=3)
	if (5*cock+3*hen+chicken/3==100)
	if (cock + hen + chicken == 100)
		printf("��������%d,ĸ������%d,С������%d\n",cock,hen,chicken);
}