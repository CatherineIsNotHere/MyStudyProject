#include "stdio.h"
#include "stdlib.h"
//#pragma warning(disable:4996)
/*
	"r" 打开一个用于读取的文本文件
	"w" 创建一个用于写入的文本文件
	"a" 附加到一个文本文件
	"rb" 打开一个用于读取的二进制文件
	"wb" 创建一个用于写入的二进制文件
	"ab" 附加到一个二进制文件
	"r+" 打开一个用于读/写的文本文件
	"w+" 创建一个用于读/写的文本文件
	"a+" 打开一个用于读/写的文本文件
	"rb+" 打开一个用于读/写的二进制文件
	"wb+" 创建一个用于读/写的二进制文件
	"ab+" 打开一个用于读/写的二进制文件
*/
long GetFileSize(FILE* file){
	//函数fseek()为给出的流设置位置数据
	//SEEK_SET 从文件的开始处开始搜索 
	//SEEK_CUR 从当前位置开始搜索
	//SEEK_END 从文件的结束处开始搜索
	fseek(file, 0, SEEK_END);//设置文件当前游标位置


	long size = ftell(file);//ftell()函数返回stream(流)当前的文件位置,如果发生错误返回-1. 


	return size;
}

void main(){

	FILE* pfile;
	errno_t err;
	err= fopen_s(&pfile,"c:\\abc.txt","r");

	if (err)
		printf("打开文件为空或路径找不到!\n");
	else
		printf("打开成功！\n");

	do
	{
		char szbuf[1024] = {};//读取每行的长度
		fgets(szbuf, sizeof(szbuf),pfile);//函数fgets()从给出的文件流中读取[num - 1]个字符并且把它们转储到str(字符串)中.
		if (szbuf == nullptr)
			printf("读取失败");
		printf(szbuf);
	} while (feof(pfile)==0);//函数feof()在到达给出的文件流的文件尾时返回一个非零值. 
	printf("\n");

	long size=GetFileSize(pfile);
	printf("文件大小为%dB\n",size);
	
	fclose(pfile);
	system("pause");
}