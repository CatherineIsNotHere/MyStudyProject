#include "stdio.h"
#include "string.h"

/*
	问题：使用char的时候输入总出现问题
	*/

void bbbb(){
	char in[] = { "0" };
	while (true)
	{
		printf("请选择难度：");
		scanf_s("%c", &in);
		for (int i = 0; i < sizeof(in); i++){
			printf("%c\n", in[i]);
		}
	}
}

void aaaa(){
	char aaa[1];
	while (true){
		printf("请输入y:\n");
		scanf_s("%c", &aaa);
		char a1= aaa[0];
		/*for (int i = 0; i < sizeof(aaa); i++){
			if (aaa[i] == '\n'){
				printf("有回车\n");
			}
			printf("%c\n", aaa[i]);
		}*/
		if (a1 != 'y'&&a1 != 'Y'&&a1 != 'n'&&a1 != 'N'){
			printf("能别瞎输么\n");
			continue;
		}
	}
}
void main(){
	aaaa();
}

