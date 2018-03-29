/*
%c 字符
%d 带符号整数
%i 带符号整数
%e 科学计数法, 使用小写"e"
%E 科学计数法, 使用大写"E"
%f 浮点数
%g 使用%e或%f中较短的一个
%G 使用%E或%f中较短的一个
%o 八进制
%s 一串字符
%u 无符号整数
%x 无符号十六进制数, 用小写字母
%X 无符号十六进制数, 用大写字母
%p 一个指针
%n 参数应该是一个指向一个整数的指针
指向的是字符数放置的位置
%% 一个'%'符号
*/

#include "stdio.h"

void main(){
	char name[20] = "Bob";
	int age = 20;
	printf("Hello %s,you are %d years old\n",name,age);
}