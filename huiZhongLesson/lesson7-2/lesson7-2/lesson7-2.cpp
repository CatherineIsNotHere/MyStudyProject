#include "stdio.h"

//++在前；先自增，再参与其他运算
//++在后；先参加运算，再自增
void main(){
	int m = 0;
	int n = m++ + 10;
	printf("%d\n%d",m,n);
}