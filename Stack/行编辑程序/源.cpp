#include<stdio.h>
#include<stack>
using namespace std;

void LineEdit() {
	//�����ַ�ջS,���ն˽���һ�в����������ù��̵�������
	stack<char> S;
	char ch = getchar();//���ն˽��յ�һ���ַ�
	while (ch != EOF) {//EOFΪȫ�Ľ�����
		while (ch != EOF&&ch != '\N') {
			switch (ch) {
			case '#':S.pop();	break;
			case '@':S.emplace();	break;
			default: S.push(ch);
			}
			ch = getchar();//���ն˽�����һ���ַ�
		}
		//����ջ�׵�ջ����ջ���ַ����������ù��̵�������
		S.emplace();

		if (ch != EOF)	ch = getchar();
	}
	
}

int main() {
	LineEdit();
	return 0;
}
