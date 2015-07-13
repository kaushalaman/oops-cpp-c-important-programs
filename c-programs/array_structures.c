#include <stdio.h>
struct Point
{
    int x, y;
};

int main(){
    struct Point arr[10];

    arr[0].x=10;
    arr[0].y=12;

    printf("%d %d",arr[0].x,arr[0].y);
    return 0;
}


