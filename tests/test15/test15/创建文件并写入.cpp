#include <stdio.h>
#include <stdlib.h>



void main(){
	//�����ļ�
	errno_t err=-1;
	FILE* file = nullptr;
	err = fopen_s(&file, "./conf.ini", "w");
	if (!err){//�����ɹ�
		printf("�����ɹ���");

	}
	else{
		printf("����ʧ�ܣ�");
	}

	system("pause");
}