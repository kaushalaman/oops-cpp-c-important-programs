#include <stdio.h>
void foo();
int main()
{
   foo();
   getchar();
   return 0;
}
void foo()
{
   printf("foo called");
}
