#include "stdio.h";


//���������㷨
void sort(int s[]){
	int i = sizeof(s);
	int k = 0;
	for (int j = 2; j < i; j++){
		s[0] = s[j];
		k = j;
		while (s[0]<s[k-1]){
			s[k] = s[k-1];
			k--;
		}
		s[k] = s[0];
	}
}

void main(){
	int a[11] = {0,1,60,70,80,-20,30,90,10,20,20};
	printf("������10������������飺");
	//for (int i = 1; i < 11; i++)
	//{
	//	scanf_s("%d", &a[i]);
	//}
	printf("\nԭ����Ϊ��");
	for (int i = 0; i < 11; i++)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
	sort(a);
	printf("\n����������Ϊ��");
	for (int i = 0; i < 11; i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");
}