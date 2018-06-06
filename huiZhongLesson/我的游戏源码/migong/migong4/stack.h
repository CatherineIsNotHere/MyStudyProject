//file name:stack.h
#ifndef STACK_H
#define STACK_H
#include "queue.h"

#define MAXSIZE 10000

typedef int Status; /*返回状态值*/
typedef struct
{
	int i, j;/*坐标值*/
	int next;/*前一个位置在队列中的序号*/
}SElemType;
/*队列结构*/
typedef struct {
	int top;
	SElemType elem[MAXSIZE];
}SqStack;
Status InitStack(SqStack *);  //构造一个空栈
Status StackEmpty(SqStack);//若栈为空，返回TRUE，否则返回FALSE
Status Push(SqStack *, ElemType);//插入元素作为新的栈顶元素
Status Pop(SqStack *, SElemType *);//若栈不空，删除栈顶元素，用e返回其值
#endif // !STACK_H
