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
		printf("���һ������:\n");
		scanf_s("%d", &guess);
		time++;
		if (guess == num){
			printf("��ϲ��¶���,������%d�ξͲ¶��ˣ�",time);
			break;
		}
		else if (guess > num){
			printf("�´���");
			continue;
		}
		else if (guess < num){
			printf("��С��");
			continue;
		}
		else {
			printf("����Ƿ�");
			continue;
		}
	}

}