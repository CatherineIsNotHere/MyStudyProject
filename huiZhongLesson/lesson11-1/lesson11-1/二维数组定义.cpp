#include "stdio.h"

void main(){
	int arr[2][3] = { {10,9,8},{100,99} };

	/*arr[0][0] = 10;
	arr[0][1] = 9;
	arr[0][2] = 8;
	arr[1][0] = 100;
	arr[1][1] = 99; 
	arr[1][2] = 98;*/
	for (int i = 0; i < 2;i++){
		for (int j = 0; j < 3; j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
}