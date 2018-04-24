#pragma once;
#include <stdio.h>

FILE* openFileForRead(char* fileStr);//以字符形式打开文件

FILE* openFileForReadBinery(char* fileStr);//以二进制形式打开文件

FILE* openFileForWrite(char* fileStr);//准备写一个file

FILE* openFileForWriteBinery(char* fileStr);//准备写一个二进制file

void printFile(FILE* file);

void fileCopy(FILE* fstFile, FILE* scdFile, char* tirdFile);

void fileCopyBinery(FILE* fstFile, FILE* scdFile, char* tirdFile);

int tarTheFiles(FILE* srcFiles, FILE* targetFile, int count);