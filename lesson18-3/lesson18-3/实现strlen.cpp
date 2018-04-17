#include "stdio.h"
#include "string.h"

int strLen(char* arr){
	int size1 = 0;
	//for (int i = 0; i < 128; i++)
	//{
	//	if (arr[i] == '\0')
	//		break;
	//	else
	//		size1++;
	//}
	for (; arr[size1] != '\0'; ++size1);
	return size1;
}

int strLen2(char* arr){
	char* p = arr;
	for (; *arr++ != '\0';){
	
	}
	return arr - p - 1;
}
int wei = 0;
int strLen3(char* arr){
	int i = 0;
	if (i>=128){
		wei = 128;
	}
	else if(arr[0]!='\0'){
		wei++;
		i++;
		strLen3(++arr);
	}
	return wei;
}

void main(){
	int length = 128;
	//char* arr = new char[length];
	char arr2[128] = {};
	gets_s(arr2);
	//strcpy_s(arr,arr2);
	int c = strLen3(arr2);
	printf("您输入字符串的长度为%d", c);
}