#pragma once;
#include <stdio.h>

FILE* openFileForRead(char* fileStr);//���ַ���ʽ���ļ�

FILE* openFileForReadBinery(char* fileStr);//�Զ�������ʽ���ļ�

FILE* openFileForWrite(char* fileStr);//׼��дһ��file

FILE* openFileForWriteBinery(char* fileStr);//׼��дһ��������file

void printFile(FILE* file);

void fileCopy(FILE* fstFile, FILE* scdFile, char* tirdFile);

void fileCopyBinery(FILE* fstFile, FILE* scdFile, char* tirdFile);

int tarTheFiles(FILE* srcFiles, FILE* targetFile, int count);