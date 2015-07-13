#include <stdio.h>

int main(){
    char arr[] = "geeks";
    printf("%ld\n",sizeof(arr));
    char a[5]="geeks";
    printf("%ld\n",sizeof(a));
    char a_new[5]={'g','e','e','k','s'};
    printf("%ld\n",sizeof(a));

    return 0;
}
