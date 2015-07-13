#include <stdio.h>
#include <inttypes.h>
int main(int argc, char const *argv[])
{
	/* code */
	register int i=5;
	int *ptr =&i;
	printf("%p\n",ptr );
	printf("%d\n", *ptr);
	printf("0x%" PRIXPTR "\n", (uintptr_t)ptr);
	return 0;
}