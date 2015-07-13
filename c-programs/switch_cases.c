#include <stdio.h>

int main(){
    int x = 2;
    switch(x)
    {
        case 1: printf("1");
                break;
        case 2: printf("2");
                break;
        case 3: printf("3");
                break;
        default: printf("other");
                 break;
    }
    return 0;
}
