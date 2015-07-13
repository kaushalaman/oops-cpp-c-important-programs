#include <stdio.h>
 
int main()
{
     char a = 0xfb;
     unsigned char b = 0xfb;
             
     printf("a = %c", a);
     printf("\nb = %c", b);
                     
     if (a == b)
            printf("\nSame");
     else
            printf("\nNot Same");
     return 0;
}
