/*
����ջ������׺���ʽ��ת���ɣ�ǰ׺���ʽ��
e.g.
1+2*3+(4*5+6)*7 ת���� ++1*23*+*4567

infix����׺���ʽ�� : 1+2*3+(4*5+6)*7
prefix��ǰ׺���ʽ�� : ++1*23*+*4567
*/
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;

void InfixToPrefix(const string infix, string& prefix)
{
	stack<char> mark;                           // ����ջ

	map<char, int> priority;                    // �������ȼ�
	priority['+'] = 0;
	priority['-'] = 0;
	priority['*'] = 1;
	priority['/'] = 1;

	int infix_length = infix.size();            // ��׺���ʽ���ַ�����
	prefix.reserve(infix_length);               // ���Ч��
	for (int i = infix_length - 1; i >= 0; --i) {
		switch (infix[i]) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			prefix.push_back(infix[i]);
			break;
		case '+':
		case '-':
		case '*':
		case '/':
			if (!mark.empty()) {
				char markTop = mark.top();
				// ע��˴�������׺ת��׺������ͬ
				while (markTop != ')' && priority[infix[i]] < priority[markTop]) {
					prefix.push_back(markTop);
					mark.pop();
					if (mark.empty()) {
						break;
					}
					markTop = mark.top();
				}
			}
			mark.push(infix[i]);
			break;
		case ')':
			mark.push(infix[i]);
			break;
		case '(':
		{
			char markTop = mark.top();
			while (markTop != ')') {
				prefix.push_back(markTop);
				mark.pop();
				markTop = mark.top();
			}
			mark.pop();
		}
		break;
		}
	}
	// ʣ���ȫ����ջ
	while (!mark.empty()) {
		prefix.push_back(mark.top());
		mark.pop();
	}
	reverse(prefix.begin(), prefix.end());
}

int main(int argc, char const *argv[])
{
	std::string infix = "1+2*3+(4*5+6)*7";
	std::string prefix;

	cout << "infix : " << infix << endl;
	InfixToPrefix(infix, prefix);
	cout << "prefix : " << prefix << endl;

	return 0;
}