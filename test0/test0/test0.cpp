#include "stdio.h"
#include "string.h"

/*
	���⣺ʹ��char��ʱ�������ܳ�������
	*/

void bbbb(){
	char in[] = { "0" };
	while (true)
	{
		printf("��ѡ���Ѷȣ�");
		scanf_s("%c", &in);
		for (int i = 0; i < sizeof(in); i++){
			printf("%c\n", in[i]);
		}
	}
}

void aaaa(){
	char aaa[1];
	while (true){
		printf("������y:\n");
		scanf_s("%c", &aaa);
		char a1= aaa[0];
		/*for (int i = 0; i < sizeof(aaa); i++){
			if (aaa[i] == '\n'){
				printf("�лس�\n");
			}
			printf("%c\n", aaa[i]);
		}*/
		if (a1 != 'y'&&a1 != 'Y'&&a1 != 'n'&&a1 != 'N'){
			printf("�ܱ�Ϲ��ô\n");
			continue;
		}
	}
}
void main(){
	aaaa();
}

