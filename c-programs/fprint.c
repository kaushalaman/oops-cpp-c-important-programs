#include <stdio.h>

int main(){
    int i,n=5;
    char str[50];

    FILE *fptr = fopen("sample.txt","w");

    if(fptr == NULL){
        printf("could not open file\n");
        return 0;
    }
    for (i=0; i<n; i++){
        puts("Enter a name");
        gets(str);
        fprintf(fptr,"%d.%s\n",i,str);
    }
    fclose(fptr);
    return 0;
}
