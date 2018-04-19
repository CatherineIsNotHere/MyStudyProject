#pragma once;
#include <stdio.h>

FILE* openFile(char* fileStr);//以字符形式打开文件

FILE* openFileBinery(char* fileStr);//以二进制形式打开文件

void printFile(FILE* file);

void fileCopy(FILE* fstFile, FILE* scdFile, char* tirdFile);

