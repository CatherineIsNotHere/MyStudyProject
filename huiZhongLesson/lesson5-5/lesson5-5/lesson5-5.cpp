#include "stdio.h"
#include "stdlib.h"

void main(){
	int num = rand() % 100;
	printf("����Ϊ%d\n", num);
	int time = 5;
	int guess = 0;
	bool b = false;
	printf("������һ�����֣�����%d�λ���", time);
	scanf_s("%d", &guess);
	if (!b && time > 0){
		if (num == guess){
			b = true;
			printf("��ϲ�¶�\n");
		}
		else if (num<guess){
			printf("����\n");
		}
		else if (num>guess)
		{
			printf("С��\n");
		}
		time--;
	}
	if (!b && time > 0){
		printf("������һ�����֣�����%d�λ���", time);
		scanf_s("%d", &guess);
		if (num == guess){
			b = true;
			printf("��ϲ�¶�\n");
		}
		else if (num<guess){
			printf("����\n");
		}
		else if (num>guess)
		{
			printf("С��\n");
		}
		time--;
	}
	if (!b && time > 0){
		printf("������һ�����֣�����%d�λ���", time);
		scanf_s("%d", &guess);
		if (num == guess){
			b = true;
			printf("��ϲ�¶�\n");
		}
		else if (num<guess){
			printf("����\n");
		}
		else if (num>guess)
		{
			printf("С��\n");
		}
		time--;

	}
	if (!b && time > 0){
		printf("������һ�����֣�����%d�λ���", time);
		scanf_s("%d", &guess);
		if (num == guess){
			b = true;
			printf("��ϲ�¶�\n");
		}
		else if (num<guess){
			printf("����\n");
		}
		else if (num>guess)
		{
			printf("С��\n");
		}
		time--;
	}
	if (!b && time > 0){
		printf("������һ�����֣�����%d�λ���", time);
		scanf_s("%d", &guess);
		if (num == guess){
			b = true;
			printf("��ϲ�¶�\n");
		}
		else if (num<guess){
			printf("����\n");
		}
		else if (num>guess)
		{
			printf("С��\n");
		}
		time--;
	}
	system("pause");
}