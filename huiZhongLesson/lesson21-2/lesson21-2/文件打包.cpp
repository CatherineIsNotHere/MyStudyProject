#include <stdio.h>
#include <string.h>  
#include <io.h>  
#include "文件操作.h"


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
	fwrite(&filecount, szfilecount, 1, targetFile);//将头文件的文件个数写入新文件中
	long point = szfilecount;//计算文件节点
	long szfilePath = 0;//文件路径大小
	long szfileSize = 0;//文件大小
	long szposition = 0;//文件位置大小
	for (int i = 0; i < filecount; i++)
	{
		strcpy_s(fileDetails[i].filePath, fileName[i]);
		file = openFileForReadBinery(fileDetails[i].filePath);//读取每个文件
		szfilePath = sizeof(fileDetails[i].filePath);//计算文件路径需要存储的空间
		fwrite(&fileDetails[i].filePath, szfilePath, 1, targetFile);
		point += szfilePath;
		if (file != nullptr){
			int no = _fileno(file);
			fileDetails[i].fileSize = _filelength(no);//文件大小
			szfileSize = sizeof(fileDetails[i].fileSize);
			fwrite(&fileDetails[i].fileSize, szfileSize, 1, targetFile);
			if (i == 0)
			{
				fileDetails[i].position = szfilecount + filecount * sizeof(AllFile);//第一个文件的存储位置
			}
			else{
				fileDetails[i].position = fileDetails[i - 1].position + fileDetails[i - 1].fileSize;//第二个文件的存储位置
			}
			szposition = sizeof(fileDetails[i].position);//计算文件路径大小需要存储的空间
			fwrite(&fileDetails[i].position, szposition, 1, targetFile);
			point += szposition;
			fseek(targetFile, sizeof(int)+filecount * sizeof(AllFile),SEEK_SET);
			fwrite(file, fileDetails[i].fileSize,1,targetFile);
			fseek(targetFile, point, SEEK_SET);
		}
		else
			printf("读取文件错误");
	}


	//tarTheFiles(, targetFile, size);

	_fcloseall();
}