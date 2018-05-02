#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

/*
	0���յ�
	1��Ŀ�ĵ� ��
	2��ǽ�� ��
	4������ ��
	8����� ��
	*/
enum _state{
	space = 0,
	destination = 1,
	wall = 2,
	box = 4,
	player = 8,

} state;

typedef enum _playerDirection
{
	none,
	up,
	down,
	left,
	right,
}PlayerDirection;

int col = 0, row = 0;//�� ��
int isVictory = 0;
int stepBackforwards = 8;
int stepBacked = 0;
int steps = 0;//����ƶ��Ĳ���
PlayerDirection* direction = new PlayerDirection[stepBackforwards] {none};



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
void MoveLeft(int map[][14]);
void MoveRight(int map[][14]);
void MoveUp(int map[][14]);
void MoveDown(int map[][14]);
void MoveUpBox(int map[][14]);
void MoveDownBox(int map[][14]);
void MoveRightBox(int map[][14]);
void MoveLeftBox(int map[][14]);
void MoveSpace(int map[][14]);
void MoveBackwords(int map[][14]);
void gotoxy(unsigned char x, unsigned char y);

int main(){
	drawMap(map);
	int num = 0;
	char key = 0;
	while (true)
	{
		key = _getch();//��ͣ�������У��ȴ��û���������
		switch (key)
		{
		case 'W':
		case 'w':
			if (map[row - 1][col] == box || map[row - 1][col] == box + destination)//���������
			{
				if (map[row - 2][col] != wall&&map[row - 2][col] != box){//�����Ӻ�߲���ǽ��������
					MoveUp(map);
					MoveUpBox(map);
				}
			}
			else {//��������
				if (map[row - 1][col] != wall)//����ǽ
				MoveUp(map);//����
				gotoxy(2*col, row);
			}
			break;
		case 'A':
		case 'a':
			if (map[row][col - 1] == box || map[row][col - 1] == box + destination)
			{
				if (map[row][col - 2] != wall&&map[row][col - 2] != box){
					MoveLeft(map);
					MoveLeftBox(map);
				}
			}
			else
			{
				if (map[row][col - 1] != wall)
					MoveLeft(map);//����
			}
			
			break;
		case 'S':
		case 's':
			if (map[row + 1][col] == box || map[row + 1][col] == box + destination)
			{
				if (map[row + 2][col] != wall&&map[row + 2][col] != box){
					MoveDown(map);
					MoveDownBox(map);
				}
			}
			else
			{
				if (map[row + 1][col] != wall)
					MoveDown(map);//����
			}
			break;
		case 'D':
		case 'd':
			if (map[row][col + 1] == box || map[row][col + 1] == box + destination)
			{
				if (map[row][col + 2] != wall&&map[row][col + 2] != box){
					MoveRight(map);
					MoveRightBox(map);
				}
			}
			else
			{
				if (map[col + 1][row] != wall)
					MoveRight(map);//����
			}
			break;
		default:
			break;
		}
		//system("cls");
		//drawMap(map);
		if (isVictory == 10)
		{
			system("cls");
			printf("��ϲʤ��!");
		}
	}
	return 0;
}

void drawMap(int map[13][14]){
	int i = 0, j = 0;
	isVictory = 0;
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
				isVictory++;
				break;
			case wall:
				printf("��");
				break;
			case box:
				printf("��");
				break;
			case player:
			case player + destination:
				printf("��");
				row = i;
				col = j;//��¼�������λ��
				break;
			default:
				break;
			}
		}
		printf("\n");
	}
}

void MoveLeft(int map[][14]){
	map[row][col] -= player;
	map[row][col - 1] += player;
}

void MoveRight(int map[][14]){
	map[row][col] -= player;
	map[row][col + 1] += player;
}
void MoveUp(int map[][14]){
	map[row][col] -= player;
	map[row - 1][col] += player;
}
void MoveDown(int map[][14]){
	map[row][col] -= player;
	map[row + 1][col] += player;
}

void MoveLeftBox(int map[][14]){
	map[row][col - 2] += box;
	map[row][col - 1] -= box;
}

void MoveRightBox(int map[][14]){
	map[row][col + 2] += box;
	map[row][col + 1] -= box;
}
void MoveUpBox(int map[][14]){
	map[row - 2][col] += box;
	map[row - 1][col] -= box;
}
void MoveDownBox(int map[][14]){
	map[row + 2][col] += box;
	map[row + 1][col] -= box;
}


void MoveBackwords(int map[][14]){//���˹���

}

void gotoxy(unsigned char x, unsigned char y)
{
	COORD cor;
	HANDLE hout;
	cor.X = x;
	cor.Y = y;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, cor);
}