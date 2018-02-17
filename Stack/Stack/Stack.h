/**********************************

*                                 *

* �ļ���: Stack.h                  *

*                                 *

* ��  ��:  ˳��ջ�Ļ���������������    *

*                                 *

**********************************/


#include"Status.h"

#define STACK_INIT_SIZE 100		//�洢�ռ��ʼ������

#define STACKINCREMENT 10		//�洢�ռ��������

typedef  int SElemType;

typedef  int Status;



typedef  struct {

	SElemType *base; //��ָ��

	SElemType *top;  //ָ��ջ����ָ��

	int stacksize;   //��ǰջ���������

}SqStack;

Status InitStack(SqStack &S);

Status DestroyStack(SqStack &S);

Status ClearStack(SqStack &S);

Status StackEmpty(SqStack S);

int StackLength(SqStack S);

Status GetTop(SqStack S, SElemType &e);

Status Push(SqStack &S, SElemType e);

Status Pop(SqStack &S, SElemType &e);

Status StackTraverse(SqStack S, Status(*visit)(SElemType));

Status visit_display(SElemType e);

Status display_char(SElemType e);