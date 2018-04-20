#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	char szdata[16] = "abcde";
	char szdata2[16] = {};
	memcpy(szdata2,szdata,sizeof(szdata));//内置参数为void类型，拷贝的是内存空间，所以内存必须是连续的
	memset(szdata2,0,sizeof(szdata2));//内存设置初值
	memcmp(szdata2,szdata,sizeof(szdata));

	system("pause");
}