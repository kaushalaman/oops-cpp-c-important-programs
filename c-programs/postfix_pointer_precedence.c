#include <stdio.h>

int main(){
    char arr[] = "geeksforgeeks";
    char *p = arr;
    *p++;
    printf("%c",*p);
    return 0;

}
