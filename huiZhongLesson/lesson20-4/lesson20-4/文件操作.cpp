#include <stdio.h>
#include "�ļ�����.h"

FILE* openFile(char* fileStr){//��һ��file����file
	errno_t err = -1;
	FILE* file = nullptr;
	err=fopen_s(&file,fileStr,"r");
	if (err)
	{
		return nullptr;
	}
	return file;
}

FILE* openFileBinery(char* fileStr){//��һ��������file
	errno_t err = -1;
	FILE* file = nullptr;
	err = fopen_s(&file, fileStr, "rb");
	if (err)
	{
		return nullptr;
	}
	return file;
}


void printFile(FILE* file){//��ȡfile�е�����
	char szbuf[1024] = {};
	do
	{
		fgets(szbuf,1024, file);
		printf(szbuf);
		//fseek(file, 0, SEEK_SET);//ÿ�ν��α���ڳ�ʼ�򲻻�����ѭ��
	} while (feof(file)==0);
	printf("\n");
}

void fileCopy(FILE* fstFile, FILE* scdFile,char* tirdFile){//��file1��file2�ϲ���file3Ŀ¼��
	errno_t err = -1;
	FILE* file = nullptr;
	err = fopen_s(&file, tirdFile, "w");
	char szbuf[1024] = {};
	do
	{
		fgets(szbuf, 1024, fstFile);
		fputs(szbuf, file);//д��
	} while (feof(fstFile) == 0);
	fputs("\n",file);
	do
	{
		fgets(szbuf, 1024, scdFile);
		fputs(szbuf, file);//д��
	} while (feof(scdFile) == 0);

}

void fileCopyBinery(FILE* fstFile, FILE* scdFile, char* tirdFile){//��file1��file2�ϲ���file3Ŀ¼��
	errno_t err = -1;
	FILE* file = nullptr;
	err = fopen_s(&file, tirdFile, "wb");

	fseek(fstFile, 0, SEEK_END);
	long size = ftell(fstFile);
	fseek(fstFile, 0, SEEK_SET);
	char* pbuf = new char[size];
	//1.��ȡ�������ַ
	//2.��ȡ�������ʹ�СintΪ4charΪ1
	//3.��ȡ����ֻҪ�ڶ��������͵�����������˵����ļ���С����
	//4.��ȡĿ���ļ�
	fread(pbuf, 1, size, fstFile);
	fwrite(pbuf, 1, size, file);//д������  fwrite()����������buffer(������)��, дcount����СΪsize(��С)�Ķ���stream(��)ָ������. ����ֵ����д�Ķ��������. 
	//�ڶ��������͵�����������˵���arr�Ĵ�С����
	fseek(scdFile, 0, SEEK_END);
	long size2 = ftell(scdFile);
	fseek(scdFile, 0, SEEK_SET);
	char* pbuf2 = new char[size];
	fread(pbuf2, 1, size2, scdFile);
	fwrite(pbuf2, 1, size2, file);

}