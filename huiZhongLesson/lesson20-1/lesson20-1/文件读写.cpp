#include "stdio.h"
#include "stdlib.h"
//#pragma warning(disable:4996)
/*
	"r" ��һ�����ڶ�ȡ���ı��ļ�
	"w" ����һ������д����ı��ļ�
	"a" ���ӵ�һ���ı��ļ�
	"rb" ��һ�����ڶ�ȡ�Ķ������ļ�
	"wb" ����һ������д��Ķ������ļ�
	"ab" ���ӵ�һ���������ļ�
	"r+" ��һ�����ڶ�/д���ı��ļ�
	"w+" ����һ�����ڶ�/д���ı��ļ�
	"a+" ��һ�����ڶ�/д���ı��ļ�
	"rb+" ��һ�����ڶ�/д�Ķ������ļ�
	"wb+" ����һ�����ڶ�/д�Ķ������ļ�
	"ab+" ��һ�����ڶ�/д�Ķ������ļ�
*/
long GetFileSize(FILE* file){
	//����fseek()Ϊ������������λ������
	//SEEK_SET ���ļ��Ŀ�ʼ����ʼ���� 
	//SEEK_CUR �ӵ�ǰλ�ÿ�ʼ����
	//SEEK_END ���ļ��Ľ�������ʼ����
	fseek(file, 0, SEEK_END);//�����ļ���ǰ�α�λ��


	long size = ftell(file);//ftell()��������stream(��)��ǰ���ļ�λ��,����������󷵻�-1. 


	return size;
}

void main(){

	FILE* pfile;
	errno_t err;
	err= fopen_s(&pfile,"c:\\abc.txt","r");

	if (err)
		printf("���ļ�Ϊ�ջ�·���Ҳ���!\n");
	else
		printf("�򿪳ɹ���\n");

	do
	{
		char szbuf[1024] = {};//��ȡÿ�еĳ���
		fgets(szbuf, sizeof(szbuf),pfile);//����fgets()�Ӹ������ļ����ж�ȡ[num - 1]���ַ����Ұ�����ת����str(�ַ���)��.
		if (szbuf == nullptr)
			printf("��ȡʧ��");
		printf(szbuf);
	} while (feof(pfile)==0);//����feof()�ڵ���������ļ������ļ�βʱ����һ������ֵ. 
	printf("\n");

	long size=GetFileSize(pfile);
	printf("�ļ���СΪ%dB\n",size);
	
	fclose(pfile);
	system("pause");
}