#include <stdio.h>
int fun(int ptr[])
{
    int x = 10;
    printf("size of ptr = %d\n",sizeof(ptr));
    ptr = &x;
    printf("*ptr = %d",*ptr);
    return 0;
    
}

int main(){
    int arr[]={10,20,30,40};
    fun(arr);
    return 0;

}
