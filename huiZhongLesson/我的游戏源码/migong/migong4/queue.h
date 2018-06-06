//file name:queue.h
#ifndef QUEUE_H
#define QUEUE_H

#define MAXSIZE 10000

typedef int Status; /*����״ֵ̬*/
/*����������Ԫ������*/
typedef struct
{
	int i, j;/*����ֵ*/
	int pre;/*ǰһ��λ���ڶ����е����*/
}ElemType;
/*���нṹ*/
typedef struct {
	int front, rear;
	ElemType elem[MAXSIZE];
}SqQueue;

Status InitQueue(SqQueue *);  /*����һ���ն���Q*/
int QueueLength(SqQueue); /*���ض���Q��Ԫ�ظ����������еĳ���*/
Status EnQueue(SqQueue *, ElemType);/*����Ԫ��eΪQ���µĶ�βԪ��*/
Status DeQueue(SqQueue *, ElemType *);  /*�����в�Ϊ�գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ*/
Status QueueEmpty(SqQueue);/*������Ϊ�գ��򷵻���*/
Status GetHead(SqQueue, ElemType *);  /*�����в��գ���e���ض�ͷԪ��*/
#endif // !QUEUE_H
