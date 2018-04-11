#include "stdio.h"
#include "string.h"
#include "stdlib.h"

void main(){
	char *p1, *p2, s[50] = "xyz";
	p1 = "abcd";
	p2 = "ABCD";
	strcpy_s(s + 2, strcat_s(p1 + 2, p2 + 1));
	printf("%s", s);
	system("pause");
	return ;
}//xycdBCD