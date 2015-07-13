#include <stdio.h>

int main(){
char a[100];
gets(a);
printf("%s\n",a);
fgets(a,100,stdin);
printf("%s\n",a);
getchar();
return 0;
}
