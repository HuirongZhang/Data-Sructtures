#include <iostream>
using namespace std;

void  swap(int &a,int &b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}

void bubblesort1A(int A[],int n){//�����㷨�汾1A:0<=n
	bool sorted =false;//���������־
	while(!sorted){
		sorted=true;//�ٶ��Ѿ�����
		for(int i=0;i<n;i++){
			if(A[i-1]>A[i]){
				swap(A[i-1],A[i]);
				sorted=false;
			}
		} 
		n--;//����Ԫ�ر�Ȼ��λ 
	} 
	
} 
int main(int argc, char** argv) {
	int A[7]={5,2,7,4,6,3,1};
	bubblesort1A(A,7);
	for(int i=0;i<7;i++){
		cout<<A[i]<<" ";
	}
	return 0;
}
