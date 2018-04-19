#include "stdio.h"
#include "stdlib.h"

void mystrcpy(char* dst,char* src){
	for (int i = 0;; i++)
	{
		dst[i] = src[i];
		if (dst[i]==0)
		{
			break;
		}
	}

}

void mystrcpy2(char* dst,char* src){
	for (;; *dst++, *src++)
	{
		*dst = *src;
		if (*dst==0){
			break;
		}
	}
}

void main(){

	char str[128] = {};
	char str2[128] = {};
	gets_s(str);
	mystrcpy2(str2, str);

	system("pause");
}