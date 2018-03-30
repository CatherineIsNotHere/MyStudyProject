#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void main(){
	srand((unsigned)time(NULL));
	int num = rand()%100;
	printf("%d\n",num);
	int guess = 0;
	int time = 0;
	while (true){
		printf("请猜一个数字:\n");
		scanf_s("%d", &guess);
		time++;
		if (guess == num){
			printf("恭喜你猜对了,您猜了%d次就猜对了！",time);
			break;
		}
		else if (guess > num){
			printf("猜大了");
			continue;
		}
		else if (guess < num){
			printf("猜小了");
			continue;
		}
		else {
			printf("输入非法");
			continue;
		}
	}

}