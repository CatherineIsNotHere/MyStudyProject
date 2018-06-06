#include <stdio.h>
#include<Windows.h>
#include<time.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
#define WIDTH    26    //��
#define HEIGHT   26    //��
#define WALL     1     //ǽ
#define ROAD     0     //·
#define START    2     //���
#define END      3     //����

int px;
int py;
int tx;
int ty;
int map[WIDTH + 2][HEIGHT + 2];  //0 1
void walk();

void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}


void Paint(int x, int y)
{
	gotoxy(2 * y - 2, x - 1);

	switch (map[x][y])
	{
	case WALL:
		printf("��");
		break;
	case ROAD:
		printf("  ");
		break;
	case START:
		printf("��");
		px = x;
		py = y;
		break;
	case END:
		tx = x;
		ty = y;
		printf("��");
		break;
	}

}
void CreateMaze(int x, int y)
{
	//�����ĸ�����

	int dir[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };

	//�����������
	int j, temp;
	for (int i = 0; i < 4; i++)
	{
		j = rand() % 4;          //0-3
		temp = dir[i][0];
		dir[i][0] = dir[j][0];
		dir[j][0] = temp;
		temp = dir[i][1];
		dir[i][1] = dir[j][1];
		dir[j][1] = temp;
	}
	map[x][y] = ROAD;      //��ֵΪ·
	for (int i = 0; i < 4; i++)
	{
		if (map[x + 2 * dir[i][0]][y + 2 * dir[i][1]] == WALL) //�����Ƿ���ǽ     dir[0][0]
		{

			map[x + dir[i][0]][y + dir[i][1]] = ROAD;
			CreateMaze(x + 2 * dir[i][0], y + 2 * dir[i][1]);
		}

	}
}



int main()
{
	HideCursor();
	srand((unsigned int)time(NULL));
	//����Χ��ֵΪ0��·�� �м�ĸ�ֵΪ1��ǽ��
	for (int i = 0; i < HEIGHT + 2; i++)
	{
		for (int j = 0; j < WIDTH + 2; j++)
		{
			if (i == 0 || i == HEIGHT || j == 0 || j == WIDTH)
			{
				map[i][j] = ROAD;
			}
			else
			{
				map[i][j] = WALL;
			}
		}
	}
	CreateMaze(2 * (rand() % (HEIGHT / 2) + 1), 2 * (rand() % (WIDTH / 2) + 1));
	map[2][1] = START;              //���
	map[HEIGHT - 2][WIDTH - 1] = END;   //����

	for (int i = 1; i <= HEIGHT; i++)
	{
		for (int j = 1; j <= WIDTH; j++)
		{
			Paint(i, j);
		}
	}
	Paint(0, 0);
	walk();
	system("cls");
	gotoxy(HEIGHT / 2-4, WIDTH/2-4);
	cout << "��ϲͨ�أ������Ҽ������������ĵ��ˣ�" << endl;
	getchar();
	return 0;

}

void walk(){
	char key = 0;
	while (true){
		key = _getch();
		switch (key)
		{
		case 'w':
		case 'W':
			if (map[px - 1][py] != WALL&&map[px - 1][py] != END){
				gotoxy(2 * (py - 1), px - 1);
				cout << "  ";
				gotoxy(2 * (py - 1), px - 2);
				cout << "��";
				map[px][py] = ROAD;
				map[px - 1][py] = START;
				px--;
			}
			else if (map[px - 1][py] == END){
				return;
			}
			break;
		case 'a':
		case 'A':
			if (map[px][py - 1] != WALL&&map[px][py - 1] != END){
				gotoxy(2 * (py - 1), px - 1);
				cout << "  ";
				gotoxy(2 * (py - 2), px - 1);
				cout << "��";
				map[px][py] = ROAD;
				map[px][py - 1] = START;
				py--;
			}
			else if (map[px][py - 1] == END){
				return;
			}
			break;
		case 's':
		case 'S':
			if (map[px + 1][py] != WALL&&map[px + 1][py] != END){
				gotoxy(2 * (py - 1), px - 1);
				cout << "  ";
				gotoxy(2 * (py - 1), px);
				cout << "��";
				map[px][py] = ROAD;
				map[px + 1][py] = START;
				px++;
			}
			else if (map[px + 1][py] == END){
				return;
			}
			break;
		case 'd':
		case 'D':
			if (map[px][py + 1] != WALL&&map[px][py + 1] != END){
				gotoxy(2 * (py - 1), px - 1);
				cout << "  ";
				gotoxy(2 * py, px - 1);
				cout << "��";
				map[px][py] = ROAD;
				map[px][py + 1] = START;
				py++;
			}
			else if (map[px][py + 1] == END){
				return;
			}
			break;
		default:
			break;
		}
	}
}