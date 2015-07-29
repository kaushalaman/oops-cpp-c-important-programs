#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print_series(int start, int end){
	printf("%d",start);
	for(int i = start+1; i <= end ; i++){
		printf(",%d",i);
	}
}

void main(int argc, char** argv){
	printf("%s\n",argv[1]);

	char* arg = argv[1];
	int i =0;
	int num = 0;
	int start, end ;
	printf("\n");
	int substitute = 0;
	int dots = 0;
	for(; i<strlen(arg); i++){
		switch(*(arg+i)) {
			case '.':
				dots ++;
				if(dots == 1)
					start = num;
				num = 0;
				break;
			case ',':
				if(dots == 2){
					print_series(start, end);
					printf(",");
					dots = 0;
					num=0;
				} else {
					printf("%d,", num);
					num = 0;
				}
				break;
			default:
				num = num * 10 + (*(arg+i) - '0');
				if(dots == 2){
					end = num;
				}
		}
	}
	if(dots == 2){
		print_series(start, end);
	} else {
		printf("%d", num);
	}
	printf("\n");
}