#include <iostream>
#define MAX 100000
using namespace std;

int printpairs(int A[],int arr_size,int sum){

	int bitmap[MAX]={0};
	int temp;
	for(int i=0;i<=arr_size-1;i++){
		temp=sum-A[i];
		if(temp>0 && bitmap[temp]==1){
			cout<<"Two elements are "<<temp<<" and "<<A[i]<<endl;
		}
		bitmap[A[i]]=1;
	}
}

int main(){
	int A[]={1, 4, 45, 6, 10, 8,2};
	int arr_size=7;
	int sum=10;
	printpairs(A,arr_size,sum);
	return 0;
}