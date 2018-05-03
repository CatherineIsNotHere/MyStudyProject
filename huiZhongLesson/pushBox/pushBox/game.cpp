#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "sysTools.h"

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


int col = 0, row = 0;//�� ��
int stepBackforwards = 8;
int stepBacked = 0;
int steps = 0;//����ƶ��Ĳ���


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
void IsVictory(int map[13][14]);//�Ƿ�ʤ��


void main(){
	HideCursor();//���ع��
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
				if (map[row][col + 1] != wall)
					MoveRight(map);//����
			}
			break;
		default:
			break;
		}
		IsVictory(map);
	}
}
void MoveLeft(int map[][14]){
	map[row][col] -= player;
	gotoxy(2 * col, row);
	if (map[row][col]==destination){
		printf("��");
	}
	else{
		printf("  ");
	}
	map[row][col - 1] += player;
	gotoxy(2 *(col-1), row);
	printf("��");
	
}

void MoveRight(int map[][14]){
	map[row][col] -= player;
	gotoxy(2 * col, row);
	if (map[row][col] == destination){
		printf("��");
	}
	else{
		printf("  ");
	}
	map[row][col + 1] += player;
	gotoxy(2 * (col + 1), row);
	printf("��");
}
void MoveUp(int map[][14]){
	map[row][col] -= player;
	gotoxy(2 * col, row);
	if (map[row][col] == destination){
		printf("��");
	}
	else{
		printf("  ");
	}
	map[row - 1][col] += player;
	gotoxy(2 * col, row-1);
	printf("��");
}
void MoveDown(int map[][14]){
	map[row][col] -= player;
	gotoxy(2 * col, row);
	if (map[row][col] == destination){
		printf("��");
	}
	else{
		printf("  ");
	}
	map[row + 1][col] += player;
	gotoxy(2 * col, row+1);
	printf("��");
}

void MoveLeftBox(int map[][14]){
	map[row][col - 2] += box;
	gotoxy(2 * (col-2), row);
	if (map[row][col - 2] == destination+box){
		printf("��");
	}
	else{
		printf("��");
	}
	map[row][col - 1] -= box;
}

void MoveRightBox(int map[][14]){
	map[row][col + 2] += box;
	gotoxy(2 * (col + 2), row);
	if (map[row][col + 2] == destination + box){
		printf("��");
	}
	else{
		printf("��");
	}
	map[row][col + 1] -= box;
}
void MoveUpBox(int map[][14]){
	map[row - 2][col] += box;
	gotoxy(2 * col, row-2);
	if (map[row-2][col] == destination + box){
		printf("��");
	}
	else{
		printf("��");
	}
	map[row - 1][col] -= box;
}
void MoveDownBox(int map[][14]){
	map[row + 2][col] += box;
	gotoxy(2 * col, row+2);
	if (map[row+2][col] == destination + box){
		printf("��");
	}
	else{
		printf("��");
	}
	map[row + 1][col] -= box;
}

//TODO
void MoveBackwords(int map[][14]){//���˹���

}



void drawMap(int map[13][14]){
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
				break;
			case player:
			case player+destination:
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
				row = i;
				col = j;//��¼�������λ��
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