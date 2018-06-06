//file name:queue.h
#ifndef QUEUE_H
#define QUEUE_H

#define MAXSIZE 10000

typedef int Status; /*返回状态值*/
/*队列中数据元素类型*/
typedef struct
{
	int i, j;/*坐标值*/
	int pre;/*前一个位置在队列中的序号*/
}ElemType;
/*队列结构*/
typedef struct {
	int front, rear;
	ElemType elem[MAXSIZE];
}SqQueue;

Status InitQueue(SqQueue *);  /*构造一个空队列Q*/
int QueueLength(SqQueue); /*返回队列Q的元素个数，即队列的长度*/
Status EnQueue(SqQueue *, ElemType);/*插入元素e为Q的新的队尾元素*/
Status DeQueue(SqQueue *, ElemType *);  /*若队列不为空，则删除Q的队头元素，用e返回其值*/
Status QueueEmpty(SqQueue);/*若队列为空，则返回真*/
Status GetHead(SqQueue, ElemType *);  /*若队列不空，用e返回队头元素*/
#endif // !QUEUE_H
