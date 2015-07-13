#include <stdio.h>

int main(){
    int a=3;int b=5;
    char buffer[50];
    sprintf(buffer,"a is %d and b is %d\n",a,b);
    printf("%s",buffer);
    getchar();
    return 0;
}
