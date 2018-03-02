#include"queue.h"
#include<stdio.h>
#include<stdlib.h>


Status InitQueue(LinkQueue &Q) {

	Q.front = Q.rear = (QueuePtr)malloc(LEN);
	if (!Q.front)	exit(OVERFLOW);

	Q.front->next = NULL;
	return OK;
}

Status DestroyQueue(LinkQueue &Q) {

	while (Q.front) {
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}

	return OK;
}

Status ClearQueue(LinkQueue &Q) {
	/**

	* ��Q���, ���ͷŽ��ռ�

	*/
	QueuePtr q, p = Q.front->next;

	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	Q.front->next = NULL;
	Q.rear = Q.front;

	return OK;
}

Status QueueEmpty(LinkQueue Q) {

	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

int QueueLength(LinkQueue Q) {

	int i = 0;
	QueuePtr p = Q.front->next;

	while (p)
	{
		i++;
		p = p->next;
	}

	return i;
}

Status GetHead(LinkQueue Q, QElemType &e) {

	if (Q.front == Q.rear)

		return ERROR;

	e = Q.front->next->data;

	return OK;
}

Status EnQueue(LinkQueue &Q, QElemType e) {
	//����Ԫ��eΪQ���µĶ�βԪ��
	QueuePtr p = (QueuePtr)malloc(LEN);
	if (!p)	exit(OVERFLOW);

	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;

	return OK;

}

Status DeQueue(LinkQueue &Q, QElemType &e) {
	//�����в���,��ɾ��Q�Ķ�ͷԪ����e������ֵ,������OK
	if (Q.front == Q.rear)	return ERROR;
	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)	Q.rear = Q.front;
	free(p);
	return OK;

}

Status QueueTraverse(LinkQueue Q, Status(*visit)(QElemType &e)) {
	QueuePtr p;

	p = Q.front->next;

	while (p) {

		if (!(*visit)(p->data))

			return ERROR;

		p = p->next;

	}

	return OK;
}

Status visit_display(QElemType &e) {

	printf("%d ", e);

	return OK;
}

int main() {
	LinkQueue Q;
	QElemType e;
	InitQueue(Q);
	EnQueue(Q, 1);
	QueueTraverse(Q, visit_display);
	DeQueue(Q,e);
	QueueEmpty(Q) ? printf("��\n") : printf("�ǿ�\n");
	return 0;
}