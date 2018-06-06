//file name:stack.cpp
#include<stdio.h>
#include"stdlib.h"
#include"stack.h"
#include"queue.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define OVERFLOW -2

Status InitStack(SqStack *S)  //构造一个空栈
{
	S->top = -1;
	return OK;
}//InitStack

Status StackEmpty(SqStack S)//若栈为空，返回TRUE，否则返回FALSE
{
	if (S.top == -1)
		return TRUE;
	else
		return FALSE;
}//StackEmpty

Status Push(SqStack *S, ElemType e)//插入元素作为新的栈顶元素
{
	if (S->top >= MAXSIZE - 1){//栈满
		printf("The stack is full!\n");
		return ERROR;
	}
	++S->top;
	S->elem[S->top].i = e.i;
	S->elem[S->top].j = e.j;
	S->elem[S->top].next = e.pre;
	return OK;
}//Push

Status Pop(SqStack *S, SElemType *e)//若栈不空，删除栈顶元素，用e返回其值
{
	if (S->top == -1)
	{
		printf("Empty stack!\n");
		return ERROR;
	}
	e->i = S->elem[S->top].i;
	e->j = S->elem[S->top].j;
	e->next = S->elem[--S->top].next;
	return OK;
}//Pop