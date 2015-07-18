#include <iostream>
using namespace std;

int insertionsort(int A[],int arr_size)
{	int i,j,k;
	for(i=1;i<arr_size;i++){
		k=A[i];
		for(j=i-1;j>=0 && k<A[j];j--){
			A[j+1]=A[j];
		}
		A[j+1]=k;
	}
}

void display(int A[],int arr_size){
	cout<<"\n"<<"sorted list"<<endl;
	for(int i=0;i<=arr_size-1;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return;
}

int main(){
	int arr_size;
	cout<<"enter array size"<<"\t";
	cin>>arr_size;
	int a[arr_size];
	cout<<"enter elements of array by spacing space"<<endl;
	for(int i=0;i<=arr_size-1;i++){
		cin>>a[i];
	}
	insertionsort(a,arr_size);
	display(a,arr_size);
	return 0;
}
