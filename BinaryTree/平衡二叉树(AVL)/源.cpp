#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct node {

	int v, height;//vΪ���Ȩֵ,heightΪ��ǰ�����ĸ߶�
	node *lchild, *rchild;
};

node* newNode(int v) {

	node* Node = new node;
	Node->v = v;
	Node->height = 1;
	Node->lchild = Node->rchild = NULL;
	return Node;
}

int getHeight(node* root) {

	if (root == NULL)	return 0;
	return root->height;

}

int getBanlanceFactor(node* root) {

	return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(node* root) {
	//max(���ӵ�height,�Һ��ӵ�height)+1
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

void search(node* root, int x) {

	if (root == NULL) {
		printf("serach failed\n");
		return;
	}

	if (x == root->v) {
		printf("%d\n", root->v);
	}
	else if (x < root->v) {
		search(root->lchild, x);
	}
	else {
		search(root->rchild, x);
	}
}

//����
void L(node* &root) {

	node* temp = root->rchild;//rootָ��ڵ�A,tempָ����B
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;

}

//����
void R(node* &root) {

	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;

}
//����ȨֵΪv�Ľ��
void insert(node* &root, int v) {

	if (root == NULL) {
		root = newNode(v);
		return;
	}

	if (v < root->v) {//v�ȸ��ڵ��ȨֵС
		insert(root->lchild, v);
		updateHeight(root);
		if (getBanlanceFactor(root) == 2) {
			if (getBanlanceFactor(root->lchild) == 1) {//LL��
				R(root);
			}
			else if (getBanlanceFactor(root->lchild) == -1) {//LR��
				L(root->lchild);
				R(root);
			}
		}
	}
	else {//v�ȸ��ڵ��Ȩֵ��
		insert(root->rchild, v);
		updateHeight(root);
		if (getBanlanceFactor(root) == 2) {
			if (getBanlanceFactor(root->rchild) == -1) {//RR��
				L(root);
			}
			else if (getBanlanceFactor(root->rchild) == 1) {//LL��
				R(root->rchild);
				L(root);
			}
		}

	}
}

node *Create(int data[], int n) {
	node* root = NULL;
	for (int i = 0; i < n; i++) {
		insert(root, data[i]);
	}

	return root;
}

int main() {
	int n;
	int data[10];

	node* root = NULL;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);

	}

	
}
