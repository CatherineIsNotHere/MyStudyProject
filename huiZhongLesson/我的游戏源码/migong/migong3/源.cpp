#include <stdio.h>
#include <graphics.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

#define WINDOWWIDTH     640     //�����ڿ�
#define WINDOWHEIGHT    480     //�����ڸ�
#define WIDTH           480     //�Թ���
#define HEIGHT          480     //�Թ���
#define WALL            1       //�궨�� 
#define ROAD            0
#define UNIT            20

const SIZE g_utMAP = { 23, 23 };
const POINT g_utExit = { 21, 22 };
const POINT g_utPlayer = { 1, 1 };
const POINT g_ptOffset = { 10, 10 };

IMAGE g_imgMAP(WIDTH, HEIGHT);   //�Թ�λ��
DWORD* g_bufMap;                 // �Թ��Դ�
IMAGE g_imgRender(WIDTH, HEIGHT); //��ǰ��ͼ��
DWORD* g_bufRender;               //��ǰ��ͼ���Դ�
DWORD* g_bufScreen;                //������Ļ���Դ�
POINT g_ptPlayer;

enum CMD{ CMD_QUIT = 1, CMD_UP = 2, CMD_DOWN = 4, CMD_LEFT = 8, CMD_RIGHT = 16, CMD_RESTART = 32 };
void Welcome();
void TraveMaze(int x, int y, BYTE** aryMap);
void ReadyGo();
void InitGame();
void CreateMaze(int width, int height);
void DrawWall(int x, int y, bool left, bool right, bool up, bool down);
void GamePaint();
void DrawPlayer();


int main()
{
	initgraph(WINDOWWIDTH, WINDOWHEIGHT);
	Welcome();
	int ch;
	do
	{
		ReadyGo();
		while (true)
		{
			ch = GetCmd();
			//if
		}
		GamePaint();
	} while (!ch&CMD_QUIT);
	ReadyGo();
	/*setbkcolor(RED);     ������ɫ
	cleardevice();*/
	getchar();
	closegraph();

	return 0;
}
void Welcome()
{

	setfillcolor(DARKGRAY);
	solidrectangle(WIDTH, 0, WINDOWWIDTH, WINDOWHEIGHT);

	setbkmode(TRANSPARENT);
	outtextxy(490, 100, L"��Ҫ����ַ���");

}

void ReadyGo()      //ʵ�ֶϵ��Ч��
{
	InitGame();
	int time[7] = { 1000, 50, 500, 50, 50, 50, 50 };
	for (int i = 0; i < 7; i++)
	{
		if (i % 2 == 0)
		{
			putimage(0, 0, &g_imgMAP);
		}
		else
		{
			clearrectangle(0, 0, WIDTH, HEIGHT);
		}
		Sleep(time[i]);
	}

	for (int i = 255; i >= 0; i--)
	{
		for (int y = (HEIGHT - 1)*WINDOWWIDTH; y >= 0; y -= WINDOWWIDTH)
		{
			for (int x = 0; x < WIDTH; x++)
			{
				if (g_bufScreen[y + x] != 0)
					g_bufScreen[y + x] -= 0x050505;
			}
		}
		FlushBatchDraw();
		Sleep(50);
	}
	GamePaint();
}

void InitGame()
{
	g_bufRender = GetImageBuffer(&g_imgRender);
	g_bufMap = GetImageBuffer(&g_imgMAP);
	g_bufScreen = GetImageBuffer(NULL);

	SetWorkingImage(&g_imgRender);
	setbkmode(TRANSPARENT);
	SetWorkingImage(NULL);
	CreateMaze(g_utMAP.cx, g_utMAP.cy);

	g_ptPlayer.x = g_utPlayer.x*UNIT + UNIT / 2 + g_ptOffset.x;
	g_ptPlayer.y = g_utPlayer.x*UNIT + UNIT / 2 + g_ptOffset.y;
}
void CreateMaze(int width, int height)
{
	int x, y;
	//�����ά����
	BYTE** aryMap = new BYTE*[width + 2];
	for (x = 0; x < width + 2; x++);
	{
		aryMap[x] = new BYTE[height + 2];
		memset(aryMap[x], WALL, height + 2);
	}

	//�߽�
	for (x = 0; x <= width + 1; x++);
	{
		aryMap[x][0] = aryMap[x][height + 1] = ROAD;
	}
	for (y = 0; y <= height + 1; y++);
	{
		aryMap[0][y] = aryMap[width + 1][y] = ROAD;
	}

	TraveMaze(((rand() % (width - 1)) & 0xfffe) + 2, ((rand() % (height - 1)) & 0xffffe) + 2, aryMap);
	aryMap[g_utExit.x + 1][g_utExit.y + 1] = ROAD;

	SetWorkingImage(&g_imgMAP);
	cleardevice();
	for (int j = 1; j <= height; j++)
	{
		for (int i = 1; i <= width; i++)
		{
			if (aryMap[i][j] == WALL)
			{
				DrawWall(i, j,
					aryMap[i - 1][j] == WALL,
					aryMap[i + 1][j] == WALL,
					aryMap[i][j - 1] == WALL,
					aryMap[i][j + 1] == WALL);

			}

		}
	}


	SetWorkingImage(NULL);
}

void TraveMaze(int x, int y, BYTE** aryMap)
{
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

	aryMap[x][y] = ROAD;      //��ֵΪ·
	for (int i = 0; i < 4; i++)
	{
		if (aryMap[x + 2 * dir[i][0]][y + 2 * dir[i][1]] == WALL) //�����Ƿ���ǽ     dir[0][0]
		{

			aryMap[x + dir[i][0]][y + dir[i][1]] = ROAD;
			TraveMaze(x + 2 * dir[i][0], y + 2 * dir[i][1], aryMap);
		}

	}
}

//printf
void DrawWall(int x, int y, bool left, bool right, bool up, bool down)
{
	int cx, cy;
	cx = x*UNIT - UNIT / 2 - 2 + 10;
	cy = y*UNIT - UNIT / 2 - 2 + 10;

	if (left)  solidrectangle(x*UNIT - UNIT + 10, cy, cx + 4, cy + 4);
	if (right) solidrectangle(cx, cy, x*UNIT + 9, cy + 4);
	if (up)    solidrectangle(cx, y*UNIT - UNIT + 10, cx + 4, cy + 4);
	if (down)  solidrectangle(cx, cy, cx + 4, y*UNIT + 9);



}
void GamePaint()
{
	SetWorkingImage(&g_imgRender);
	cleardevice();
	//���Ƶƹ�

	//��Ϸ��
	DrawPlayer();
	//����
	SetWorkingImage(NULL);
	putimage(0, 0, &g_imgRender);

}
void DrawPlayer()
{
	setfillcolor(RED);
	fillcircle(g_ptPlayer.x, g_ptPlayer.y, 5);
}