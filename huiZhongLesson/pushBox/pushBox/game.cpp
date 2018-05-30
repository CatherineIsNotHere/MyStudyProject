#include "allSysInclude.h"
#include "sysTools.h"
#include "workMan.h"
#include "container.h"
#include "pushBoxMap.h"
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
static int destinationNum = 0;
static container* boxes;//箱子用静态全局变量
static pushBoxMap* _pushBoxMap = new pushBoxMap();
static workMan* man = new workMan();
static string fileStage = "001";

static int fileToMap();//读取地图
static void startPushBox();//开始推箱子主方法
static void drawMap();//画地图
static void initBoxAndDestination();//箱子初始化
static container* findBox(int x, int y);//寻找工人所推箱子
static void MoveBackwords(workMan* man, container* cont);//回退功能
static void IsVictory();//是否胜利
static void overStage();//重置关卡数据
static void gameSaves();//进度保存
static string readSaves();//读取进度
static void endGame();//游戏结束


void main() {
	string retry = readSaves();
	if (retry.length() != 0) {
		fileStage = retry;
	}
	startPushBox();
}

static void startPushBox() {

	if (!fileToMap())//读取地图
	{
		endGame();
		return;
	}
	HideCursor();//隐藏光标
	drawMap();//画地图
	initBoxAndDestination();
	char key = 0;
	container* movebox = nullptr;
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
			if (_pushBoxMap->m_imap[iWLY - 1][iWLX] == box || _pushBoxMap->m_imap[iWLY - 1][iWLX] == box + destination)//如果是箱子
			{
				if (_pushBoxMap->m_imap[iWLY - 2][iWLX] != wall && _pushBoxMap->m_imap[iWLY - 2][iWLX] != box && _pushBoxMap->m_imap[iWLY - 2][iWLX] != box + destination) {//且箱子后边不是墙或者箱子
					step = dirUp;
					man->Move(step, _pushBoxMap->m_imap);//移动工人
					movebox = findBox(iWLX, iWLY - 1);//找到箱子
					movebox->Move(step, _pushBoxMap->m_imap);//移动箱子
					stepBacked = (Direction)((int)step*(-1));//回退功能赋值
				}
				else {
					validStep = false;
				}
			}
			else if (_pushBoxMap->m_imap[iWLY - 1][iWLX] != wall) {//不是墙
				step = dirUp;
				man->Move(step, _pushBoxMap->m_imap);
				movebox = nullptr;
				stepBacked = (Direction)((int)step*(-1));
			}
			else {
				validStep = false;
			}

			break;
		case 'A':
		case 'a':
			if (_pushBoxMap->m_imap[iWLY][iWLX - 1] == box || _pushBoxMap->m_imap[iWLY][iWLX - 1] == box + destination)
			{
				if (_pushBoxMap->m_imap[iWLY][iWLX - 2] != wall && _pushBoxMap->m_imap[iWLY][iWLX - 2] != box && _pushBoxMap->m_imap[iWLY][iWLX - 2] != box + destination) {
					step = dirLeft;
					man->Move(step, _pushBoxMap->m_imap);
					movebox = findBox(iWLX - 1, iWLY);
					movebox->Move(step, _pushBoxMap->m_imap);
					stepBacked = (Direction)((int)step*(-1));
				}
				else {
					validStep = false;
				}
			}
			else if (_pushBoxMap->m_imap[iWLY][iWLX - 1] != wall) {
				step = dirLeft;
				man->Move(step, _pushBoxMap->m_imap);
				movebox = nullptr;
				stepBacked = (Direction)((int)step*(-1));
			}
			else {
				validStep = false;
			}
			break;
		case 'S':
		case 's':
			if (_pushBoxMap->m_imap[iWLY + 1][iWLX] == box || _pushBoxMap->m_imap[iWLY + 1][iWLX] == box + destination)
			{
				if (_pushBoxMap->m_imap[iWLY + 2][iWLX] != wall && _pushBoxMap->m_imap[iWLY + 2][iWLX] != box && _pushBoxMap->m_imap[iWLY + 2][iWLX] != box + destination) {
					step = dirDown;
					man->Move(step, _pushBoxMap->m_imap);
					movebox = findBox(iWLX, iWLY + 1);
					movebox->Move(step, _pushBoxMap->m_imap);
					stepBacked = (Direction)((int)step*(-1));
				}
				else {
					validStep = false;
				}
			}
			else if (_pushBoxMap->m_imap[iWLY + 1][iWLX] != wall) {
				step = dirDown;
				man->Move(step, _pushBoxMap->m_imap);
				movebox = nullptr;
				stepBacked = (Direction)((int)step*(-1));
			}
			else {
				validStep = false;
			}
			break;
		case 'D':
		case 'd':
			if (_pushBoxMap->m_imap[iWLY][iWLX + 1] == box || _pushBoxMap->m_imap[iWLY][iWLX + 1] == box + destination)
			{
				if (_pushBoxMap->m_imap[iWLY][iWLX + 2] != wall && _pushBoxMap->m_imap[iWLY][iWLX + 2] != box && _pushBoxMap->m_imap[iWLY][iWLX + 2] != box + destination) {
					step = dirRight;
					man->Move(step, _pushBoxMap->m_imap);
					movebox = findBox(iWLX + 1, iWLY);
					movebox->Move(step, _pushBoxMap->m_imap);
					stepBacked = (Direction)((int)step*(-1));
				}
				else {
					validStep = false;
				}
			}
			else if (_pushBoxMap->m_imap[iWLY][iWLX + 1] != wall) {
				step = dirRight;
				man->Move(step, _pushBoxMap->m_imap);
				movebox = nullptr;
				stepBacked = (Direction)((int)step*(-1));
			}
			else {
				validStep = false;
			}
			break;
		case 'E':
		case 'e':
			if (stepBacked != dirNone) {
				MoveBackwords(man, movebox);
				steps -= 2;
			}
			else {
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
			gotoxy(2 * 14, 16);
			printf("%d步", steps);
		}
		IsVictory();
	}
}
/*
	回退功能
*/
static void MoveBackwords(workMan* man, container* cont) {
	man->Move(stepBacked, _pushBoxMap->m_imap);
	if (cont != nullptr) {
		cont->Move(stepBacked, _pushBoxMap->m_imap);
	}
	stepBacked = dirNone;
}

static void drawMap() {
	system("cls");
	int i = 0, j = 0;
	for (i = 0; i < 14; i++)
	{
		for (j = 0; j < 16; j++)
		{
			switch (_pushBoxMap->m_imap[i][j])
			{
			case space:
				printf("  ");
				break;
			case destination:
				printf("☆");
				break;
			case destination + box:
				printf("★");
				boxNum++;
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
	gotoxy(2 * 2, 16);
	printf("第%d关", _pushBoxMap->getIstage());
	gotoxy(2 * 14, 16);
	printf("%d步", steps);
	printf("\n\n\n 按W,A,S,D控制工人,\n 按E键回退,\n 按Q键退出游戏。\n");
}
/*
	初始化箱子
*/
static void initBoxAndDestination() {
	boxes = new container[boxNum];
	int k = 0;
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (_pushBoxMap->m_imap[i][j] == box || _pushBoxMap->m_imap[i][j] == destination + box) {
				boxes[k].setILocationX(j);
				boxes[k].setIlocationY(i);
				k++;
			}
			else if (_pushBoxMap->m_imap[i][j] == destination || _pushBoxMap->m_imap[i][j] == destination + player)
				destinationNum++;
			if (_pushBoxMap->m_imap[i][j] == destination + box)
				destinationNum++;
		}
	}
}

/*
	寻找箱子
*/
static container* findBox(int x, int y)
{
	container* scanboxes = boxes;
	for (int i = 0; i < boxNum; i++, scanboxes++)
	{
		if (scanboxes->getILocationX() == x && scanboxes->getILocationY() == y)
			return scanboxes;
	}

}
/*
	是否胜利
*/
static void IsVictory() {
	int i = 0, j = 0;
	int isVictory = 0;
	for (i = 0; i < 14; i++)
	{
		for (j = 0; j < 16; j++)
		{
			switch (_pushBoxMap->m_imap[i][j])
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
	if (isVictory == destinationNum)
	{
		gameSaves();
		overStage();
		system("cls");

		int next = stoi(fileStage);
		next++;
		fileStage = to_string(next);
		string nStage = "";
		if (next > 0 && next < 10)
			nStage = "00";
		else if (next >= 10 && next < 100)
			nStage = "0";
		else if (next >= 100)
			nStage = "";
		nStage.append(fileStage);
		fileStage = nStage;
		startPushBox();
	}
}
/*
	读取地图
*/
static int fileToMap() {
	string mapUrl = "./maps/";
	mapUrl.append(fileStage);
	mapUrl.append(".txt");
	ifstream ifs(mapUrl);
	if (ifs.is_open()) {//成功打开
		_pushBoxMap->clearMap();
		int stage = 0;
		ifs >> stage;
		_pushBoxMap->setIstage(stage);
		int j = 0;
		for (int i = 0; i < 14; i++)//14行
		{
			string st;
			ifs >> st;
			j = 0;
			for (string::iterator ist = st.begin(); ist != st.end(); ist++) {
				char a = *ist;
				char* ab = &a;
				_pushBoxMap->m_imap[i][j] = atoi(ab);
				j++;
				if (j >= 16)
					break;
			}
		}
		ifs.close();
		return 1;
	}
	else {
		system("cls");
		cout << "恭喜全部通关" << endl;
		return 0;
	}
}

/*
	保存进度
*/
static void gameSaves() {
	ofstream outfile("./saves/playerSave.txt");
	outfile << fileStage << endl;
	outfile.close();
}
/*
	读取进度
*/
static string readSaves() {
	string st = "";
	ifstream ifs("./saves/playerSave.txt");
	ifs >> st;
	cout << "您当前在第" << st << "关,是否继续关卡（Y/N）" << endl;
	bool retry = false;
	switch (getchar())
	{
	case 'Y':
	case 'y':
		retry = false;
		break;
	case 'N':
	case 'n':
		retry = true;
		break;
	default:
		break;
	}
	ifs.close();
	if (retry)
		return "";
	else
		return st;
}

/*
	重置关卡数据
*/
static void overStage() {
	steps = 0;
	boxNum = 0;
	destinationNum = 0;
	step = dirNone;
	stepBacked = dirNone;
}
/*
	游戏结束释放内存
*/
static void endGame() {
	overStage();
	delete _pushBoxMap;
	delete[] man;
	delete[] boxes;
	_pushBoxMap = nullptr;
	man = nullptr;
	boxes = nullptr;
}
