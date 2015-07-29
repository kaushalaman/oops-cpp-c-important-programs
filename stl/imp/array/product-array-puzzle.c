#include<stdio.h>
#include<stdlib.h>

/* Function to print product array for a given array
 arr[] of size n */
void productArray(int arr[], int n)
{
  int i, temp = 1;
 
  /* Allocate memory for the product array */
  int *prod = (int *)malloc(sizeof(int)*n);
 
  /* Initialize the product array as 1 */
  memset(prod, 1, n);
 
  /* In this loop, temp variable contains product of
    elements on left side excluding arr[i] */
  for(i=0; i<n; i++)
  {
    prod[i] = temp;
    temp *= arr[i];
  }
 
  /* Initialize temp to 1 for product on right side */
  temp = 1;
 
  /* In this loop, temp variable contains product of
    elements on right side excluding arr[i] */
  for(i= n-1; i>=0; i--)
  {
    prod[i] *= temp;
    temp *= arr[i];
  }
 
  /* print the constructed prod array */
  for (i=0; i<n; i++)
    printf("%d ", prod[i]);
 
  return;
}

/* Driver program to test above functions */
int main()
{
  int arr[] = {10, 3, 5, 6, 2};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("The product array is: \n");
  productArray(arr, n);
  getchar();
}
