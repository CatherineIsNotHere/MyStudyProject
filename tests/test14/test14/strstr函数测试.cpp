#include "stdio.h"
#include "string.h"
#include "stdlib.h"

void main(){
	char str1[128] = { "poiisdelicious" };
	char str2[128] = { "delicious" };
	char* p=strstr(str1, str2);//p是一个指针相当于&str1[5]
	//函数返回一个指针，它指向字符串str2 首次出现于字符串str1中的位置，如果没有找到，返回NULL。
	system("pause");
}