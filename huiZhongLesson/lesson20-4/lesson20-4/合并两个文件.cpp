#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "文件操作.h"


void main(){

	///*
	//	打印文件内容
	//*/
	//FILE* fstFile = openFile("./A.txt");
	//if (fstFile==nullptr){
	//	printf("打开失败");
	//}
	//FILE* scdFile = openFile("./B.txt");
	//if (scdFile == nullptr){
	//	printf("打开失败");
	//}
	//printFile(fstFile);//使用完fstFile的fgets后貌似自动将file流清空了
	//printFile(scdFile);
	//
	///*
	//	复制两个文件到第三个文件
	//*/

	////所以此处还要重新打开一下
	//fstFile = openFile("./A.txt");
	//if (fstFile == nullptr){
	//	printf("打开失败");
	//}
	//scdFile = openFile("./B.txt");
	//if (scdFile == nullptr){
	//	printf("打开失败");
	//}
	//fileCopy(fstFile, scdFile,"./C.txt");

	/*
		以二进制的方式读取文件
	*/
	//FILE* fstFileb = openFileBinery("./pic/frowny.bmp");
	FILE* fstFileb = openFileBinery("./A.txt");
	if (fstFileb == nullptr){
		printf("打开失败");
	}

	//FILE* scdFileb = openFileBinery("./pic/smiley.bmp");
	FILE* scdFileb = openFileBinery("./B.txt");
	if (scdFileb == nullptr){
		printf("打开失败");
	}
	fileCopyBinery(fstFileb, scdFileb, "./C.txt");

}