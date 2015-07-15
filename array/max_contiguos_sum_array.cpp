#include <iostream>
using namespace std;

int max_sum_subarray(int A[], int arr_size){
	int curr_max = A[0];
	int max_so_far=A[0];
	for(int i=1;i<=arr_size-1;i++){
		curr_max=max(A[i],curr_max+A[i]);
		max_so_far=max(max_so_far,curr_max);

	}
	return max_so_far;
}

int main(int argc, char const *argv[])
{
	/* code */
	int a[]={-2, -3, 4, -1, -2, 1, 5, -3};
	cout<<max_sum_subarray(a,8);
	return 0;
}