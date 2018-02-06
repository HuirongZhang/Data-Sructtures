
/**********************************
*                                 *
* �ļ���: LinkList.h               *
*                                 *
* ��  ��: ��������Ļ���������������    *
*                                 *
**********************************/

#include"Status.h"

#define LEN sizeof(struct LNode)

typedef  int ElemType;
typedef  int Status;

//------��ͷ���ĵ�����洢�ṹ-------//

struct LNode {

	ElemType data;

	struct LNode *next;

};


/*************��������****************/

void InitList_L(struct LNode * &L);

Status DestoryList_L(struct LNode * &L);

void ClearList_L(struct LNode * &L);

bool ListEmpty_L(struct LNode * &L);

int ListLength_L(struct LNode * &L);

Status GetElem_L(struct LNode * &L, int i, ElemType &e);

int LocateElem_L(struct LNode * &L, ElemType e);

Status PriorElem_L(struct LNode * &L, ElemType cur_e, ElemType &pre_e);

Status NextElem_L(struct LNode * &L, ElemType cur_e, ElemType &next_e);

Status ListInsert_L(struct LNode * &L, int i, ElemType e);

Status ListDelete_L(struct LNode * &L, int i, ElemType &e);

Status ListTraverse_L(struct LNode * &L, Status(*visit)(struct LNode * &));

Status visit_display_L(struct LNode * &L);



void CreateList_L(struct LNode * &L, int n);

void MergeList_L(struct LNode * &La, struct LNode * &Lb, struct LNode * &Lc);

/************************************/
