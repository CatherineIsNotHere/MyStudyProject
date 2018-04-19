#include <stdio.h>
#include <stdlib.h>



void main(){
	//创建文件
	errno_t err=-1;
	FILE* file = nullptr;
	err = fopen_s(&file, "./conf.ini", "w");
	if (!err){//创建成功
		printf("创建成功！");

	}
	else{
		printf("创建失败！");
	}

	system("pause");
}