
//file name:main.cpp
#include<stdio.h>
#include<windows.h>
#include"maze.h"

int main()
{
	int row, col;
	int **MAZE;
	/*输入行和列生成迷宫图*/
	printf("\n>>>Input the maze's row and column(row<11,column<11): ");
	scanf_s("%d%d", &row, &col);
	while (row <= 0 || row>10 || col <= 0 || col>10) {
		printf("Dataes error!Please input suitable dataes\n");
		printf("\n>>>Input the maze's row and column: ");
		scanf_s("%d%d", &row, &col);
	}
	printf("\n>>>>>>>>>>A map is being created...\n");
	Sleep(500);
	ProduceArray(&MAZE, row, col);//动态生成一个二维数组
	ProduceMap(MAZE, row, col);//生成一张迷宫图
	PrintMap(MAZE, row, col, 1, 1);//打印迷宫

	printf("\n============>Finding the ways...\n");
	printf(">>>Caculating the shortest way...\n");
	Sleep(1000);
	if (FindPath(MAZE, row, col) == 0) {
		printf("Can not arrive!\n");
	}

	system("pause");
	return 0;
}