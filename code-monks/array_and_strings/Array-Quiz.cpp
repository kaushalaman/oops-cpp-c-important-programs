/* Time for a surprise quiz on array? Great. 
Here it is. Let’s say that you have an array: A[ 6 ] = {2, 5, 6, 4, 7, 9} and 
you have to find the sum of elements between index 2 to 4. How will you do that ? */

#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int A[6]={2, 5, 6, 4, 7, 9};
	int sum=0;
	for(int i=2;i<=4;i++)
		sum+=A[i];
	printf("%d\n",sum);
	return 0;
}