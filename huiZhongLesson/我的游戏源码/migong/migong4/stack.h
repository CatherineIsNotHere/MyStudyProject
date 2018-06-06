//file name:stack.h
#ifndef STACK_H
#define STACK_H
#include "queue.h"

#define MAXSIZE 10000

typedef int Status; /*����״ֵ̬*/
typedef struct
{
	int i, j;/*����ֵ*/
	int next;/*ǰһ��λ���ڶ����е����*/
}SElemType;
/*���нṹ*/
typedef struct {
	int top;
	SElemType elem[MAXSIZE];
}SqStack;
Status InitStack(SqStack *);  //����һ����ջ
Status StackEmpty(SqStack);//��ջΪ�գ�����TRUE�����򷵻�FALSE
Status Push(SqStack *, ElemType);//����Ԫ����Ϊ�µ�ջ��Ԫ��
Status Pop(SqStack *, SElemType *);//��ջ���գ�ɾ��ջ��Ԫ�أ���e������ֵ
#endif // !STACK_H
