#include "stdio.h"

void main(){
	FILE* file;
	errno_t err;
	err = fopen_s(&file,"c:\\abc.txt","a");
	if (!err){
		fputs("\nasdasdasdasd",file);//写入
		fprintf(file,"\n%d,%s",100,"helloworld");//写入2

		int arr[] = { 12,23,34 };
		fwrite(arr,4,sizeof(arr)/sizeof(int),file);//写二进制  fwrite()函数从数组buffer(缓冲区)中, 写count个大小为size(大小)的对象到stream(流)指定的流. 返回值是已写的对象的数量. 
		//第二个参数和第三个参数相乘等于arr的大小即可
		fclose(file);
	}

}