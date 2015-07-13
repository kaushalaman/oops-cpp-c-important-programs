#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *str1,char *str2){
    char *temp = (char *)malloc((strlen(str1)+1)*sizeof(char));
    strcpy(temp,str1);
    strcpy(str1,str2);
    strcpy(str2,temp);
    free(temp);

}

int main(){
    char str1[10] = "geeks";
    char str2[10] = "forgeeks";
    swap(str1,str2);
    printf("%s, %s",str1,str2);
    getchar();
    return 0;

}
