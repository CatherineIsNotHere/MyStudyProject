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
Status ProduceArray(int ***, int, int);  //��̬����һ����ά����
Status ProduceMap(int **, int, int);//����0 1���������һ��ͼ(1Ϊǽ)
Status PrintMap(int **, int, int, int, int);//��ӡ�Թ�ͼ
Status FindPath(int**, const int, const int); //Ѱ��·��
Status ShowShortPath(int**, int, int, SqQueue);  //��ӡ���·

#endif // !MAZE_H