#include <iostream>
using namespace std;

int find_majority(int A[],int arr_size){
	int count=0;
	int maj;
	for(int i=0;i<=arr_size-1;i++){
		if(count==0){
			maj=A[i];
			count+=1;
		}
		if(A[i]==maj){
			count++;
		}
		else{
			count--;
		}
	}
	count=0;
	for(int i=0;i<=arr_size-1;i++){
		if(A[i]==maj){
			count++;
		}
	}
	if(count>(arr_size/2)){
		cout<<"count of "<<maj<<" is "<<count<<endl;
		
	}
	else{
	return -1;}
}

int main(int argc, char const *argv[])
{
	/* code */
	int a[]={1,2,3,2,2,4,2};
	find_majority(a,7);
	return 0;
}





