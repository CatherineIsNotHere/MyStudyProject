#include "stdio.h"
#include "string.h"
#pragma warning(disable:4996)


void main(){
	char str[128] = "abcde";
	strcpy(str,"xyz");//����strcpy_s�����strС��3����������
	int hp = 100;
	int mp = 50;
	sprintf(str,"hp=%d,mp=%d\n",hp,mp);//����������ת��Ϊ�ַ�����str�ǽ����ַ�����hp,mpΪ��������
	printf("%s",str);
	printf("����\n");
	sscanf(str,"hp=%d,mp=%d",&mp,&hp);//����ת����ʽ
	printf("hp=%d\n", hp);
	printf("mp=%d\n",mp);
	int c = strlen(str);//�����ַ������ȣ������ȥ\0
	printf("��%d���ַ�\n",c);
	char* pbuf = new char[c + 1];//new��һ���ַ���
	strcpy(pbuf,str);//�������Ϸ��������ַ���
	strcmp(pbuf,str);//�ַ����ȽϺ��� 0Ϊ��ȣ���Ϊ���򲻵�


	delete[] pbuf;
	pbuf = nullptr;
}