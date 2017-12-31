#include<stdio.h> 
using namespace std;

__int64 powerBF ( __int64 a, int n ) { //a^n�㷨�������棩��n >= 0
   __int64 pow = 1; //O(1)
   while ( 0 < n ) { //O(n)
      pow *= a; //O(1)
      n--; //O(1)
   }
   return pow; //O(1)
} //powerBF()

__int64 power ( __int64 a, int n ) { //a^n�㷨��n >= 0
   __int64 pow = 1; //O(1)
   __int64 p = a; //O(1)
   while ( 0 < n ) { //O(logn)
      if ( n & 1 ) //O(1)
         pow *= p; //O(1)
      n >>= 1; //O(1)
      p *= p; //O(1)
   }
   return pow; //O(1)
} //power()

__int64 power2BF_I ( int n ) { //�ݺ���2^n�㷨�����������棩��n >= 0 ���Ӷ�O(logN) 
   __int64 pow = 1; //O(1)���ۻ�����ʼ��Ϊ2^0
   while ( 0 < n -- ) //O(n)������n�֣�ÿ�ֶ�
      pow <<= 1; //O(1)�����ۻ�������
   return pow; //O(1)�������ۻ���
} //O(n) = O(2^r)��rΪ����ָ��n�ı���λ��

__int64 power2BF ( int n ) { //�ݺ���2^n�㷨�������ݹ�棩��n >= 0
   return ( 1 > n ) ? 1 : power2BF ( n - 1 ) << 1; //�ݹ�
} //O(n) = O(2^r)��rΪ����ָ��n�ı���λ��

__int64 power2_I ( int n ) { //�ݺ���2^n�㷨���Ż������棩��n >= 0
   __int64 pow = 1; //O(1)���ۻ�����ʼ��Ϊ2^0
   __int64 p = 2; //O(1)���۳����ʼ��Ϊ2
   while ( 0 < n ) { //O(logn)������log(n)�֣�ÿ�ֶ�
      if ( n & 1 ) //O(1)�����ݵ�ǰ����λ�Ƿ�Ϊ1�������Ƿ�
         pow *= p; //O(1)������ǰ�۳�������ۻ���
      n >>= 1; //O(1)��ָ������
      p *= p; //O(1)���۳����Գ�
   }
   return pow; //O(1)�������ۻ���
} //O(logn) = O(r)��rΪ����ָ��n�ı���λ��
 
 inline __int64 sqr ( __int64 a ) { return a * a; }
__int64 power2 ( int n ) { //�ݺ���2^n�㷨���Ż��ݹ�棩��n >= 0
   if ( 0 == n ) return 1; //�ݹ����������n����ż�ֱ�ݹ�
   return ( n & 1 ) ? sqr ( power2 ( n >> 1 ) ) << 1 : sqr ( power2 ( n >> 1 ) );
} //O(logn) = O(r)��rΪ����ָ��n�ı���λ��

int main() {
	__int64 a=2; int r=10; 
	printf ( "\n2 ^ %d  =  %I64d  =  %I64d\n\n", r, power2BF_I ( r ), power2_I ( r ) ); //������
   printf ( "\n2 ^ %d  =  %I64d  =  %I64d\n\n", r, power2BF ( r ), power2 ( r ) ); //�ݹ��
   printf ( "\n%I64d ^ %d  =  %I64d  =  %I64d\n\n", a, r, powerBF ( a, r ), power ( a, r ) ); //ͨ���㷨������
   return 0;
} 
