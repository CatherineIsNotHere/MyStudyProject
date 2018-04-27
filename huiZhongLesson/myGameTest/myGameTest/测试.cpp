#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include <conio.h>


void main(){

	initgraph(640, 480);   // 这里和 TC 略有区别//这个函数用于初始化绘图环境。
	settextcolor(RGB(255, 255, 255));
	settextstyle(15, 0, L"黑体");//这个函数用于设置当前字体样式。
	outtextxy(20, 460, L"W，S移动，K攻击");
	

	//circle(200, 200, 100); // 画圆，圆心(200, 200)，半径 100
	_getch();               // 按任意键继续
	closegraph();          // 关闭图形界面

}