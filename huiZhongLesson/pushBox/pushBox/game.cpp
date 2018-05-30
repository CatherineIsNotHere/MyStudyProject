#include "allSysInclude.h"
#include "sysTools.h"
#include "workMan.h"
#include "container.h"
#include "pushBoxMap.h"
/*
	0���յ�
	1��Ŀ�ĵ� ��
	2��ǽ�� ��
	4������ ��
	8����� ��
	*/
static Direction stepBacked = dirNone;
static Direction step = dirNone;
static int steps = 0;
static int boxNum = 0;
static int destinationNum = 0;
static container* boxes;//�����þ�̬ȫ�ֱ���
static pushBoxMap* _pushBoxMap = new pushBoxMap();
static workMan* man = new workMan();
static string fileStage = "001";

static int fileToMap();//��ȡ��ͼ
static void startPushBox();//��ʼ������������
static void drawMap();//����ͼ
static void initBoxAndDestination();//���ӳ�ʼ��
static container* findBox(int x, int y);//Ѱ�ҹ�����������
static void MoveBackwords(workMan* man, container* cont);//���˹���
static void IsVictory();//�Ƿ�ʤ��
static void overStage();//���ùؿ�����
static void gameSaves();//���ȱ���
static string readSaves();//��ȡ����
static void endGame();//��Ϸ����


void main() {
	string retry = readSaves();
	if (retry.length() != 0) {
		fileStage = retry;
	}
	startPushBox();
}

static void startPushBox() {

	if (!fileToMap())//��ȡ��ͼ
	{
		endGame();
		return;
	}
	HideCursor();//���ع��
	drawMap();//����ͼ
	initBoxAndDestination();
	char key = 0;
	container* movebox = nullptr;
	bool validStep = false;
	while (true)
	{
		key = _getch();//��ͣ�������У��ȴ��û���������
		validStep = true;
		int iWLY = man->getILocationY();//��ȡman������
		int iWLX = man->getILocationX();
		switch (key)
		{
		case 'W':
		case 'w':
			if (_pushBoxMap->m_imap[iWLY - 1][iWLX] == box || _pushBoxMap->m_imap[iWLY - 1][iWLX] == box + destination)//���������
			{
				if (_pushBoxMap->m_imap[iWLY - 2][iWLX] != wall && _pushBoxMap->m_imap[iWLY - 2][iWLX] != box && _pushBoxMap->m_imap[iWLY - 2][iWLX] != box + destination) {//�����Ӻ�߲���ǽ��������
					step = dirUp;
					man->Move(step, _pushBoxMap->m_imap);//�ƶ�����
					movebox = findBox(iWLX, iWLY - 1);//�ҵ�����
					movebox->Move(step, _pushBoxMap->m_imap);//�ƶ�����
					stepBacked = (Direction)((int)step*(-1));//���˹��ܸ�ֵ
				}
				else {
					validStep = false;
				}
			}
			else if (_pushBoxMap->m_imap[iWLY - 1][iWLX] != wall) {//����ǽ
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
			printf("%d��", steps);
		}
		IsVictory();
	}
}
/*
	���˹���
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
				printf("��");
				break;
			case destination + box:
				printf("��");
				boxNum++;
				break;
			case wall:
				printf("��");
				break;
			case box:
				printf("��");
				boxNum++;
				break;
			case player:
			case player + destination:
				printf("��");
				man->setILocationX(j);//��¼�������λ��
				man->setILocationY(i);
				break;
			default:
				break;
			}
		}
		printf("\n");
	}
	gotoxy(2 * 2, 16);
	printf("��%d��", _pushBoxMap->getIstage());
	gotoxy(2 * 14, 16);
	printf("%d��", steps);
	printf("\n\n\n ��W,A,S,D���ƹ���,\n ��E������,\n ��Q���˳���Ϸ��\n");
}
/*
	��ʼ������
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
	Ѱ������
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
	�Ƿ�ʤ��
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
				man->setILocationX(j);//��¼�������λ��
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
	��ȡ��ͼ
*/
static int fileToMap() {
	string mapUrl = "./maps/";
	mapUrl.append(fileStage);
	mapUrl.append(".txt");
	ifstream ifs(mapUrl);
	if (ifs.is_open()) {//�ɹ���
		_pushBoxMap->clearMap();
		int stage = 0;
		ifs >> stage;
		_pushBoxMap->setIstage(stage);
		int j = 0;
		for (int i = 0; i < 14; i++)//14��
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
		cout << "��ϲȫ��ͨ��" << endl;
		return 0;
	}
}

/*
	�������
*/
static void gameSaves() {
	ofstream outfile("./saves/playerSave.txt");
	outfile << fileStage << endl;
	outfile.close();
}
/*
	��ȡ����
*/
static string readSaves() {
	string st = "";
	ifstream ifs("./saves/playerSave.txt");
	ifs >> st;
	cout << "����ǰ�ڵ�" << st << "��,�Ƿ�����ؿ���Y/N��" << endl;
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
	���ùؿ�����
*/
static void overStage() {
	steps = 0;
	boxNum = 0;
	destinationNum = 0;
	step = dirNone;
	stepBacked = dirNone;
}
/*
	��Ϸ�����ͷ��ڴ�
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
