#include <iostream>
using namespace std;
void quicksort(int *,int,int);
int hasArrayTwoCandidates(int A[],int arr_size, int sum)
{
	quicksort(A,0,arr_size-1);
	int i=0;
	int j=arr_size-1;
	while(i<j){
		if(A[i]+A[j]<sum){
			i++;
		}
		else if(A[i]+A[j]==sum){
			return 1;
		}
		else{
			j--;
		}
	}
	return 0;

}

int main(int argc, char const *argv[])
{
	/* code */
	int A[]={1,4,45,6,10,-8};
	int n=16;
	int arr_size=6;
	if(hasArrayTwoCandidates(A,arr_size,n)){
		cout<<"Array has two elements with sum 16"<<endl;
	}
	else
		cout<<"no such elements"<<endl;
	return 0;
}

void exchange(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int A[],int si, int ei){
	int x=A[ei];
	int i=si-1;
	int j;
	for(j=si;j<=ei-1;j++){
			if(A[j]<=x){
				i++;
				exchange(&A[i],&A[j]);
			}
	}
	exchange(&A[i+1],&A[ei]);
	return(i+1);
}

void quicksort(int A[],int si, int ei){
	int pi;
	if(si<ei)
	{
		pi=partition(A,si,ei);
		quicksort(A,si,pi-1);
		quicksort(A,pi+1,ei);
	}
}