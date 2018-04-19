#include "stdio.h"
#include "string.h"
#pragma warning(disable:4996)


void main(){
	char str[128] = "abcde";
	strcpy(str,"xyz");//不用strcpy_s则如果str小于3长度则会溢出
	int hp = 100;
	int mp = 50;
	sprintf(str,"hp=%d,mp=%d\n",hp,mp);//将其他类型转换为字符串，str是接收字符串，hp,mp为任意类型
	printf("%s",str);
	printf("以上\n");
	sscanf(str,"hp=%d,mp=%d",&mp,&hp);//反向转换格式
	printf("hp=%d\n", hp);
	printf("mp=%d\n",mp);
	int c = strlen(str);//计算字符串长度，这里除去\0
	printf("有%d个字符\n",c);
	char* pbuf = new char[c + 1];//new了一个字符串
	strcpy(pbuf,str);//常用以上方法拷贝字符串
	strcmp(pbuf,str);//字符串比较函数 0为相等，不为零则不等


	delete[] pbuf;
	pbuf = nullptr;
}