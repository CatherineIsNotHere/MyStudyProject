#include "stdio.h"

void main(){
	int day, i;
	i = 1;
	day = 9;
	while (day > 0){
		i = ++i * 2;
		day--;
	}
	printf("%d", i);

}