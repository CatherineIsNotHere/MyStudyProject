#include "stdio.h"

void main(){
	int i, j, t, a[11];					/*�������������Ϊ��������*/
	printf("������10����:\n");
	for (i = 1; i < 11; i++)
		scanf_s("%d", &a[i]);				/*�Ӽ���������Ҫ�����10������*/
	for ( i = 1; i < 11; i++)
	{
		for (j= i+1; j < 11; j++)
		{
			if (a[i]>a[j]){
				a[0] = a[i];
				a[i] = a[j];
				a[j] = a[0];
			}
		}
	}
	printf("������˳����:\n");
	for (i = 1; i <= 10; i++)
		printf("%5d", a[i]);				/*���ź�����������*/
	printf("\n");
}