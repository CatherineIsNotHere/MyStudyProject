#include "allSysInclude.h"
#include "sysTools.h"
#include "workMan.h"
#include "container.h"
/*
	0：空地
	1：目的地 ☆
	2：墙壁 ■
	4：箱子 □
	8：玩家 ♂
	*/



static Direction stepBacked = dirNone;
static Direction step = dirNone;
static int steps = 0;
static int boxNum = 0;
static container* boxes;//箱子用静态全局变量
static workMan* man = new workMan();

//int map[13][14] = {
//	{ space, space, space, space, wall, wall, wall, wall, wall, wall, space, space, space, space },
//	{ space, space, space, space, wall, space, space, space, space, wall, space, space, space, space },
//	{ space, wall, wall, wall, wall, space, space, box, box, wall, wall, wall, wall, wall },
//	{ space, wall, space, space, space, wall, space, space, space, wall, space, space, space, wall },
//	{ space, wall, space, box, space, space, space, box, space, space, space, box, space, wall },
//	{ space, wall, space, space, space, wall, wall, space, wall, wall, wall, wall, wall, wall },
//	{ wall, wall, wall, wall, box, wall, wall, space, space, space, space, space, space, wall },
//	{ wall, space, space, space, box, space, wall, space, space, space, player, space, space, wall },
//	{ wall, space, box, space, box, space, wall, space, wall, wall, wall, wall, wall, wall },
//	{ wall, wall, space, space, box, space, wall, space, wall, destination, destination, destination, wall, space },
//	{ space, wall, space, wall, wall, space, space, space, space, destination, destination, destination, wall, space },
//	{ space, wall, space, space, space, space, wall, wall, destination, destination, destination, destination, wall, space },
//	{ space, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, space }
//};

int map[13][14] = {
	{ 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0 },
	{ 0, 2, 2, 2, 2, 0, 0, 4, 4, 2, 2, 2, 2, 2 },
	{ 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2 },
	{ 0, 2, 0, 4, 0, 0, 0, 4, 0, 0, 0, 4, 0, 2 },
	{ 0, 2, 0, 0, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2 },
	{ 2, 2, 2, 2, 4, 2, 2, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 0, 0, 0, 4, 0, 2, 0, 0, 0, 8, 0, 0, 2 },
	{ 2, 0, 4, 0, 4, 0, 2, 0, 2, 2, 2, 2, 2, 2 },
	{ 2, 2, 0, 0, 4, 0, 2, 0, 2, 1, 1, 1, 2, 0 },
	{ 0, 2, 0, 2, 2, 0, 0, 0, 0, 1, 1, 1, 2, 0 },
	{ 0, 2, 0, 0, 0, 0, 2, 2, 1, 1, 1, 1, 2, 0 },
	{ 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0 }
};
void startPushBox();//开始推箱子主方法
static void drawMap();//画地图
static void initBox();//箱子初始化
static container* findBox(int x, int y);//寻找工人所推箱子
static void MoveBackwords(workMan* man,container* cont);//回退功能
static void IsVictory();//是否胜利


void main() {
	startPushBox();
}

void startPushBox() {
	HideCursor();//隐藏光标
	drawMap();//画地图
	initBox();
	char key = 0;
	container* movebox=nullptr;
	bool validStep = false;
	while (true)
	{
		key = _getch();//暂停程序运行，等待用户键盘输入
		validStep = true;
		int iWLY = man->getILocationY();//获取man的坐标
		int iWLX = man->getILocationX();
		switch (key)
		{
		case 'W':
		case 'w':
			if (map[iWLY - 1][iWLX] == box || map[iWLY - 1][iWLX] == box + destination)//如果是箱子
			{
				if (map[iWLY - 2][iWLX] != wall && map[iWLY - 2][iWLX] != box) {//且箱子后边不是墙或者箱子
					step = dirUp;
					man->Move(step, map);
					movebox =findBox(iWLX, iWLY - 1);
					movebox->Move(step, map);
					stepBacked = (Direction)((int)step*(-1));
				}
				else{
					validStep = false;
				}
			}
			else if (map[iWLY - 1][iWLX] != wall) {//不是墙
				step = dirUp;
				man->Move(step, map);
				movebox = nullptr;
				stepBacked = (Direction)((int)step*(-1));
			}
			else{
				validStep = false;
			}
			
			break;
		case 'A':
		case 'a':
			if (map[iWLY][iWLX - 1] == box || map[iWLY][iWLX - 1] == box + destination)
			{
				if (map[iWLY][iWLX - 2] != wall && map[iWLY][iWLX - 2] != box) {
					step = dirLeft;
					man->Move(step, map);
					movebox = findBox(iWLX - 1, iWLY);
					movebox->Move(step, map);
					stepBacked = (Direction)((int)step*(-1));
				}
				else{
					validStep = false;
				}
			}
			else if (map[iWLY][iWLX - 1] != wall) {
				step = dirLeft;
				man->Move(step, map);
				movebox = nullptr;
				stepBacked = (Direction)((int)step*(-1));
			}
			else{
				validStep = false;
			}
			break;
		case 'S':
		case 's':
			if (map[iWLY + 1][iWLX] == box || map[iWLY + 1][iWLX] == box + destination)
			{
				if (map[iWLY + 2][iWLX] != wall && map[iWLY + 2][iWLX] != box) {
					step = dirDown;
					man->Move(step, map);
					movebox = findBox(iWLX, iWLY + 1);
					movebox->Move(step, map);
					stepBacked = (Direction)((int)step*(-1));
				}
				else{
					validStep = false;
				}
			}
			else if (map[iWLY + 1][iWLX] != wall) {
				step = dirDown;
				man->Move(step, map);
				movebox = nullptr;
				stepBacked = (Direction)((int)step*(-1));
			}
			else{
				validStep = false;
			}
			break;
		case 'D':
		case 'd':
			if (map[iWLY][iWLX + 1] == box || map[iWLY][iWLX + 1] == box + destination)
			{
				if (map[iWLY][iWLX + 2] != wall && map[iWLY][iWLX + 2] != box) {
					step = dirRight;
					man->Move(step, map);
					movebox=findBox(iWLX + 1, iWLY);
					movebox->Move(step, map);
					stepBacked = (Direction)((int)step*(-1));
				}
				else{
					validStep = false;
				}
			}
			else if (map[iWLY][iWLX + 1] != wall) {
				step = dirRight;
				man->Move(step, map);
				movebox = nullptr;
				stepBacked = (Direction)((int)step*(-1));
			}
			else{
				validStep = false;
			}
			break;
		case 'E':
		case 'e':
			if (stepBacked != dirNone) {
				MoveBackwords(man, movebox);
				steps -= 2;
			}
			else{
				validStep = false;
			}
			break;
		case 'Q':
		case 'q':
			return;
		default:
			validStep = false;
			break;
		}
		if (validStep) {
			steps++;
			gotoxy(2 * 12, 14);
			printf("%d步", steps);
		}
		IsVictory();
	}
}
/*
	回退功能
*/
static void MoveBackwords(workMan* man, container* cont) {
	man->Move(stepBacked, map);
	if (cont!=nullptr) {
		cont->Move(stepBacked,map);
	}
	stepBacked = dirNone;
}

static void drawMap() {
	int i = 0, j = 0;
	for (i = 0; i < 13; i++)
	{
		for (j = 0; j < 14; j++)
		{
			switch (map[i][j])
			{
			case space:
				printf("  ");
				break;
			case destination:
				printf("☆");
				break;
			case destination + box:
				printf("★");
				break;
			case wall:
				printf("■");
				break;
			case box:
				printf("□");
				boxNum++;
				break;
			case player:
			case player + destination:
				printf("♂");
				man->setILocationX(j);//记录玩家所在位置
				man->setILocationY(i);
				break;
			default:
				break;
			}
		}
		printf("\n");
	}
	gotoxy(2 * 1, 14);
	printf("第x关");
	gotoxy(2 * 12, 14);
	printf("%d步", steps);
	printf("\n\n\n 按W,A,S,D控制工人,\n 按E键回退,\n 按Q键退出游戏。\n");
}

static void initBox() {
	boxes = new container[boxNum];
	int k = 0;
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			if (map[i][j] == box) {
				boxes[k].setILocationX(j);
				boxes[k].setIlocationY(i);
				k++;
			}
		}
	}
}

static container* findBox(int x, int y)
{
	container* scanboxes = boxes;
	for (int i = 0; i < boxNum; i++, scanboxes++)
	{
		if (scanboxes->getILocationX() == x && scanboxes->getILocationY() == y)
			return scanboxes;
	}

}

static void IsVictory() {
	int i = 0, j = 0;
	int isVictory = 0;
	for (i = 0; i < 13; i++)
	{
		for (j = 0; j < 14; j++)
		{
			switch (map[i][j])
			{
			case destination + box:
				isVictory++;
				break;
			case player:
			case player + destination:
				man->setILocationX(j);//记录玩家所在位置
				man->setILocationY(i);
				break;
			default:
				break;
			}
		}
	}
	if (isVictory == 10)
	{
		system("cls");
		printf("恭喜胜利!");
	}
}