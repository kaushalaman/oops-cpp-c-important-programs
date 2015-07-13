#include <stdio.h>
int f1(void){
    int  x=5;
    return x;
}
int f2(void){
    int x=10;
    return x;
}
int main(){
    int i;
    i=f1()+f2();
    printf("%d\n",i);
    return 0;
}
