#pragma once;
#include <stdio.h>

FILE* openFile(char* fileStr);//���ַ���ʽ���ļ�

FILE* openFileBinery(char* fileStr);//�Զ�������ʽ���ļ�

void printFile(FILE* file);

void fileCopy(FILE* fstFile, FILE* scdFile, char* tirdFile);

