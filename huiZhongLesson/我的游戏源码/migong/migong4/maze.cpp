
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

/*生成一张图*/
Status ProduceMap(int **MAZE, int row, int col)
{
	int i, j;

	srand((unsigned)(time(NULL)));  //随机种子

	for (i = 0; i <= row + 1; i++) {
		for (j = 0; j <= col + 1; j++)
		{
			/*围墙的处理*/
			if (i == 0 || j == 0 || i == (row + 1) || j == (col + 1))
				MAZE[i][j] = 1;
			else {
				MAZE[i][j] = ((rand() % 10) > 6 ? 1 : 0);/*产生随机数,控制产生的概率*/
			}
		}
	}
	/*入口和出口*/
	MAZE[1][1] = MAZE[row][col] = 0;
	return SUCCESS;
}//ProduceMap

Status PrintMap(int **MAZE, int row, int col, int cur_x, int cur_y)
{
	system("cls");
	int i, j;
	const char *BAR = "▓";  //障碍物图案"▓"
	const char *OBJ = "㊣"; //物体位置图案"㊣"

	for (i = 0; i <= row + 1; i++) {
		for (j = 0; j <= col + 1; j++) {
			if (MAZE[i][j] == 1) {  //障碍物
				printf(BAR);
			}
			else if (i == cur_x&&j == cur_y) {  //移动对象
				printf(OBJ);
			}
			else if (MAZE[i][j] == 0)  //可通位置，2个空格
				printf("  ");
		}
		printf("\n");
	}
	printf("Current position:(%d,%d)\n\n", cur_x, cur_y);
	return SUCCESS;
}//PrintMap

Status FindPath(int **MAZE, int row, int col) //寻找路线
{
	ElemType head, e;
	int x, y, i, j, k;
	SqQueue Q;//队列
	static int **MARK;//标记数组
	const DType Direction[8] = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, 1 },
	{ 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 } };

	ProduceArray(&MARK, row, col);
	MARK[0][0] = 0;//初始化为零

	InitQueue(&Q);//队列的初始化
	e.i = 1, e.j = 1, e.pre = -1;//起点位置
	EnQueue(&Q, e);//将起点放入队列
	MARK[1][1] = 1;//标记数组将起点标记为已通过
	while (!QueueEmpty(Q)){//当队列不为空时
		GetHead(Q, &head);//取出队头元素给head
		x = head.i, y = head.j;
		for (k = 0; k < 8; k++) {  //依次探查各个方向
			i = x + Direction[k].x;
			j = y + Direction[k].y;
			if (MAZE[i][j] == 0 && MARK[i][j] != 1) {//未通过且可行路
				e.i = i, e.j = j, e.pre = Q.front;
				EnQueue(&Q, e);//将新的路放到队尾
				MARK[x][y] = 1;//标记已走路
			}
			if (i == row&&j == col) {//如果到达出口
				ShowShortPath(MAZE, row, col, Q);
				return SUCCESS;
			}
		}//for end
		DeQueue(&Q, &head);
	}//while end
	//无法通过
	return FAIL;
}//FindPath

Status ShowShortPath(int **MAZE, int row, int col, SqQueue Q)  //打印最短路线
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