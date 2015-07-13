#include <stdio.h>

int main(){
    int arr[]={10,20,30,40};

    int *ptr = arr;

    printf("size of arr[] %d\n",sizeof(arr));
    printf("size of ptr %d\n",sizeof(ptr));
    printf("%d\n",ptr[2]);
    printf("%d\n",*(ptr+2));
    printf("%d\n",arr[2]);
    printf("%d\n",*(arr+2));
    getchar();
    return 0;

}
