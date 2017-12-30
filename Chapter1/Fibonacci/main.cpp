#include "Fib.h"
#include<stdio.h>

__int64 fibI ( int n ) { //����Fibonacci���еĵ�n������棩��O(n)
   __int64 f = 1, g = 0; //��ʼ����fib(-1)��fib(0)
   while ( 0 < n-- ) { g += f; f = g - f; } //����ԭʼ���壬ͨ��n�μӷ��ͼ�������fib(n)
   return g; //����
}

__int64 fib ( int n ) { //����Fibonacci���еĵ�n����ֵݹ�棩��O(2^n)
   return ( 2 > n ) ?
          ( __int64 ) n //������ݹ����ֱ��ȡֵ
          : fib ( n - 1 ) + fib ( n - 2 ); //���򣬵ݹ����ǰ�����ͼ�Ϊ����
}

__int64 fib ( int n, __int64& prev ) { //����Fibonacci���е�n����Եݹ�棩�������ʽfib(n, prev)
   if ( 0 == n ) //������ݹ������
      { prev = 1; return 0; } //ֱ��ȡֵ��fib(-1) = 1, fib(0) = 0
   else { //����
      __int64 prevPrev; prev = fib ( n - 1, prevPrev ); //�ݹ����ǰ����
      return prevPrev + prev; //��ͼ�Ϊ����
   }
} //�ø���������¼ǰһ��������еĵ�ǰ�O(n)

int main(){
	int n=24;
	Fib f ( 0 );
   for ( int i = 0; i < n; i++, f.next() )
      printf ( "fib(%2d) = %d\n", i, f.get() );
   for ( int i = 0; i <= n; i++, f.prev() )
      printf ( "fib(%2d) = %d\n", n - i, f.get() );
   printf ( "\n------------- Iteration -------------\n" );
   for ( int i = 0; i < n; i++ )
      printf ( "fib(%2d) = %22I64d\n", i, fibI ( i ) );
   printf ( "\n------------- Linear Recursion -------------\n" );
   for ( int i = 0; i < n; i++ ) {
      __int64 f;
      printf ( "fib(%2d) = %22I64d\n", i, fib ( i, f ) );
   }
   printf ( "\n------------- Binary Recursion -------------\n" );
   for ( int i = 0; i < n; i++ )
      printf ( "fib(%2d) = %22I64d\n", i, fib ( i ) );
   return 0;
}

