#include "allSysInclude.h"
#include "sysTools.h"
#include "workMan.h"
#include "container.h"
/*
	0���յ�
	1��Ŀ�ĵ� ��
	2��ǽ�� ��
	4������ ��
	8����� ��
	*/



int iWLX;
int iWLY;
int stepBackforwards = 8;
int stepBacked = 0;
int steps = 0;//����ƶ��Ĳ���
int boxNum = 0;

int map[13][14] = {
	{ space, space, space, space, wall, wall, wall, wall, wall, wall, space, space, space, space },
	{ space, space, space, space, wall, space, space, space, space, wall, space, space, space, space },
	{ space, wall, wall, wall, wall, space, space, box, box, wall, wall, wall, wall, wall },
	{ space, wall, space, space, space, wall, space, space, space, wall, space, space, space, wall },
	{ space, wall, space, box, space, space, space, box, space, space, space, box, space, wall },
	{ space, wall, space, space, space, wall, wall, space, wall, wall, wall, wall, wall, wall },
	{ wall, wall, wall, wall, box, wall, wall, space, space, space, space, space, space, wall },
	{ wall, space, space, space, box, space, wall, space, space, space, player, space, space, wall },
	{ wall, space, box, space, box, space, wall, space, wall, wall, wall, wall, wall, wall },
	{ wall, wall, space, space, box, space, wall, space, wall, destination, destination, destination, wall, space },
	{ space, wall, space, wall, wall, space, space, space, space, destination, destination, destination, wall, space },
	{ space, wall, space, space, space, space, wall, wall, destination, destination, destination, destination, wall, space },
	{ space, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, space }
};

void drawMap(int map[][14]);
void initBox(int map[13][14]);
void MoveUpBox(int map[][14]);
void MoveDownBox(int map[][14]);
void MoveRightBox(int map[][14]);
void MoveLeftBox(int map[][14]);
//void MoveSpace(int map[][14]);
void MoveBackwords(int map[][14]);
void IsVictory(int map[13][14]);//�Ƿ�ʤ��


static container* boxes;


void main(){
	HideCursor();//���ع��
	drawMap(map);//����ͼ
	initBox(map);
	int num = 0;
	char key = 0;
	workMan man(iWLX, iWLY);
	while (true)
	{
		key = _getch();//��ͣ�������У��ȴ��û���������
		switch (key)
		{
		case 'W':
		case 'w':
			if (map[iWLY - 1][iWLX] == box || map[iWLY - 1][iWLX] == box + destination)//���������
			{
				if (map[iWLY - 2][iWLX] != wall&&map[iWLY - 2][iWLX] != box){//�����Ӻ�߲���ǽ��������
					man.Move(dirUp,map);
					
					MoveUpBox(map);
				}
			}
			else {//��������
				if (map[iWLY - 1][iWLX] != wall)//����ǽ
					man.Move(dirUp, map);
			}
			break;
		case 'A':
		case 'a':
			if (map[iWLY][iWLX - 1] == box || map[iWLY][iWLX - 1] == box + destination)
			{
				if (map[iWLY][iWLX - 2] != wall&&map[iWLY][iWLX - 2] != box){
					man.Move(dirLeft, map);
					MoveLeftBox(map);
				}
			}
			else
			{
				if (map[iWLY][iWLX - 1] != wall)
					man.Move(dirLeft, map);
			}
			
			break;
		case 'S':
		case 's':
			if (map[iWLY + 1][iWLX] == box || map[iWLY + 1][iWLX] == box + destination)
			{
				if (map[iWLY + 2][iWLX] != wall&&map[iWLY + 2][iWLX] != box){
					man.Move(dirDown, map);
					MoveDownBox(map);
				}
			}
			else
			{
				if (map[iWLY + 1][iWLX] != wall)
					man.Move(dirDown, map);
			}
			break;
		case 'D':
		case 'd':
			if (map[iWLY][iWLX + 1] == box || map[iWLY][iWLX + 1] == box + destination)
			{
				if (map[iWLY][iWLX + 2] != wall&&map[iWLY][iWLX + 2] != box){
					man.Move(dirRight, map);
					MoveRightBox(map);
				}
			}
			else
			{
				if (map[iWLY][iWLX + 1] != wall)
					man.Move(dirRight, map);
			}
			break;
		default:
			break;
		}
		IsVictory(map);
	}
}



void MoveLeftBox(int map[][14]){
	map[iWLY][iWLX - 2] += box;
	gotoxy(2 * (iWLX-2), iWLY);
	if (map[iWLY][iWLX - 2] == destination+box){
		printf("��");
	}
	else{
		printf("��");
	}
	map[iWLY][iWLX - 1] -= box;
}

void MoveRightBox(int map[][14]){
	map[iWLY][iWLX + 2] += box;
	gotoxy(2 * (iWLX + 2), iWLY);
	if (map[iWLY][iWLX + 2] == destination + box){
		printf("��");
	}
	else{
		printf("��");
	}
	map[iWLY][iWLX + 1] -= box;
}
void MoveUpBox(int map[][14]){
	map[iWLY - 2][iWLX] += box;
	gotoxy(2 * iWLX, iWLY-2);
	if (map[iWLY-2][iWLX] == destination + box){
		printf("��");
	}
	else{
		printf("��");
	}
	map[iWLY - 1][iWLX] -= box;
}
void MoveDownBox(int map[][14]){
	map[iWLY + 2][iWLX] += box;
	gotoxy(2 * iWLX, iWLY+2);
	if (map[iWLY+2][iWLX] == destination + box){
		printf("��");
	}
	else{
		printf("��");
	}
	map[iWLY + 1][iWLX] -= box;
}

//TODO
void MoveBackwords(int map[][14]){//���˹���

}

static void drawMap(int map[][14]){
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
				printf("��");
				break;
			case destination + box:
				printf("��");
				break;
			case wall:
				printf("��");
				break;
			case box:
				printf("��");
				boxNum++;
				break;
			case player:
			case player+destination:
				printf("��");
				iWLX = j;//��¼�������λ��
				iWLY = i;
				break;
			default:
				break;
			}
		}
		printf("\n");
	}
}

static void initBox(int map[13][14]) {
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
	//for (int i = 0; i < boxNum; i++)
	//{
	//	printf("%d,%d\n",boxes[i].getILocationX(),boxes[i].getILocationY());
	//}
}

void IsVictory(int map[13][14]){
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
				iWLX = j;//��¼�������λ��
				iWLY = i;
				break;
			default:
				break;
			}
		}
	}
	if (isVictory == 10)
	{
		system("cls");
		printf("��ϲʤ��!");
	}
}