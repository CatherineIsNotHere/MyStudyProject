#include "stdio.h"

void main(){
	char arr[] = { 'a', 'b', 'c' };//个数为3
	char arr2[] = { "abc\"" };//个数为4，最后一个为]\0
	char arr3[] = "abc\'";
	int i = sizeof(arr);
	printf("%d\n", i);
	i = sizeof(arr2);
	printf("%d\n", i);
	i = sizeof(arr3);
	printf("%d\n", i);
	for (int j = 0; j < i-1; j++)
	{
		//if (arr2[j]=='\0'){
		//	break;
		//}
		printf("%c",arr2[j]);
	}
	printf("\n");
	printf("%s",arr3);//%s特点就是打印字符串
	getchar();
}