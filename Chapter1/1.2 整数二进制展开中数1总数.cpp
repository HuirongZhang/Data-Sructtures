#include<iostream>
using namespace std;

int countOnes(unsigned int n){//ͳ������������չ������Ϊ1������: ���Ӷ�:O(logN)
	int ones=0;//����λ��λ
	while(n>0){
		ones+=(1&n);//������λ,��Ϊ1�����
		n>>=1;//����1λ 
	} 
	return ones; 
	
}
int main(){
	cout<<countOnes(441)<<endl;
	return 0;
}
