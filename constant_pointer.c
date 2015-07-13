#include <stdio.h>

int main(){
	const int i=20;
	int j=200;
	int *ptr=&j;
	printf("%d\n",*ptr );
	*ptr = &i;
	/* i=30; */
	
	printf("%d\n",*ptr);
	ptr = &j;
	printf("%d\n",*ptr);

	return 0;

}