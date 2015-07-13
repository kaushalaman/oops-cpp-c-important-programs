#include <stdio.h>

int main(){
    int arr[5], i;
    for(i = 0; i<5;i++ ){
        printf("Address :%u\n",&arr[i]);
    }
    return 0;
}
