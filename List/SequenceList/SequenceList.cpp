
/*************************************
*                                    *
* �ļ���: SquenceList.cpp             *
*                                    *
* ��  ��: ���Ա�Ļ���������������ʵ��    *
*                                    *
*************************************/


#include"Status.h"
#include"SequenceList.h"
#include<stdio.h>
#include<stdlib.h>

Status InitList(SqList &L) {
	L.elem = (ElemType*)malloc(LIST_INT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INT_SIZE;
	return OK;
}

Status DestoryList(SqList &L) {
	if (L.elem) free(L.elem);
	printf("���Ա�������!");
	return OK;
}

Status ClearList(SqList &L) {
	L.length = 0;
	printf("���Ա������!");
	return OK;
}

bool ListEmpty(SqList L) {
	if (0 == L.length)
		return TRUE;
	else
		return FALSE;
}

int ListLength(SqList L) {
	return L.length;
}

ElemType GetElem(SqList L, int i, ElemType &e) {
	if (i<1 || i>L.length)
		printf("iֵ���Ϸ�!");
	else {
		e = *(L.elem + i - 1);
	}
	return e;

}

int LocateElem(SqList L, ElemType e) {//���ص���(�±�-1)
	for (int i = 0; i < L.length; i++) {
		if (e == L.elem[i])
			return i;
	}
	return 0;//��ʾ�޴�Ԫ��
}

ElemType PriorElem(SqList L, ElemType current_e, ElemType &pre_e) {
	int i = LocateElem(L, current_e);
	if (i > 0) return L.elem[i - 1];

}

ElemType NextElem(SqList L, ElemType current_e, ElemType &next_e) {
	int i = LocateElem(L, current_e);
	if (i < L.length - 1) return L.elem[i + 1];
}

Status ListInsert(SqList &L, int i, ElemType e) {
	ElemType *p, *q, *newbase;

	if (i<1 || i>L.length + 1) return ERROR;

	if (L.length >= L.listsize) {
		newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}

	q = &(L.elem[i - 1]);

	for (p = &(L.elem[L.length - 1]); p >= q; --p) {
		*(p + 1) = *p;
	}
	*q = e;
	++L.length;
	return OK;

}

ElemType ListDelete(SqList &L, int i, ElemType &e) {
	ElemType *p = NULL, *q = NULL;

	if (i<1 || i>L.length + 1) return ERROR;

	p = &(L.elem[i - 1]);
	e = *q;
	q = L.elem + L.length - 1;
	for (++p; p <= q; ++p) {
		*(p - 1) = *p;
	}

	--L.length;
	return OK;

}

Status ListTraverse(SqList L) {
	int i = 0;
	for (int i = 0; i<L.length; i++) {
		printf("%d ", L.elem[i]);
	}
	return OK;
}
/**************�㷨2.1 ��ε��******************/

void Union(SqList &La, SqList Lb) {
	//��������Lb�е�����La�е�Ԫ�ز��뵽La
	int La_len = La.length;
	int Lb_len = Lb.length;
	ElemType e;
	for (int i = 1; i <= Lb.length; i++) {
		GetElem(Lb, i, e);
		if (!LocateElem(La, e))
			ListInsert(La, ++La_len, e);
	}

}
/**************�㷨2.2  ��ε��*******************/
void MergeList(SqList La, SqList Lb, SqList &Lc) {
	//��֪���Ա�La��Lb�е�����Ԫ�ذ�ֵ�ǵݼ�����
	//�鲢La��Lb�õ��µ����Ա�Lc,Lc������Ԫ��Ҳ��ֵ�ǵݼ�����
	InitList(Lc);
	int i = 1, j = 1, k = 0;
	int La_len = ListLength(La);
	int Lb_len = ListLength(Lb);
	ElemType ai, bj;

	while ((i <= La_len) && (j <= Lb_len)) {
		GetElem(La, i, ai);
		GetElem(Lb, j, bj);
		if (ai <= bj) {
			ListInsert(Lc, ++k, ai);
			++i;
		}
		else {
			ListInsert(Lc, ++k, bj);
			++j;
		}
	}

	while (i <= La_len) {
		GetElem(La, i++, ai);
		ListInsert(Lc, ++k, ai);
	}

	while (j <= Lb_len) {
		GetElem(Lb, j++, bj);
		ListInsert(Lc, ++k, bj);
	}
}