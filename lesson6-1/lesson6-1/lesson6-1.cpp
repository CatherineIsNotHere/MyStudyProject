#include "stdio.h"

//��ӡ0~100�ĵ���
void main(){
	int a = 0;
	for (int i = 1; i < 100; i++)
	{	
		a = i;
		if (i%2!=0){
			printf("%d\n",a);
		}
	}
}