#include <stdio.h>
#include "文件操作.h"

FILE* openFile(char* fileStr){//打开一个file返回file
	errno_t err = -1;
	FILE* file = nullptr;
	err=fopen_s(&file,fileStr,"r");
	if (err)
	{
		return nullptr;
	}
	return file;
}

FILE* openFileBinery(char* fileStr){//打开一个二进制file
	errno_t err = -1;
	FILE* file = nullptr;
	err = fopen_s(&file, fileStr, "rb");
	if (err)
	{
		return nullptr;
	}
	return file;
}


void printFile(FILE* file){//读取file中的内容
	char szbuf[1024] = {};
	do
	{
		fgets(szbuf,1024, file);
		printf(szbuf);
		//fseek(file, 0, SEEK_SET);//每次将游标放在初始则不会跳出循环
	} while (feof(file)==0);
	printf("\n");
}

void fileCopy(FILE* fstFile, FILE* scdFile,char* tirdFile){//将file1和file2合并到file3目录中
	errno_t err = -1;
	FILE* file = nullptr;
	err = fopen_s(&file, tirdFile, "w");
	char szbuf[1024] = {};
	do
	{
		fgets(szbuf, 1024, fstFile);
		fputs(szbuf, file);//写入
	} while (feof(fstFile) == 0);
	fputs("\n",file);
	do
	{
		fgets(szbuf, 1024, scdFile);
		fputs(szbuf, file);//写入
	} while (feof(scdFile) == 0);

}

void fileCopyBinery(FILE* fstFile, FILE* scdFile, char* tirdFile){//将file1和file2合并到file3目录中
	errno_t err = -1;
	FILE* file = nullptr;
	err = fopen_s(&file, tirdFile, "w");
	char szbuf[1024] = {};
	do
	{
		fgets(szbuf, 1024, fstFile);
		fputs(szbuf, file);//写入
	} while (feof(fstFile) == 0);
	fputs("\n", file);
	do
	{
		fgets(szbuf, 1024, scdFile);
		fputs(szbuf, file);//写入
	} while (feof(scdFile) == 0);

}