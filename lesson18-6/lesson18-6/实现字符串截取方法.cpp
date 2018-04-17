#include "stdio.h"

void substrings(char* arr,char* arr2,int start,int last){
	int end = start + last-1;
	for (int i = 0; start <= end; start++,i++)
		arr2[i] = arr[start];
}

void main(){
	char arr[128] = {"abcdefgh"};
	char arr2[128] = {};
	int start = 0;
	int last = 0;
	printf("ÇëÊäÈë×Ö·û´®£º\n");
	gets_s(arr);
	printf("ÇëÊäÈë½ØÈ¡×Ö·û´®³õÊ¼Î»ÖÃ£º\n");
	scanf_s("%d",&start);
	printf("ÇëÊäÈë½ØÈ¡×Ö·û´®³¤¶È£º\n");
	scanf_s("%d", &last);
	substrings(arr,arr2,start,last);

	printf("½ØÈ¡ºóµÄ×Ö·û´®Îª£º%s",arr2);
}