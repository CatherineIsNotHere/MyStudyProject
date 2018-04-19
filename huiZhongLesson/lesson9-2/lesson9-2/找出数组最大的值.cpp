#include "stdio.h"

void main(){
	int a[10] = { 1, 12, 3, 14, 5, 6, 7, 800, 19, -300 };
	int c = a[0];
	for (int i = 1; i < 10;i++){
		if (c>a[i]){
			c = a[i];
		}
	}
	printf("%d\n",c);
}