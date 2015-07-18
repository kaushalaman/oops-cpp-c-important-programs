#include <iostream>
using namespace std;

int exchange(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int selectionsort(int A[], int arr_size){
	int i, smallest,index;
	for(i=0;i<arr_size-1;i++){
		if(A[i]<= A[i+1]){
			if(i+1==arr_size-1){
				return 1;
			}
			continue;
		}
		else{
			break;
		}
		
	}
	for(i=0;i<arr_size-1;i++){
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
	return i+1;
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
	cout<<"no of passes are "<<selectionsort(a,arr_size)<<endl;
	display(a,arr_size);
	return 0;
}