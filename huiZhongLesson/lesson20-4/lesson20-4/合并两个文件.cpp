#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "�ļ�����.h"


void main(){

	///*
	//	��ӡ�ļ�����
	//*/
	//FILE* fstFile = openFile("./A.txt");
	//if (fstFile==nullptr){
	//	printf("��ʧ��");
	//}
	//FILE* scdFile = openFile("./B.txt");
	//if (scdFile == nullptr){
	//	printf("��ʧ��");
	//}
	//printFile(fstFile);//ʹ����fstFile��fgets��ò���Զ���file�������
	//printFile(scdFile);
	//
	///*
	//	���������ļ����������ļ�
	//*/

	////���Դ˴���Ҫ���´�һ��
	//fstFile = openFile("./A.txt");
	//if (fstFile == nullptr){
	//	printf("��ʧ��");
	//}
	//scdFile = openFile("./B.txt");
	//if (scdFile == nullptr){
	//	printf("��ʧ��");
	//}
	//fileCopy(fstFile, scdFile,"./C.txt");

	/*
		�Զ����Ƶķ�ʽ��ȡ�ļ�
	*/
	FILE* fstFileb = openFileBinery("./pic/frowny.bmp");
	if (fstFileb == nullptr){
		printf("��ʧ��");
	}
	FILE* scdFileb = openFileBinery("./pic/smiley.bmp");
	if (scdFileb == nullptr){
		printf("��ʧ��");
	}


}