#include<iostream>
#include<stack>
using namespace std;

void conversion() {
	//��������һ���Ǹ�ʮ��������,��ӡ��������ֵ�İ˽�����
	stack<int> S;//�����ջ

	int N;

	cin >> N;

	while (N) {
		S.push(N % 8);
		N = N / 8;
	}

	while (!S.empty()) {
		int e = S.top();
		cout << e;
		S.pop();
	}

}

int main() {
	conversion();
	return 0;
}