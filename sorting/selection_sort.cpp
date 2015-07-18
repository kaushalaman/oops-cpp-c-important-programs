#include <iostream>
using namespace std;

int exchange(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int selectionsort(int A[], int arr_size){
	int smallest,index;
	for(int i=0;i<arr_size-1;i++){
		smallest=A[i];
		for(int j=i+1;j<arr_size;j++){
			if(smallest>A[j]){
				smallest=A[j];
				index=j;
			}
		}
		if(smallest!=A[i]){
			exchange(&A[i],&A[index]);
		}
	}
}

void display(int A[],int arr_size){
	cout<<"\n"<<"sorted list done"<<endl;
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
	cout<<"enter elements of array by entering space"<<endl;
	for(int i=0;i<=arr_size-1;i++){
		cin>>a[i];
	}
	selectionsort(a,arr_size);
	display(a,arr_size);
	return 0;
}
