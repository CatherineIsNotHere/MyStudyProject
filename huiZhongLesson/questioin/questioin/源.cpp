#include "stdio.h"

void main()
{
	int  x = 3, y = 0, z = 0;
	int s = x = y + z;
	if (s)
		printf("* * * *");
	else
		printf("# # # #");
}
