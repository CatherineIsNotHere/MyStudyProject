#include "stdio.h"
#include "stdlib.h"
#include "time.h"

bool first = true;//�ж��Ƿ��ǵ�һ������Ϸ
int count;//���ò´���
int num;//���òµ�����

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
					printf("��ӭ����������");
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
					printf("��ѡ���Ѷȣ�");
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
					printf("1.���Ѷ�");
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
					printf("2.�����Ѷ�");
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
					printf("3.�м��Ѷ�");
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
					printf("4.�߼��Ѷ�");
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
					printf("5.�����Ѷ�");
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
					printf("0.�˳���Ϸ");
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
		printf("��������Ҫ�µ����֣�������%d�λ��᣺\n", count);
		scanf_s("%d", &guess);
		guessTime++;
		if (guess > num){
			printf("���´��ˣ�\n");
		}
		else if (guess < num){
			printf("����С�ˣ�\n");
		}
		else if (guess == num){
			printf("��ϲ���¶��ˣ�������%d�Σ�\n", guessTime);
			break;
		}
		else{
			printf("�����������ѽ��\n");
			count++;
		}
		count--;
	} while (count > 0);
	if (count <= 0){
		printf("���ź���û�л����ˣ�\n");
	}
	return;
}

void level(){
	char in[] = {"0"};
	while (true)
	{
		printf("��ѡ���Ѷȣ�");
		scanf_s("%c", &in);
		if (in[0] != '1' && in[0] != '2' && in[0] != '3' && in[0] != '4'&& in[0] != '5' && in[0] != '0'){
			printf("�����������������\n");
			continue;
		}
		else if (in[0] == '1'){
			printf("��ѡ�������Ѷ�\n");
			num = rand() % 10;
			count = 999999;
			break;
		}
		else if (in[0] == '2'){
			printf("��ѡ���˳����Ѷ�\n");
			num = rand() % 10;
			count = 10;
			break;
		}
		else if (in[0] == '3'){
			printf("��ѡ�����м��Ѷ�\n");
			num = rand() % 100;
			count = 30;
			break;
		}
		else if (in[0] == '4'){
			printf("��ѡ���˸߼��Ѷ�\n");
			num = rand() % 100;
			count = 10;
			break;
		}
		else if (in[0] == '5'){
			printf("��ѡ���˵����Ѷ�\n");
			num = rand() % 1000;
			count = 30;
			break;
		}
		else if (in[0] == '0'){
			printf("�����˳���Ϸ\n");
			break;
		}
		else{
			printf("�����������������\n");
		}
	}
}

void main(){

	while (true){
		srand((unsigned)time(NULL));
		if (!first){
			char again[1];
			printf("���Ƿ�Ҫ����һ�֣�y/n��:\n");
			scanf_s("%c", &again);
			char a1 = again[0];
			printf("%d\n",a1);
			if (a1 != 'y'&&a1 != 'Y'&&a1 != 'n'&&a1 != 'N'){
				printf("�ܱ�Ϲ��ô\n");
				continue;
			}
			else if (a1 == 'y' || a1 == 'Y'){
				printf("������Ϸ\n");
				system("cls");
				_print(12);//��ӡ12�е���Ϸ����
				level();//��ȡ����
				startGuess(num, count);
				first=false;
			}
			else if (a1 == 'n' || a1 == 'N'){
				printf("��Ϸ������\n");
				getchar();
				return;
			}
			else{
				printf("����������ѽ���ܱ�Ϲ��ô\n");
			}
		}
		else{
			_print(12);//��ӡ12�е���Ϸ����
			level();
			startGuess(num, count);
			first = false;
		}
	}
}