
//file name:maze.cpp
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include"maze.h"
#include"stack.h"

Status ProduceArray(int ***array, int row, int col)
{
	int i;

	*array = (int **)malloc((row + 2) * sizeof(int *));
	for (i = 0; i < (row + 2); i++) {
		(*array)[i] = (int *)malloc((col + 2) * sizeof(int *));
	}
	return SUCCESS;
}

/*����һ��ͼ*/
Status ProduceMap(int **MAZE, int row, int col)
{
	int i, j;

	srand((unsigned)(time(NULL)));  //�������

	for (i = 0; i <= row + 1; i++) {
		for (j = 0; j <= col + 1; j++)
		{
			/*Χǽ�Ĵ���*/
			if (i == 0 || j == 0 || i == (row + 1) || j == (col + 1))
				MAZE[i][j] = 1;
			else {
				MAZE[i][j] = ((rand() % 10) > 6 ? 1 : 0);/*���������,���Ʋ����ĸ���*/
			}
		}
	}
	/*��ںͳ���*/
	MAZE[1][1] = MAZE[row][col] = 0;
	return SUCCESS;
}//ProduceMap

Status PrintMap(int **MAZE, int row, int col, int cur_x, int cur_y)
{
	system("cls");
	int i, j;
	const char *BAR = "��";  //�ϰ���ͼ��"��"
	const char *OBJ = "�I"; //����λ��ͼ��"�I"

	for (i = 0; i <= row + 1; i++) {
		for (j = 0; j <= col + 1; j++) {
			if (MAZE[i][j] == 1) {  //�ϰ���
				printf(BAR);
			}
			else if (i == cur_x&&j == cur_y) {  //�ƶ�����
				printf(OBJ);
			}
			else if (MAZE[i][j] == 0)  //��ͨλ�ã�2���ո�
				printf("  ");
		}
		printf("\n");
	}
	printf("Current position:(%d,%d)\n\n", cur_x, cur_y);
	return SUCCESS;
}//PrintMap

Status FindPath(int **MAZE, int row, int col) //Ѱ��·��
{
	ElemType head, e;
	int x, y, i, j, k;
	SqQueue Q;//����
	static int **MARK;//�������
	const DType Direction[8] = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, 1 },
	{ 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 } };

	ProduceArray(&MARK, row, col);
	MARK[0][0] = 0;//��ʼ��Ϊ��

	InitQueue(&Q);//���еĳ�ʼ��
	e.i = 1, e.j = 1, e.pre = -1;//���λ��
	EnQueue(&Q, e);//�����������
	MARK[1][1] = 1;//������齫�����Ϊ��ͨ��
	while (!QueueEmpty(Q)){//�����в�Ϊ��ʱ
		GetHead(Q, &head);//ȡ����ͷԪ�ظ�head
		x = head.i, y = head.j;
		for (k = 0; k < 8; k++) {  //����̽���������
			i = x + Direction[k].x;
			j = y + Direction[k].y;
			if (MAZE[i][j] == 0 && MARK[i][j] != 1) {//δͨ���ҿ���·
				e.i = i, e.j = j, e.pre = Q.front;
				EnQueue(&Q, e);//���µ�·�ŵ���β
				MARK[x][y] = 1;//�������·
			}
			if (i == row&&j == col) {//����������
				ShowShortPath(MAZE, row, col, Q);
				return SUCCESS;
			}
		}//for end
		DeQueue(&Q, &head);
	}//while end
	//�޷�ͨ��
	return FAIL;
}//FindPath

Status ShowShortPath(int **MAZE, int row, int col, SqQueue Q)  //��ӡ���·��
{
	SqStack S;
	InitStack(&S);
	SElemType e;
	int cur_x, cur_y;
	int count = 0;
	DType Way[100];

	int i = Q.rear - 1;

	while (i != -1)
	{
		Push(&S, Q.elem[i]);
		i = Q.elem[i].pre;
	}
	printf(">>>>One of the shortest way:\n");
	while (!StackEmpty(S))
	{
		Pop(&S, &e);
		cur_x = e.i, cur_y = e.j;
		Way[count].x = cur_x, Way[count++].y = cur_y;
		PrintMap(MAZE, row, col, cur_x, cur_y);
		Sleep(1000);
	}
	for (i = 0; i < count; i++) {
		printf("(%d,%d)\t", Way[i].x, Way[i].y);
		if ((i + 1) % 5 == 0)
			printf("\n");
	}
	printf("\n>>>>the shortest way need: %d steps\n\n", count);
	return SUCCESS;
}//ShowShortPath