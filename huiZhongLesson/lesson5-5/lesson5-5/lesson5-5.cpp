#include "stdio.h"
#include "stdlib.h"

void main(){
	int num = rand() % 100;
	printf("数字为%d\n", num);
	int time = 5;
	int guess = 0;
	bool b = false;
	printf("请输入一个数字：您有%d次机会", time);
	scanf_s("%d", &guess);
	if (!b && time > 0){
		if (num == guess){
			b = true;
			printf("恭喜猜对\n");
		}
		else if (num<guess){
			printf("大了\n");
		}
		else if (num>guess)
		{
			printf("小了\n");
		}
		time--;
	}
	if (!b && time > 0){
		printf("请输入一个数字：您有%d次机会", time);
		scanf_s("%d", &guess);
		if (num == guess){
			b = true;
			printf("恭喜猜对\n");
		}
		else if (num<guess){
			printf("大了\n");
		}
		else if (num>guess)
		{
			printf("小了\n");
		}
		time--;
	}
	if (!b && time > 0){
		printf("请输入一个数字：您有%d次机会", time);
		scanf_s("%d", &guess);
		if (num == guess){
			b = true;
			printf("恭喜猜对\n");
		}
		else if (num<guess){
			printf("大了\n");
		}
		else if (num>guess)
		{
			printf("小了\n");
		}
		time--;

	}
	if (!b && time > 0){
		printf("请输入一个数字：您有%d次机会", time);
		scanf_s("%d", &guess);
		if (num == guess){
			b = true;
			printf("恭喜猜对\n");
		}
		else if (num<guess){
			printf("大了\n");
		}
		else if (num>guess)
		{
			printf("小了\n");
		}
		time--;
	}
	if (!b && time > 0){
		printf("请输入一个数字：您有%d次机会", time);
		scanf_s("%d", &guess);
		if (num == guess){
			b = true;
			printf("恭喜猜对\n");
		}
		else if (num<guess){
			printf("大了\n");
		}
		else if (num>guess)
		{
			printf("小了\n");
		}
		time--;
	}
	system("pause");
}