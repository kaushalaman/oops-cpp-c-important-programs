#include <stdio.h>

int main(){
    char *str;
    int size = 4;
    str = (char *)malloc(sizeof(char)*size);
    *(str+0)='G';
    *(str + 1 )='f';
    *(str+2)='G';
    *(str+3)='\0';
    printf("%s",str);
    return 0;
}
