#include "stdio.h"

void main(){
	char arr[] = { 'a', 'b', 'c' };//����Ϊ3
	char arr2[] = { "abc\"" };//����Ϊ4�����һ��Ϊ]\0
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
	printf("%s",arr3);//%s�ص���Ǵ�ӡ�ַ���
	getchar();
}