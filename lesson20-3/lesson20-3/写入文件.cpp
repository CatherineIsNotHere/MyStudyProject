#include "stdio.h"

void main(){
	FILE* file;
	errno_t err;
	err = fopen_s(&file,"c:\\abc.txt","a");
	if (!err){
		fputs("\nasdasdasdasd",file);//д��
		fprintf(file,"\n%d,%s",100,"helloworld");//д��2

		int arr[] = { 12,23,34 };
		fwrite(arr,4,sizeof(arr)/sizeof(int),file);//д������  fwrite()����������buffer(������)��, дcount����СΪsize(��С)�Ķ���stream(��)ָ������. ����ֵ����д�Ķ��������. 
		//�ڶ��������͵�����������˵���arr�Ĵ�С����
		fclose(file);
	}

}