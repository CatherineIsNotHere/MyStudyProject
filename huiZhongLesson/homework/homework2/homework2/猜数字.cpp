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
		printf("\n���һ�����֣�0-100������%d�λ���", guessTime);
		scanf_s("%d", &guess);
		if (guess > num){
			printf("\n�´���");
			guessTime--;
			continue;
		}
		else if (guess < num){
			printf("\n��С��");
			guessTime--;
			continue;
		}
		else if (guess == num){
			printf("\n�¶���");
			break;
		}
		else{
			printf("\n�������");
		}
	}
}