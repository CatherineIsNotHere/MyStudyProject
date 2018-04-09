#include "stdio.h"
#include "stdlib.h"
#include "time.h"

bool first = true;//判断是否是第一次玩游戏
int count;//设置猜次数
int num;//设置猜的数字

void _print(int n){
	for (int i = 0; i <= n; i++){
		switch (i){
		case 0:
			for (int j = 0; j < 24; j++){
				printf("**");
			}
			printf("\n");
			break;
		case 1:
			for (int j = 0; j < 24; j++){
				if (j == 8){
					printf("欢迎来到猜数字");
					j += 6;
				}
				else{
					printf("**");
				}
			}
			printf("\n");
			break;
		case 2:
			for (int j = 0; j < 24; j++){
				printf("**");
			}
			printf("\n");
			break;
		case 3:
			for (int j = 0; j < 24; j++){
				if (j == 1){
					printf("请选择难度：");
					j += 5;
				}
				else{
					printf("**");
				}
			}
			printf("\n");
			break;
		case 4:
			for (int j = 0; j < 24; j++){
				printf("**");
			}
			printf("\n");
			break;
		case 5:
			for (int j = 0; j < 24; j++){
				if (j == 1){
					printf("1.无难度");
					j += 3;
				}
				else{
					printf("**");
				}
			}
			printf("\n");
			break;
		case 6:
			for (int j = 0; j < 24; j++){
				if (j == 1){
					printf("2.初级难度");
					j += 4;
				}
				else{
					printf("**");
				}
			}
			printf("\n");
			break;
		case 7:
			for (int j = 0; j < 24; j++){
				if (j == 1){
					printf("3.中级难度");
					j += 4;
				}
				else{
					printf("**");
				}
			}
			printf("\n");
			break;
		case 8:
			for (int j = 0; j < 24; j++){
				if (j == 1){
					printf("4.高级难度");
					j += 4;
				}
				else{
					printf("**");
				}
			}
			printf("\n");
			break;
		case 9:
			for (int j = 0; j < 24; j++){
				if (j == 1){
					printf("5.地狱难度");
					j += 4;
				}
				else{
					printf("**");
				}
			}
			printf("\n");
			break;
		case 10:
			for (int j = 0; j < 24; j++){
				if (j == 1){
					printf("0.退出游戏");
					j += 4;
				}
				else{
					printf("**");
				}
			}
			printf("\n");
			break;
		case 11:
			for (int j = 0; j < 24; j++){
				printf("**");
			}
			printf("\n");
			break;
		default:
			printf("\n");
			break;
		}
	}
	return;
}

void startGuess(int num, int count){
	int guess = 0;
	int guessTime = 0;
	do{
		printf("请输入您要猜的数字，您还有%d次机会：\n", count);
		scanf_s("%d", &guess);
		guessTime++;
		if (guess > num){
			printf("您猜大了！\n");
		}
		else if (guess < num){
			printf("您猜小了！\n");
		}
		else if (guess == num){
			printf("恭喜您猜对了，您用了%d次！\n", guessTime);
			break;
		}
		else{
			printf("您介是输的嘛呀！\n");
			count++;
		}
		count--;
	} while (count > 0);
	if (count <= 0){
		printf("很遗憾你没有机会了！\n");
	}
	return;
}

void level(){
	char in[] = {"0"};
	while (true)
	{
		printf("请选择难度：");
		scanf_s("%c", &in);
		if (in[0] != '1' && in[0] != '2' && in[0] != '3' && in[0] != '4'&& in[0] != '5' && in[0] != '0'){
			printf("输入错误，请重新输入\n");
			continue;
		}
		else if (in[0] == '1'){
			printf("您选择了无难度\n");
			num = rand() % 10;
			count = 999999;
			break;
		}
		else if (in[0] == '2'){
			printf("您选择了初级难度\n");
			num = rand() % 10;
			count = 10;
			break;
		}
		else if (in[0] == '3'){
			printf("您选择了中级难度\n");
			num = rand() % 100;
			count = 30;
			break;
		}
		else if (in[0] == '4'){
			printf("您选择了高级难度\n");
			num = rand() % 100;
			count = 10;
			break;
		}
		else if (in[0] == '5'){
			printf("您选择了地狱难度\n");
			num = rand() % 1000;
			count = 30;
			break;
		}
		else if (in[0] == '0'){
			printf("您已退出游戏\n");
			break;
		}
		else{
			printf("输入错误，请重新输入\n");
		}
	}
}

void main(){

	while (true){
		srand((unsigned)time(NULL));
		if (!first){
			char again[1];
			printf("您是否还要再玩一局（y/n）:\n");
			scanf_s("%c", &again);
			char a1 = again[0];
			printf("%d\n",a1);
			if (a1 != 'y'&&a1 != 'Y'&&a1 != 'n'&&a1 != 'N'){
				printf("能别瞎输么\n");
				continue;
			}
			else if (a1 == 'y' || a1 == 'Y'){
				printf("继续游戏\n");
				system("cls");
				_print(12);//打印12行的游戏界面
				level();//获取级别
				startGuess(num, count);
				first=false;
			}
			else if (a1 == 'n' || a1 == 'N'){
				printf("游戏结束！\n");
				getchar();
				return;
			}
			else{
				printf("你介是输的嘛呀！能别瞎输么\n");
			}
		}
		else{
			_print(12);//打印12行的游戏界面
			level();
			startGuess(num, count);
			first = false;
		}
	}
}