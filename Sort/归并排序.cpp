#include <stdio.h>
#include <stdlib.h>
#define N 10

void Swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

const int maxn = 100;
//������A��[L1,R1]��[L2,R2]����ϲ�Ϊ��������(�˴�L2��ΪR1+1) 
void merge(int A[],int L1,int R1,int L2,int R2)
{
    int i=L1,j=L2;//iָ��A[L1],jָ��A[L2]
    int temp[maxn] , index=0;//temp��ʱ��źϲ��������,indexΪ���±�
    while(i<=R1&&j<=R2)
    {
        if(A[i]<=A[j])
        {
            temp[index++]=A[i++];
        }
        else
        {
            temp[index++]=A[j++];
        }
     } 
     while(i<=R1) temp[index++]=A[i++];
     while(j<R2)  temp[index++]=A[j++];
     for(i=0;i<index;i++)
     {
        A[L1+i]=temp[i];//���ϲ�������и�ֵ������A 
     }
 }
 /***********************�ݹ�ʵ��********************/ 
void mergeSort(int A[],int left,int right)//��array���鵱ǰ����[left,right]���й鲢���� 
 {
    if(left<right)
    {
        int mid=(left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid+1,right);
        merge(A,left,mid,mid+1,right);//������������ϲ� 
     } 
}
/******************�ǵݹ�*************************/
/*void mergesort(int A[])
{//stepΪ����Ԫ�ظ���,step/2Ϊ��������Ԫ�ظ���,ע��Ⱥſ��Բ�ȡ 
    for(int step=2;step/2<=N;step*=2)
    {//ÿstep��Ԫ��һ��,����ǰstep/2��step/2��Ԫ�ؽ��кϲ� 
        for(int i=1;i<=N;i+=step)//��ÿһ�� 
        {
            int mid=i+step/2-1;//��������Ԫ�ظ���Ϊstep/2
            if(mid+1<=N)  //���������Ԫ����ϲ� 
            {//��������Ϊ[i,mid],��������Ϊ[ mid+1 , min(i+step-1,N) ] 
                merge(A,i,mid,mid+1,min(i+step-1,N));
             } 
         } 
     } 
 } */  
int main()
 {
	int x, y;
	int A[N];
	
	for (x = 0; x<10; x++) 
	{
			y = rand() % 100;
			A[x] = y;
			printf("%3d\t", y);
		}
		printf("\n");
		mergeSort(A,0,9);
	//	mergesort(A);
		for(int i=0;i<N;i++)
		{
			printf("%d\t",A[i]); 
		}
		printf("\n"); 
		return 0;
	}
