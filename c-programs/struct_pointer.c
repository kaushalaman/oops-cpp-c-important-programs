#include <stdio.h>
#include <stdlib.h>
struct Point
{
    int x, y;
};

int main()
{
    
    struct Point* p1=malloc(sizeof*p1);
    p1->x=1;
    p1->y=2;   
    
    printf("%d %d\n",p1->x,p1->y);
    return 0;
}
