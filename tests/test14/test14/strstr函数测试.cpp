#include "stdio.h"
#include "string.h"
#include "stdlib.h"

void main(){
	char str1[128] = { "poiisdelicious" };
	char str2[128] = { "delicious" };
	char* p=strstr(str1, str2);//p��һ��ָ���൱��&str1[5]
	//��������һ��ָ�룬��ָ���ַ���str2 �״γ������ַ���str1�е�λ�ã����û���ҵ�������NULL��
	system("pause");
}