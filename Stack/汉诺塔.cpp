#include <stdio.h>

int move_times = 0; 	// ȫ�ֱ����� �ᶯ����

// ��n��Բ�̴�����x �ᵽ����z
void move(char x, int n, char z)
{
	printf("��%i��: ��%i��Բ�̴�%c�Ƶ�%c\n", ++move_times, n, x, z);
}

// ������x�ϰ�ֱ����С���������϶��±��Ϊ1��n��n��Բ��
// ������ᵽ����z�ϣ�y��������������
void hanoi(int n, char x, char y, char z)
{
	// ����
	if (1 == n)
	{
		move(x, 1, z);
	}
	else
	{
		hanoi(n-1, x, z, y);	// ��x�ϱ��Ϊ1��n-1��Բ���ƶ�y�ϣ�z����������(���׵ݹ����)
		move(x, n, z);			// �����Ϊn��Բ����x�Ƶ�z��
		hanoi(n-1, y, x, z);	// ��y�ϱ��Ϊ1��n-1��Բ���ƶ�x�ϣ�x����������(���׵ݹ����)
	}
}

int main()
{
	int n;
	printf("3������Ϊx��y��z��Բ�������x�ϣ�����y���ƶ�z����������Բ������");
	scanf("%d", &n);
	hanoi(n, 'x', 'y', 'z');
	return 0;
}

