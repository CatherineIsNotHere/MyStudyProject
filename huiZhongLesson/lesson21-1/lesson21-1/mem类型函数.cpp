#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	char szdata[16] = "abcde";
	char szdata2[16] = {};
	memcpy(szdata2,szdata,sizeof(szdata));//���ò���Ϊvoid���ͣ����������ڴ�ռ䣬�����ڴ������������
	memset(szdata2,0,sizeof(szdata2));//�ڴ����ó�ֵ
	memcmp(szdata2,szdata,sizeof(szdata));

	system("pause");
}