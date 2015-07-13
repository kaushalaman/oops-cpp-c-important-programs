#include <stdio.h>

int init(void){
	return 50;
}
int main(int argc, char const *argv[])
{
	/* code */
	static int i = 50;
	printf("%d\n",i );
	return 0;
}
