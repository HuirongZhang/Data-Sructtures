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
	Q.push(T);

	while (!Q.empty()) {
		p = Q.front();
		Q.pop();
		visit(p->data);
		if (p->lchild != NULL)
			Q.push(p->lchild);
		if (p->rchild != NULL)
			Q.push(p->rchild);
	
	}

	return OK;
}
/**

* �ǵݹ鷨ʵ���������������T

*/
Status PreOrderTraverse2(BiTree T, Status(*visit)(TElemType e)) {
	BiTree p = T;
	stack<BiTree> s;
	
	while (p || !s.empty()) {
		while (p) {
			visit(p->data);
			s.push(p);
			p = p->lchild;
		}
		if (!s.empty()) {
			p = s.top();
			s.pop();
			p = p->rchild;
		}
	}
	return OK;
}
/**

* �㷨6.2���ǵݹ鷨ʵ���������������T

*/
Status InOrderTraverse2(BiTree T, Status(*visit)(TElemType e)) {

	stack<BiTree> S;
	BiTree p;
	S.push(T);

	while (!S.empty()) {

		while(p==S.top()&&p) {

			S.push(p->lchild);
		
		}//if
			p = S.top();
			S.pop();
			if(!S.empty()){
				p = S.top();
				S.pop();
			if (!visit(p->data))	return ERROR;
				
			S.push(p=p->rchild);

			}//if

		}//while

	return OK;
}
/**

* �㷨6.3���ǵݹ鷨ʵ���������������T

*/
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
/**

* �ǵݹ鷨ʵ�ֺ������������T

*/
Status PostOrderTraverse2(BiTree T, Status(*visit)(TElemType e)) {
	stack<BiTree> s;
	BiTree p = T;
	int Tag[20];//��־ջ
	int t = 1;
	while (p || !s.empty()) {
		while (p) {//�����ߵ���ͷ
			s.push(p);
			p = p->lchild;
			Tag[t++] = 0;
		}

		while (!s.empty() && 1 == Tag[t - 1]) {
			p = s.top();
			s.pop();
			t--;
			if (ERROR == visit(p->data))
				return ERROR;
		}

		if (!s.empty()) {		//����־Ϊ0�����������������������־��Ϊ1
			Tag[t - 1] = 1;
			p = s.top();
			p = p->rchild;
		}
		else
			break;
	}
	return OK;
}
//Ҷ�ӽڵ����
int LeafNum(BiTree T) {

	int num1, num2;
	if (T== NULL)
		return 0;
	else if (T->lchild == NULL && T->rchild == NULL)
		return 1;
	else {
		num1 = LeafNum(T->lchild);
		num2 = LeafNum(T->rchild);
		return (num1 + num2);
	}

}
//����������
int DepthOfTree(BiTree T) {

	int lchilddep, rchilddep;
	if (T == NULL)
		return 0;
	else {
		lchilddep = DepthOfTree(T->lchild);
		rchilddep = DepthOfTree(T->rchild);
		return (lchilddep>rchilddep) ? (lchilddep + 1) : (rchilddep + 1);
	}

}
int	main() {
	BiTree T;
	CreateBiTree(T);

	printf("%d\n",LeafNum(T));
	printf("%d\n", DepthOfTree(T));

	PreOrderTraverse(T,display);
	printf("\n");

	InOrderTraverse(T, display);
	printf("\n");

	PostOrderTraverse(T, display);
	printf("\n");

	LevelOrderTraverse(T, display);
	printf("\n");

	PreOrderTraverse2(T, display);
	printf("\n");

	InOrderTraverse2(T, display);
	printf("\n");

	InOrderTraverse3(T, display);
	printf("\n");

	PostOrderTraverse2(T, display);

	return 0;
}