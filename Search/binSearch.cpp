
// ���ֲ����㷨���汾A��������������������[lo, hi)�ڲ���Ԫ��e��0 <= lo <= hi <= _size
template <typename T> static Rank binSearch ( T* A, T const& e, Rank lo, Rank hi ) {
   /*DSA*/printf ( "BIN search (A)\n" );
   while ( lo < hi ) { //ÿ����������Ҫ�����αȽ��жϣ���������֧
      /*DSA*/ for ( int i = 0; i < lo; i++ ) printf ( "     " ); if ( lo >= 0 ) for ( int i = lo; i < hi; i++ ) printf ( "....^" ); printf ( "\n" );
      Rank mi = ( lo + hi ) >> 1; //���е�Ϊ���
      if      ( e < A[mi] ) hi = mi; //����ǰ���[lo, mi)��������
      else if ( A[mi] < e ) lo = mi + 1; //�������(mi, hi)��������
      else                return mi; //��mi������
      /*DSA*/ if ( lo >= hi ) { for ( int i = 0; i < mi; i++ ) printf ( "     " ); if ( mi >= 0 ) printf ( "....|\n" ); else printf ( "<<<<|\n" ); }
   } //�ɹ����ҿ�����ǰ��ֹ
   return -1; //����ʧ��
} //�ж������Ԫ��ʱ�����ܱ�֤����������ߣ�����ʧ��ʱ���򵥵ط���-1��������ָʾʧ�ܵ�λ��

// ���ֲ����㷨���汾B��������������������[lo, hi)�ڲ���Ԫ��e��0 <= lo <= hi <= _size
template <typename T> static Rank binSearch ( T* A, T const& e, Rank lo, Rank hi ) {
   /*DSA*/printf ( "BIN search (B)\n" );
   while ( 1 < hi - lo ) { //ÿ������������һ�αȽ��жϣ���������֧���ɹ����Ҳ�����ǰ��ֹ
      /*DSA*/ for ( int i = 0; i < lo; i++ ) printf ( "     " ); if ( lo >= 0 ) for ( int i = lo; i < hi; i++ ) printf ( "....^" ); printf ( "\n" );
      Rank mi = ( lo + hi ) >> 1; //���е�Ϊ���
      ( e < A[mi] ) ? hi = mi : lo = mi; //���ȽϺ�ȷ������[lo, mi)��[mi, hi)
   } //����ʱhi = lo + 1�������������һ��Ԫ��A[lo]
   /*DSA*/ for ( int i = 0; i < lo; i++ ) printf ( "     " ); if ( lo >= 0 ) printf ( "....|\n" ); else printf ( "<<<<|\n" );
   return ( e == A[lo] ) ? lo : -1 ; //���ҳɹ�ʱ���ض�Ӧ���ȣ�����ͳһ����-1
} //�ж������Ԫ��ʱ�����ܱ�֤����������ߣ�����ʧ��ʱ���򵥵ط���-1��������ָʾʧ�ܵ�λ��

// ���ֲ����㷨���汾C��������������������[lo, hi)�ڲ���Ԫ��e��0 <= lo <= hi <= _size
template <typename T> static Rank binSearch ( T* A, T const& e, Rank lo, Rank hi ) {
   /*DSA*/printf ( "BIN search (C)\n" );
   while ( lo < hi ) { //ÿ������������һ�αȽ��жϣ���������֧
      /*DSA*/ for ( int i = 0; i < lo; i++ ) printf ( "     " ); if ( lo >= 0 ) for ( int i = lo; i < hi; i++ ) printf ( "....^" ); printf ( "\n" );
      Rank mi = ( lo + hi ) >> 1; //���е�Ϊ���
      ( e < A[mi] ) ? hi = mi : lo = mi + 1; //���ȽϺ�ȷ������[lo, mi)��(mi, hi)
   } //�ɹ����Ҳ�����ǰ��ֹ
   /*DSA*/ for ( int i = 0; i < lo - 1; i++ ) printf ( "     " ); if ( lo > 0 ) printf ( "....|\n" ); else printf ( "<<<<|\n" );
   return --lo; //ѭ������ʱ��loΪ����e��Ԫ�ص���С�ȣ���lo - 1��������e��Ԫ�ص������
} //�ж������Ԫ��ʱ�����ܱ�֤����������ߣ�����ʧ��ʱ���ܹ�����ʧ�ܵ�λ��

// Fibonacci�����㷨���汾A��������������������[lo, hi)�ڲ���Ԫ��e��0 <= lo <= hi <= _size
template <typename T> static Rank fibSearch ( T* A, T const& e, Rank lo, Rank hi ) {
   /*DSA*/printf ( "FIB search (A)\n" );
   Fib fib ( hi - lo ); //��O(log_phi(n = hi - lo)ʱ�䴴��Fib����
   while ( lo < hi ) { //ÿ����������Ҫ�����αȽ��жϣ���������֧
      /*DSA*/ for ( int i = 0; i < lo; i++ ) printf ( "     " ); if ( lo >= 0 ) for ( int i = lo; i < hi; i++ ) printf ( "....^" ); else printf ( "<<<<|" ); printf ( "\n" );
      while ( hi - lo < fib.get() ) fib.prev(); //ͨ����ǰ˳����ң���̯O(1)����������������Σ�
      Rank mi = lo + fib.get() - 1; //ȷ������Fib(k) - 1�����
      if      ( e < A[mi] ) hi = mi; //����ǰ���[lo, mi)��������
      else if ( A[mi] < e ) lo = mi + 1; //�������(mi, hi)��������
      else                return mi; //��mi������
      /*DSA*/ if ( lo >= hi ) { for ( int i = 0; i < mi; i++ ) printf ( "     " ); if ( mi >= 0 ) printf ( "....|\n" ); else printf ( "<<<<|\n" ); }
   } //�ɹ����ҿ�����ǰ��ֹ
   return -1; //����ʧ��
} //�ж������Ԫ��ʱ�����ܱ�֤����������ߣ�ʧ��ʱ���򵥵ط���-1��������ָʾʧ�ܵ�λ��

// Fibonacci�����㷨���汾B��������������������[lo, hi)�ڲ���Ԫ��e��0 <= lo <= hi <= _size
template <typename T> static Rank fibSearch ( T* A, T const& e, Rank lo, Rank hi ) {
   /*DSA*/printf ( "FIB search (B)\n" );
   Fib fib ( hi - lo ); //��O(log_phi(n = hi - lo)ʱ�䴴��Fib����
   while ( lo < hi ) { //ÿ������������һ�αȽ��жϣ���������֧
      /*DSA*/ for ( int i = 0; i < lo; i++ ) printf ( "     " ); if ( lo >= 0 ) for ( int i = lo; i < hi; i++ ) printf ( "....^" ); else printf ( "<<<<|" ); printf ( "\n" );
      while ( hi - lo < fib.get() ) fib.prev(); //ͨ����ǰ˳����ң���̯O(1)����������������Σ�
      Rank mi = lo + fib.get() - 1; //ȷ������Fib(k) - 1�����
      ( e < A[mi] ) ? hi = mi : lo = mi + 1; //�ȽϺ�ȷ������ǰ���[lo, mi)�����(mi, hi)
   } //�ɹ����Ҳ�����ǰ��ֹ
   /*DSA*/ for ( int i = 0; i < lo - 1; i++ ) printf ( "     " ); if ( lo > 0 ) printf ( "....|\n" ); else printf ( "<<<<|\n" );
   return --lo; //ѭ������ʱ��loΪ����e��Ԫ�ص���С�ȣ���lo - 1��������e��Ԫ�ص������
} //�ж������Ԫ��ʱ�����ܱ�֤������������ߣ�����ʧ��ʱ���ܹ�����ʧ�ܵ�λ��
