#include "stdio.h";

int main(){
	printf("����������� ");
	int score = 0;
		scanf_s("%d",&score);
		if (score==100){
			printf("����\n");
		}
		else if(score>=90&&score<100){
			printf("����\n");
		}
		else if (score>=70){
			printf("������\n");
		}
		else if (score>=60){
			printf("�պ�\n");
		}
		else
		{
			printf("������\n");
		}
	printf("test:");
	int score2 = 0;
	scanf_s("%d", &score2);
	printf("����Ϊ:%d\n",score2);
	if (100>=score2>=90){
		printf("������100~90��\n");
	}
	else{
		printf("������100~90��\n");
	}
	/*
		�������������ʹ�������ǲ���ȷ�ģ������ж�100>=score2�Ƿ�Ϊ�棬Ȼ���ж�score2>=90
	*/
}