#include "stdio.h"
//1字节=8位
int main(){
	printf("helloWorld\n");
	getchar();
	
	//无符号  字符1字节(0-255)    定义一个无符号字符c
	unsigned char c = 255;
	//字符1字节(0-255)    定义一个字符c
	char o = 127;
	printf("无符号字符%d\n", c);
	printf("字符%d\n", o);
	getchar();

	//无符号  短整型2字节(0-65535) 定义一个无符号短整型d
	unsigned short d = 65535;
	//短整型2字节(0-65535) 定义一个短整型d
	short p = 32767;
	printf("无符号短整型%d\n", d);
	printf("短整型%d\n", p);
	getchar();
	
	//无符号  整型4字节（2的32次方） 定义一个无符号整型e
	unsigned int e = 4294967295;
	//整型4字节（2的32次方） 定义一个整型e
	int q = 2147483647;
	printf("无符号整型%d\n",e);
	printf("整型%d\n", q);
	getchar();
	
	//无符号  长整型4字节（2的32次方） 定义一个无符号长整型f
	unsigned long f = 4294967295;
	//长整型4字节（2的32次方） 定义一个长整型f
	long r = 2147483647;
	printf("无符号长整型%d\n", f);
	printf("长整型%d\n", r);
	getchar();

	//无符号  整型64 8字节（2的64次方） 定义一个无符号int64 g
	unsigned __int64 g = 18446744073709551615;
	//整型64 8字节（2的64次方） 定义一个int64 g
	__int64 s = 9223372036854775807;
	printf("无符号int64型%d\n", g);
	printf("int64型%d\n", s);
	getchar();

	//浮点型4字节（0.1f）定义一个浮点型 h
	float h = -0.1f;
	printf("浮点型%e", h);
	getchar();

	//双精度浮点型8字节 定义一个双精度浮点型i
	double i = 0.1;
	printf("双精度浮点型%e", i);
	getchar();

	//若定义一个变量但并未赋值，那么该变量为随机值
}