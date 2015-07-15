#include <iostream>
using namespace std;
int distinctelements(int A[],int arr_size){
	int i,j;
 	for(i=0;i<=arr_size-1;i++){
 		
 		for(j=0;j<i;j++){
 			
 			if(A[j]==A[i]){
 				break;
 			}
 		}

 		if(i==j){
 			cout<<A[i]<<" ";
 		}
 	}
 	cout<<endl;
 }
 

 int main(){
 	int a[]={1,3,4,4,5,2,3};
 	distinctelements(a,7);
 	return 0;
 }