
/**********************************
*                                *
* �ļ���: SquenceList.h           *
*                                *
* ��  ��: ���Ա�Ļ���������������    *
*                                *
**********************************/
#include"Status.h"

typedef  int ElemType;
typedef  int Status;

//------���Ա�Ķ�̬����洢�ṹ-------//
#define LIST_INT_SIZE  100  //���Ա�Ĵ洢�ռ�ĳ�ʼ������
#define LISTINCREMENT  10   //���Ա�洢�ռ�ķ�������

typedef struct  {
	ElemType *elem; //�洢�ռ��ַ
	int length;     //��ǰ����
	int listsize;   //��ǰ����洢����(sizeof(ElemType)Ϊ��λ)
}SqList;

/*************��������****************/

Status InitList(SqList &L);

Status DestoryList(SqList &L);

Status ClearList(SqList &L);

bool ListEmpty(SqList L);

int ListLength(SqList L);

ElemType GetElem(SqList L, int i, ElemType &e );

int LocateElem(SqList L, ElemType e);

ElemType PriorElem(SqList L, ElemType current_e, ElemType &pre_e);

ElemType NextElem(SqList L, ElemType current_e, ElemType &next_e);

Status ListInsert(SqList &L, int i, ElemType e);

ElemType ListDelete(SqList &L, int i, ElemType &e);

Status ListTraverse(SqList L);

void Union(SqList &La, SqList Lb);

void MergeList(SqList La, SqList Lb, SqList &Lc);

/************************************/

