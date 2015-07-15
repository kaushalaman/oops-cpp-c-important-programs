#include <iostream>
using namespace std;

int element_of_odd_occurance(int A[],int arr_size){
	int res=0;
	for(int i=0;i<=arr_size-1;i++){
		res=res^A[i];
	}
	return res;
}

int main(){
	int a[]={1,2,3,2,3,1,1,1,4};
	cout<<element_of_odd_occurance(a,9)<<endl;;
	return 0;
}
