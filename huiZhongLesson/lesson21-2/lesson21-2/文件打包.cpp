#include <stdio.h>
#include <string.h>  
#include <io.h>  
#include "�ļ�����.h"


struct AllFile
{
	char filePath[256];
	char fileName[256];
	long fileSize;
	long position;
};


void main(){

	char* fileName[]{"./A.txt", "./pic/smiley.bmp", "./B.txt"};
	char* targetFileName = { "./tar/tar1.paop" };

	int size = sizeof(fileName)/sizeof(fileName[0]);
	FILE* file = new FILE;
	FILE* targetFile = openFileForWriteBinery(targetFileName);
	AllFile* fileDetails = new AllFile[size];
	for (int i = 0; i < size; i++)
	{
		strcpy(fileDetails[i].filePath, fileName[i]);
		file = openFileForReadBinery(fileDetails[i].filePath);//��ȡÿ���ļ�
		if (file != nullptr){
			int no=_fileno(file);
			fileDetails[i].fileSize = _filelength(no);
			if (i==0)
			{
				//fileDetails[i].position=
			}
		

		}
		else
			printf("��ȡ�ļ�����");
	}


	//tarTheFiles(, targetFile, size);

	_fcloseall();
}