
//file name:queue.cpp
#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2

Status InitQueue(SqQueue *Q)  /*����һ���ն���Q*/
{
	Q->front = Q->rear = 0;
	return OK;
}//InitQueue

Status EnQueue(SqQueue *Q, ElemType e)/*����Ԫ��eΪQ���µĶ�βԪ��*/
{
	if (QueueLength(*Q) >= MAXSIZE - 1) {//����
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

int QueueLength(SqQueue Q) /*���ض���Q��Ԫ�ظ����������еĳ���*/
{
	return Q.rear;
}//QueueLength

Status DeQueue(SqQueue *Q, ElemType *e)  /*�����в�Ϊ�գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ*/
{
	if (QueueEmpty(*Q))
		return ERROR;
	e->i = Q->elem[Q->front].i;
	e->j = Q->elem[Q->front].j;
	e->pre = Q->elem[Q->front].pre;
	Q->front++;
	return OK;
}//DeQueue

Status QueueEmpty(SqQueue Q) /*������Ϊ�գ��򷵻���*/
{
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}//QueueEmpty

Status GetHead(SqQueue Q, ElemType *e)  /*�����в��գ���e���ض�ͷԪ��*/
{
	if (QueueEmpty(Q)) {//����ӿ�
		printf("The queue is empty!\n");
		return ERROR;
	}
	*e = Q.elem[Q.front];
	return OK;
}//GetHead
