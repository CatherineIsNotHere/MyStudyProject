#include <stdio.h>
/*
	用%e, %E和 %f,精度修饰符让你指定想要的小数位数. 例如,%12.6f
	将会至少显示12位数字,并带有6位小数的浮点数.
*/
void main(){
	float math = 100;
	float english = 100;
	float physics = 100;
	float chinese = 100;
	printf("请输入数学成绩：  ");
	scanf_s("%f/n", &math);
	printf("请输入英语成绩：  ");
	scanf_s("%f/n", &english);
	printf("请输入物理成绩：  ");
	scanf_s("%f/n", &physics);
	printf("请输入语文成绩：  ");
	scanf_s("%f/n", &chinese);

	printf("成绩为：\n%d\n%d\n%d\n%d\n", math, english, physics, chinese);
	int sum = math + english + physics + chinese;
	printf("您的总成绩为：%d\n", sum);
	printf("您的平均成绩为：%3.2f", float(sum/4));
}