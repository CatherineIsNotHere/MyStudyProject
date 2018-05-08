#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
	int guessTime = 5;
	int guess = 0;
	srand((unsigned)time(NULL));
	int num = rand() % 10;
	printf("%d", num);
	while (guessTime > 0)
	{
		guess = 0;
		printf("\n请猜一个数字（0-100）还有%d次机会", guessTime);
		scanf_s("%d", &guess);
		if (guess > num){
			printf("\n猜大了");
			guessTime--;
			continue;
		}
		else if (guess < num){
			printf("\n猜小了");
			guessTime--;
			continue;
		}
		else if (guess == num){
			printf("\n猜对了");
			break;
		}
		else{
			printf("\n输入错误");
		}
	}
}