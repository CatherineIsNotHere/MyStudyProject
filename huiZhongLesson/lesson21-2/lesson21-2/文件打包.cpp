#include <stdio.h>
#include <string.h>  
#include <io.h>  
#include "�ļ�����.h"


struct AllFile
{
	char filePath[256];
	long fileSize;
	long position;
};


void main(){

	//char* fileName[]{"./A.txt", "./pic/smiley.bmp", "./B.txt"};
	//char* targetFileName = { "./tar/tar1.paop" };
	char* fileName[]{"./A.txt", "./B.txt", "./C.txt"};
	char* targetFileName = { "./tar/tar2.paop" };

	int filecount = sizeof(fileName) / sizeof(fileName[0]);
	long szfilecount = sizeof(filecount);
	FILE* file = new FILE;
	FILE* targetFile = openFileForWriteBinery(targetFileName);
	AllFile* fileDetails = new AllFile[filecount];
	fwrite(&filecount, szfilecount, 1, targetFile);//��ͷ�ļ����ļ�����д�����ļ���
	long point = szfilecount;//�����ļ��ڵ�
	long szfilePath = 0;//�ļ�·����С
	long szfileSize = 0;//�ļ���С
	long szposition = 0;//�ļ�λ�ô�С
	for (int i = 0; i < filecount; i++)
	{
		strcpy_s(fileDetails[i].filePath, fileName[i]);
		file = openFileForReadBinery(fileDetails[i].filePath);//��ȡÿ���ļ�
		szfilePath = sizeof(fileDetails[i].filePath);//�����ļ�·����Ҫ�洢�Ŀռ�
		fwrite(&fileDetails[i].filePath, szfilePath, 1, targetFile);
		point += szfilePath;
		if (file != nullptr){
			int no = _fileno(file);
			fileDetails[i].fileSize = _filelength(no);//�ļ���С
			szfileSize = sizeof(fileDetails[i].fileSize);
			fwrite(&fileDetails[i].fileSize, szfileSize, 1, targetFile);
			if (i == 0)
			{
				fileDetails[i].position = szfilecount + filecount * sizeof(AllFile);//��һ���ļ��Ĵ洢λ��
			}
			else{
				fileDetails[i].position = fileDetails[i - 1].position + fileDetails[i - 1].fileSize;//�ڶ����ļ��Ĵ洢λ��
			}
			szposition = sizeof(fileDetails[i].position);//�����ļ�·����С��Ҫ�洢�Ŀռ�
			fwrite(&fileDetails[i].position, szposition, 1, targetFile);
			point += szposition;
			fseek(targetFile, sizeof(int)+filecount * sizeof(AllFile),SEEK_SET);
			fwrite(file, fileDetails[i].fileSize,1,targetFile);
			fseek(targetFile, point, SEEK_SET);
		}
		else
			printf("��ȡ�ļ�����");
	}


	//tarTheFiles(, targetFile, size);

	_fcloseall();
}