#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

/*
	自定义字符和数字的映射关系；基于二维数组打印一个游戏地图；
	打印俄罗斯方块并能够实现方块下落和移动，最终掉落停下。
	*/


void main(){
	/*char arr[5][4]{{ 0, 0, 0, 0 }, {1,1,1,1}, {2,2,2,2}, {3,3,3,3}, {4,4,4,4}};
	cout << "替换前:"<<endl;
	for (int i = 0; i < 5; i++)
	{
	for (int j = 0; j < 4; j++)
	{
	cout << (int)arr[i][j];
	}
	cout << endl;
	}
	cout << "替换后:" << endl;
	for (int i = 0; i < 5; i++)
	{
	for (int j = 0; j < 4; j++)
	{
	if (arr[i][j] == (char)0)
	arr[i][j] = 'a';
	if (arr[i][j] == (char)1)
	arr[i][j] = 'b';
	if (arr[i][j] == (char)2)
	arr[i][j] = 'c';
	if (arr[i][j] == (char)3)
	arr[i][j] = 'd';
	if (arr[i][j] == (char)4)
	arr[i][j] = 'e';
	}
	for (int j = 0; j < 4; j++)
	{
	cout << arr[i][j];
	}
	cout << endl;
	}*/

	char arr2[20][13]{{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }};
	int a = 1, b = 5, c = 2, d = 6;//正方形
	int flush = 1000;
	while (true)
	{
		arr2[a][b] = 2;//左上
		arr2[a][d] = 2;//右上
		arr2[c][b] = 2;//左下
		arr2[c][d] = 2;//右下
		int key;
		if (_kbhit())
		{
			system("cls");
			key = _getch();
			switch (key)
			{
			case 'W'://上
			case 'w':
				/*a -= 1;
				c -= 1;*/
				break;
			case 'A'://左
			case 'a':
				if (b > 1){
					arr2[a][d] = 0;//右上
					arr2[c][d] = 0;//右下
					b -= 1;
					d -= 1;
				}
				break;
			case 'S'://下
			case 's':
				arr2[a][b] = 0;//左上
				arr2[a][d] = 0;//右上
				a += 1;
				c += 1;
				break;
			case 'D'://右
			case 'd':
				if (d<11){
					arr2[a][b] = 0;//左上
					arr2[c][b] = 0;//左下
					b += 1;
					d += 1;
				}
				break;
			default:
				break;
			}
			
			for (int i = 0; i < 20; i++)
			{
				for (int j = 0; j < 13; j++)
				{
					switch (arr2[i][j])
					{
					case 1:
						cout << "■";
						break;
					case 0:
						cout << "  ";
						break;
					case 2:
						cout << "□";
						break;
					default:
						break;
					}
				}
				cout << endl;
			}
		}
		else{//更新数据
			system("cls");
			for (int i = 0; i < 20; i++)
			{
				for (int j = 0; j < 13; j++)
				{
					switch (arr2[i][j])
					{
					case 1:
						cout << "■";
						break;
					case 0:
						cout << "  ";
						break;
					case 2:
						cout << "□";
						break;
					default:
						break;
					}
				}
				cout << endl;
			}
			arr2[a][b] = 0;//左上
			arr2[a][d] = 0;//右上
			a += 1;
			c += 1;
			Sleep(100);
		}
		if (c>=19){
			break;
		}
	}
	system("pause");
}
