#include "stdio.h";

//99³Ë·¨±í
void main(){
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%d*%d=%d\t", i, j, i*j);
		/*	if (i == j)
				break;*/
		}
		printf("\n");
	}
}