#include <stdio.h>
#include "�ļ�����.h"


void main(){

	char* fileName[]{"./A.txt", "./pic/smiley.bmp", "./B.txt"};
	char* targetFileName = { "./tar/tar1.paop" };

	int size = sizeof(fileName)/sizeof(fileName[0]);
	FILE* file = new FILE;
	FILE* targetFile = openFileForWriteBinery(targetFileName);
	for (int i = 0; i < 1; i++)
	{
		file = openFileForReadBinery(fileName[i]);
		if (file != nullptr){

		}
		else
			printf("��ȡ�ļ�����");
	}


	//tarTheFiles(, targetFile, size);

	_fcloseall();
}