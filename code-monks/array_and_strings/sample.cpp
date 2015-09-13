#include <stdio.h>
#include <iostream>

using namespace std;
int main( ) {
    int Arr[6] = {2,3,5,4,6,7};                      
     
    char A[3][2]={{'P','I'},{'O','M' },{'G','D'}} ;         

    // Accessing and printing the 3rd element of the first array.
    printf("The third element of Arr is\n ",Arr[2]);

   // Printing all the elements of Arr
   for (int i = 0; i < 6 ; i ++ )
       printf("%d ", Arr[i]);
   printf("\n");

   // Printing all the element of A[ ][ ] 
   printf("All the elements of 2D array A[ ][ ] are : \n");

   for( int i = 0 ; i < 3; i++ ) {
      for(int j= 0 ; j < 2 ; j++ ) {
            printf("%c ", A[i][j]);
   }
   printf("\n");
  }
  return 0;
}