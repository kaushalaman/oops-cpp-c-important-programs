#include <stdio.h>
int main()
{
 char *ptr = "geeksforgeeks";
 printf("%s\n", *&*&ptr);
  
 getchar();
 return 0;
}
