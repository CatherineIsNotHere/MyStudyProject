#pragma once;
#include <stdio.h>

FILE* openFile(char* fileStr);

void printFile(FILE* file);

void fileCopy(FILE* fstFile, FILE* scdFile, char* tirdFile);

