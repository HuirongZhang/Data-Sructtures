#include"tree.h"
#include"Status.h"
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<queue>
using namespace std;

Status CreateBiTree(BiTree &T) {
	/**

	* �㷨6.4��������˳���������

	*/

		char ch;

		scanf("%c", &ch);

		if (' ' == ch)

			T = NULL;

		else {

			T = (BiTNode *)malloc(sizeof(BiTNode));

			if (!T)

				return ERROR;

			T->data = ch;

			CreateBiTree(T->lchild);	//����������

			CreateBiTree(T->rchild);	//����������

		}

		return OK;
	
}

Status display(TElemType e) {

	printf("%c ", e);

	return OK;
}

/**

* �㷨6.1�������������������ÿ��Ԫ�ص��ú���viist

*/

Status PreOrderTraverse(BiTree T, Status(*visit)(TElemType e))

{

	if (T) {

		if (OK == visit(T->data))

			if (OK == PreOrderTraverse(T->lchild, visit))

				if (OK == PreOrderTraverse(T->rchild, visit))

					return OK;

		return ERROR;

	}
	else

		return OK;

}

/**

* �����������������ÿ��Ԫ�ص��ú���viist

*/

Status InOrderTraverse(BiTree T, Status(*visit)(TElemType e))

{

	if (T) {

		if (OK == InOrderTraverse(T->lchild, visit))

			if (OK == visit(T->data))

				if (OK == InOrderTraverse(T->rchild, visit))

					return OK;

		return ERROR;

	}
	else

		return OK;

}

/**

* �����������������ÿ��Ԫ�ص��ú���viist

*/

Status PostOrderTraverse(BiTree T, Status(*visit)(TElemType e))

{

	if (T) {

		if (OK == PostOrderTraverse(T->lchild, visit))

			if (OK == PostOrderTraverse(T->rchild, visit))

				if (OK == visit(T->data))

					return OK;

		return ERROR;

	}
	else

		return OK;

}
/**

* ������������������ö���ʵ��

*/
Status LevelOrderTraverse(BiTree T, Status(*visit)(TElemType e)) {
	BiTree p;
	queue<BiTree>Q;
	p = T;
	while(p||)
}
/**

* �㷨6.3���ǵݹ鷨ʵ���������������T

*/
Status PreOrderTraverse2(BiTree T, Status(*visit)(TElemType e)) {

}
/**

* �ǵݹ鷨ʵ�ֺ������������T

*/
Status InOrderTraverse2(BiTree T, Status(*visit)(TElemType e)) {

	stack<BiTree> S;
	BiTree p;

	S.push(T);

	while (!S.empty()) {

		while (p == S.top() && p) {

			S.push(p->lchild);
		}//while
			p = S.top();
			S.pop();

			if (!S.empty()) {

				p = S.top();
				S.pop();

				if (!visit(p->data))	return ERROR;
				
				S.push(p->rchild);

			}//if

		}//while

	return OK;
}

Status InOrderTraverse3(BiTree T, Status(*visit)(TElemType e)) {

	stack<BiTree> s;
	BiTree p =T;
	while (p || !s.empty()) {
		if (p) {
			s.push(p);
			p = p->lchild;
		}
		else {
			p = s.top();
			s.pop();
			if (!visit(p->data))	return ERROR;
			p = p->rchild;
		}//else
	}//while
	return OK;
}

Status PostOrderTraverse2(BiTree T, Status(*visit)(TElemType e));