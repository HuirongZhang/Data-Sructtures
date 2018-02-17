#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool IsValid(char *expr) {
	//����ƥ��ļ���, ƥ�䷵��TRUE����ƥ�䷵��FALSE
	//��-1��ʾ (		-2��ʾ[		-3��ʾ{
	int i = 0;

	stack <int> S;

	int e=0;

	while ('\0' != *(expr + i)) {

		switch (*(expr + i)) {

		case '(':

			S.push(-1);

			break;

		case '[':

			S.push(-2);

			break;

		case '{':

			S.push(-3);

			break;

		case ')':

			if (! S.empty() ){		//ջ�ǿգ��õ�ջ��Ԫ��

				e = S.top();

				if (-1 == e) {		//ջ��Ԫ���롮����ƥ��

					S.pop();		// ɾ��ջ��Ԫ��
				}

				else				// ��ƥ�䣬����ERROR

					return false;

			}
			else

				return false;

			break;

		case ']':

			if (!S.empty()) {

				e = S.top();

				if (-2 == e) {

					S.pop();
				}

				else

					return false;
			}
			else

				return false;

			break;

		case '}':

			if (!S.empty()) {

				e = S.top();

				if (-3 == e)

					S.pop();

				else

					return false;

			}
			else

				return false;

			break;

		default:

			break;//�������ַ�һ�ɺ���

		} //switch



		i++;

	} // while



	if (S.empty())

		return true;

	else

		return false;
}

int main() {
	char bracket[100];
	char *s = &bracket[0];
	cin >> bracket;
	string str= IsValid(s) == 1 ? "ƥ����ȷ" : "ƥ��ʧ��";
	cout << str << endl;
	return 0;
}