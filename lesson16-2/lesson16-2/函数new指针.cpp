#include "stdio.h"

void MyNew(char* pointer){
	pointer = new char[32];//此时虽然pointer被给予了一个地址但是通过new的方法是重新赋予一个地址给pointer所以new后pointer！=p,此时p依旧为nullptr；
}

void MyNew2(char** pointer){
	*pointer = new char[32];//这里将p指针的地址赋予给pointer，然后通过new的方法赋予一个地址予解引用的pointer也就是p（地址），此时p即有值；
}

void main(){
	char* p = nullptr;
	//MyNew(p);//此时在此处由于p仍然为nullptr所以15行报错
	MyNew2(&p);//这是将p指针的地址赋予给pointer
	p[0] = 'a';
	delete p;
	p = nullptr;
}