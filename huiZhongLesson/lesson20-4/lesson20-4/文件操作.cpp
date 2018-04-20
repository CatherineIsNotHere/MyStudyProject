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
	err = fopen_s(&file, tirdFile, "wb");

	fseek(fstFile, 0, SEEK_END);
	long size = ftell(fstFile);
	fseek(fstFile, 0, SEEK_SET);
	char* pbuf = new char[size];
	//1.读取的最初地址
	//2.读取数据类型大小int为4char为1
	//3.读取几个只要第二个参数和第三个参数相乘等于文件大小即可
	//4.读取目标文件
	fread(pbuf, 1, size, fstFile);
	fwrite(pbuf, 1, size, file);//写二进制  fwrite()函数从数组buffer(缓冲区)中, 写count个大小为size(大小)的对象到stream(流)指定的流. 返回值是已写的对象的数量. 
	//第二个参数和第三个参数相乘等于arr的大小即可
	fseek(scdFile, 0, SEEK_END);
	long size2 = ftell(scdFile);
	fseek(scdFile, 0, SEEK_SET);
	char* pbuf2 = new char[size];
	fread(pbuf2, 1, size2, scdFile);
	fwrite(pbuf2, 1, size2, file);

}