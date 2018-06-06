
//file name:queue.cpp
#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2

Status InitQueue(SqQueue *Q)  /*构造一个空队列Q*/
{
	Q->front = Q->rear = 0;
	return OK;
}//InitQueue

Status EnQueue(SqQueue *Q, ElemType e)/*插入元素e为Q的新的队尾元素*/
{
	if (QueueLength(*Q) >= MAXSIZE - 1) {//队满
		printf("Queue is full!Can not continue to find the way...\n");
		exit(OVERFLOW);
	}
	else {
		Q->elem[Q->rear].i = e.i;
		Q->elem[Q->rear].j = e.j;
		Q->elem[Q->rear].pre = e.pre;
		Q->rear++;
	}
	return OK;
}//Enqueue

int QueueLength(SqQueue Q) /*返回队列Q的元素个数，即队列的长度*/
{
	return Q.rear;
}//QueueLength

Status DeQueue(SqQueue *Q, ElemType *e)  /*若队列不为空，则删除Q的队头元素，用e返回其值*/
{
	if (QueueEmpty(*Q))
		return ERROR;
	e->i = Q->elem[Q->front].i;
	e->j = Q->elem[Q->front].j;
	e->pre = Q->elem[Q->front].pre;
	Q->front++;
	return OK;
}//DeQueue

Status QueueEmpty(SqQueue Q) /*若队列为空，则返回真*/
{
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}//QueueEmpty

Status GetHead(SqQueue Q, ElemType *e)  /*若队列不空，用e返回队头元素*/
{
	if (QueueEmpty(Q)) {//如果队空
		printf("The queue is empty!\n");
		return ERROR;
	}
	*e = Q.elem[Q.front];
	return OK;
}//GetHead
