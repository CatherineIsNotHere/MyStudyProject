#include "stdio.h"

void shsort(int s[], int n){
	int i, j, d;
	d = n / 2;
	while (d >= 1)
	{
		for (i = d + 1; i <=n ; i++)
		{
			s[0] = s[i];
			j = i-d;
			while ((j>0)&&(s[0]<s[j]))
			{
				s[j + d] = s[j];
				j = j - d;
			}
			s[j + d] = s[0];
		}
		d = d / 2;
	}
}


void main(){
	int a[11], i;
	for (i = 1; i < 11;i++){
		scanf_s("%d",&a[i]);
	}
	shsort(a, 10);
	for (i = 1; i < 11; i++)
	{
		printf("%d\t",a[i]);
	}
}