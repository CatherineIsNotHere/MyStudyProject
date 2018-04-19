#include "stdio.h"

int mystrcmp(char* arr1, char* arr2){

	for (; *arr1&&*arr2;arr1++,arr2++)
	{
		if (*arr1 != *arr2){
			break;
		}
	}
	return *arr1 - *arr2;
}

int mystrcmp2(char* arr1,char* arr2){
	int i = 0;
	for (i;arr1[i]&&arr2[i]; i++)
	{
		if (arr1[i]!=arr2[i]){
			break;
		}
	}
	return arr1[i] - arr2[i];
}

void main(){
	char arr1[128] = "hp=129";
	char arr2[128] = "hp=129";
	int c = mystrcmp2(arr1, arr2);
	printf("%d\n",c);
}