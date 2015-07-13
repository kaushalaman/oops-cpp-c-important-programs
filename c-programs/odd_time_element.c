#include <stdio.h>

int main(){
    int arr[]={12,12,14,90,14,14,14};
    int i;
    int res=0;
    for(i = 0; i<(sizeof(arr)/sizeof(arr[0]));i++){
        res^=arr[i];
        printf("%d ",res);

    }
    printf("odd element is %d\n",res);
    return 0;
    
}
