#include "stdio.h"
//求任意数的的阶乘
void main(){
	int i = 2, n;
	int fac = 1;
	printf("求需要阶乘的数:");
	scanf_s("%d",&n);
	if (n==0||n==1){
		printf("factoral is 1.\n");
		return;
	}
	while (i<=n){
		fac = fac*i;
		i++;
	}
	printf("factoral of %d is %d", n, fac);

}