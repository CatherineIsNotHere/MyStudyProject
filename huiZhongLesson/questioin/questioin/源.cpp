#include "stdio.h"
#include "string.h"

struct{
	int x, y;
};

void main()
{
	char aa[10] = {};
	printf("%d\n", strlen(aa));
	printf("%d", sizeof(aa));

}