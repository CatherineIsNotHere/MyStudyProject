#include "stdio.h"
#include "string.h"
#include "stdlib.h"




struct strs
{
	char inpstr[99];
};


int getsize(char* numstr){
	numstr[0];
	int k = 0;
	for (int i = 99; i >0; i--)
	{
		if (numstr[99 - i] == '\0'){
			break;
		}
		k++;
	}
	return k;
}

void main(){
	strs* str = new strs;
	char pp[99];
	printf("ÇëÊäÈë×Ö·û´®£º");
	//scanf_s("%s",&pp,99);
	gets_s(pp);
	strcpy_s(str->inpstr, pp);
	int num=getsize(str->inpstr);
	printf("×Ö·û´®³¤¶ÈÎª£º%d",num);
	delete str;
	str = nullptr;
	system("pause");
	
}