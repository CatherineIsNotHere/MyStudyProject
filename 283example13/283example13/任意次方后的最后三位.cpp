#include "stdio.h"

void main(){
	int i, x, y, z = 1;
	printf("请输入两个数x^y:\n");
	scanf_s("%d%d",&x,&y);
	for (i = 1; i <= y;i++){
		z = z*x % 1000;
	}
	if (z >= 100){
		printf("%d^%d的最后三位是:%d\n", x, y, z);
	}
	else if (z>=10)
	{
		printf("%d^%d的最后三位是:0%d\n", x, y, z);
	}
	else{
		printf("%d^%d的最后三位是:00%d\n", x, y, z);
	}
}