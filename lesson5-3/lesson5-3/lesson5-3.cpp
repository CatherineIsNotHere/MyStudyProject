#include "stdio.h";

int main(){
	printf("请输入分数： ");
	int score = 0;
		scanf_s("%d",&score);
		if (score==100){
			printf("完美\n");
		}
		else if(score>=90&&score<100){
			printf("优秀\n");
		}
		else if (score>=70){
			printf("还可以\n");
		}
		else if (score>=60){
			printf("凑合\n");
		}
		else
		{
			printf("不及格\n");
		}
	printf("test:");
	int score2 = 0;
	scanf_s("%d", &score2);
	printf("分数为:%d\n",score2);
	if (100>=score2>=90){
		printf("分数在100~90内\n");
	}
	else{
		printf("分数在100~90外\n");
	}
	/*
		综上所述：如此使用区间是不正确的，会先判断100>=score2是否为真，然后判断score2>=90
	*/
}