#include <iostream>
using namespace std;

int exchange(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int bubblesort(int A[], int arr_size){
	int i,n=arr_size;int count;
	for(i=1;i<=arr_size-1;i++){
		count=0;
		for(int j=0;j<n-1;j++){
			if(A[j]>A[j+1]){
				exchange(&A[j],&A[j+1]);
				count++;
			}
		}
		if(count == 0){
			break;
		}
		n=n-1;
	}
	return i;
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
	cout<<"no of passes are "<<bubblesort(a,arr_size)<<endl;
	display(a,arr_size);
	return 0;
}

