#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include <conio.h>


void main(){

	initgraph(640, 480);   // ����� TC ��������//����������ڳ�ʼ����ͼ������
	settextcolor(RGB(255, 255, 255));
	settextstyle(15, 0, L"����");//��������������õ�ǰ������ʽ��
	outtextxy(20, 460, L"W��S�ƶ���K����");
	

	//circle(200, 200, 100); // ��Բ��Բ��(200, 200)���뾶 100
	_getch();               // �����������
	closegraph();          // �ر�ͼ�ν���

}