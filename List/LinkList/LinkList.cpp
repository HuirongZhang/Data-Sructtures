/**********************************
*                                 *
* �ļ���: LinkList.cpp             *
*                                 *
* ��  ��: ��������Ļ�����������ʵ��    *
*                                 *
**********************************/

#include"Status.h"
#include"LinkList.h"
#include<stdio.h>
#include<stdlib.h>

void InitList_L(struct LNode * &L) {

	L=(struct LNode*)malloc(LEN);
	if (!L)	exit(OVERFLOW);
	L->next = NULL;

}

Status  DestoryList_L(struct LNode * &L) {

	struct LNode *p;
	if (!L) return OK;
	while (L)
	{
		p = L->next;
		free(L);
		L = p;
	}
	p = NULL;
	printf("�����ʽ�������\n");
	return OK;

}

void ClearList_L(struct LNode * &L) {
	//����L����Ϊ�ձ�

	L->next = NULL;
}

bool ListEmpty_L(struct LNode * &L) {
	//�ж��Ƿ�Ϊ�ձ��Ƿ���true, ���򷵻�false

	if (NULL == L->next)

		return true;

	else

		return false;
}

int ListLength_L(struct LNode * &L) {
	int len = 0;
	struct LNode *p = L->next;  // pָ���һ�����

	while (NULL != p) {

		len++;

		p = p->next;

	}

	return len;
}

Status GetElem_L(struct LNode * &L, int i, ElemType &e) {

	struct LNode *p = L->next;  // pָ���һ�����
	int j = 1;

	while ( p && j < i) {//˳ָ��������,ֱ��pָ��
		p = p->next;
		++j;
	}

	if (!p || j > i) {
		return ERROR;//��i��Ԫ�ز�����
	}

	e = p->data;
	return OK;
}

int LocateElem_L(struct LNode * &L, ElemType e) {

	struct LNode *p = L->next;  // pָ���һ�����
	int i = 0;
	if (NULL != p) {
		i++;
		if (e == p->data)
			return i;
		p = p->next;
	}
	return 0;

}

Status PriorElem_L(struct LNode * &L, ElemType cur_e, ElemType &pre_e) {
	//Ҫ�����Ա�L����

	//��cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶���
	int i = 0;
	struct LNode *p = L->next;  // pָ���һ�����
	if (NULL != p) {
		i = LocateElem_L(L, cur_e);
		if (0 != i && 1 != i) {
			GetElem_L(L, i - 1, pre_e);
			return OK;
		}
		p=p->next ;
	}
	return ERROR;
}

Status NextElem_L(struct LNode * &L, ElemType cur_e, ElemType &next_e) {

	//Ҫ�����Ա�L����

	//��cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ������������ʧ�ܣ�next_e�޶���
	int i = 0;
	struct LNode *p = L->next;  // pָ���һ�����
	if (NULL != p) {
		i = LocateElem_L(L, cur_e);
		if (i < ListLength_L(L)) {
			GetElem_L(L, i + 1, next_e);
			return OK;
		}
		p = p->next;
	}
	return ERROR;
}

Status ListInsert_L(struct LNode * &L, int i, ElemType e) {
	//�ڴ�ͷ���ĵ�����L�еĵ�i��λ��֮ǰ����Ԫ��e
	struct LNode *p = L;
	int j = 0;
	while (NULL!= p&&j < i - 1) {//Ѱ�ҵ�i-1�����
		p = p->next;
		++j;
	}
	if (NULL==p || j > i - 1)
		return ERROR;//iС��1���ߴ��ڱ���1

	struct LNode *s;
	s= (struct LNode*)malloc(LEN);
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;

}

Status ListDelete_L(struct LNode * &L, int i, ElemType &e) {
	//�ڴ�ͷ���ĵ�����L ��,ɾ����i��Ԫ��,����e������ֵ
	struct LNode *q,*p = L;
	int j = 0;
	while (p->next&&j < i - 1) {//Ѱ�ҵ�i�����,����pָ����ǰ��
		p = p->next;
		++j;

	}

	if (!(p->next) || j > i - 1)//ɾ��λ�ò�����
		return ERROR;

	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);

	return OK;

}

Status ListTraverse_L(struct LNode * &L, Status(*visit)(struct LNode * &)) {
	//Ҫ�����Ա����

	//���ζ�L��ÿ��Ԫ�ص��ú���visit(), һ��visit()ʧ�ܣ������ʧ�ܣ�����FALSE,���򷵻�TRUE



	struct LNode *p;

	p = L->next;   // pָ���һ�����L->next; 

	while (NULL != p) {

		if (ERROR == visit(p))

			return ERROR;

		p = p->next;

	}

	return OK;
}

Status visit_display_L(struct LNode * &L) {

	printf("%d ", L->data);

	return OK;

}



void CreateList_L(struct LNode * &L, int n) {
	//�㷨2.11
	//��λ������n��Ԫ�ص�ֵ,������ͷ���ĵ�����L
	struct LNode *p;
	L = (struct LNode*)malloc(LEN);

	L->next = NULL;//�Ƚ���һ����ͷ���ĵ�����
	for (int i = n; i > 0; --i) {
		p = (struct LNode*)malloc(LEN);
		scanf("%d", &p->data);
		p->next = L->next;
		L->next = p;
	}

}

void MergeList_L(struct LNode * &La, struct LNode * &Lb, struct LNode * &Lc) {
	//�㷨2.12
	//��֪���Ա�La��Lb�е�����Ԫ�ذ�ֵ�ǵݼ�����
	//�鲢La��Lb�õ��µ����Ա�Lc,Lc������Ԫ��Ҳ��ֵ�ǵݼ�����
	struct LNode *pa, *pb,*pc;
	pa = La->next;
	pb = Lb->next;
	pc = Lc = La;//��La��ͷ�����ΪLc��ͷ���
	while (pa&&pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}

		if (NULL == pa)
			pc->next = pb;
		else
			pc->next = pa;		//����ʣ���

		free(Lb);				//�ͷ�Lb��ͷ���
		Lb = NULL;
	}

}