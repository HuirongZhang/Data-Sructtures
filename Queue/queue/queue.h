#pragma once

/**********************************

*                                *

* �ļ���: queue.h                 *

*                                *

* ��  ��: �������л���������������     *

*                                *

**********************************/

#include"Status.h"

#define LEN sizeof(struct QNode)

typedef  int QElemType;

typedef  int Status;

typedef struct QNode {

	QElemType data;

	struct QNode *next;

}QNode, *QueuePtr;



typedef struct {       //����������

	QueuePtr front;   //��ͷָ��

	QueuePtr rear;	  //��βָ��

}LinkQueue;



Status InitQueue(LinkQueue &Q);

Status DestroyQueue(LinkQueue &Q);

Status ClearQueue(LinkQueue &Q);

Status QueueEmpty(LinkQueue Q);

int QueueLength(LinkQueue Q);

Status GetHead(LinkQueue Q, QElemType &e);

Status EnQueue(LinkQueue &Q, QElemType e);

Status DeQueue(LinkQueue &Q, QElemType &e);

Status QueueTraverse(LinkQueue Q, Status(*visit)(QElemType &e));

Status visit_display(QElemType &e);

