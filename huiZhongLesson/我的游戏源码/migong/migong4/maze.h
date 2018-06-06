#ifndef MAZE_H
#define MAZE_H
#include "queue.h"

#define M 12
#define N 12
#define SUCCESS 1
#define FAIL 0

typedef int Status;
typedef struct {
	int x, y;
}DType;
Status ProduceArray(int ***, int, int);  //动态生成一个二维数组
Status ProduceMap(int **, int, int);//利用0 1随机数生成一张图(1为墙)
Status PrintMap(int **, int, int, int, int);//打印迷宫图
Status FindPath(int**, const int, const int); //寻找路线
Status ShowShortPath(int**, int, int, SqQueue);  //打印最短路

#endif // !MAZE_H