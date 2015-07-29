/* write a function strremove(char *source,char *remove)
this function will delete all the chars that exit in string remove from 
array source number of iteration should be only one*/

#include <iostream>
#include <bitset>
using namespace std;

void strRemove(char *source, char *remove)
{
	if ( !source || !remove )
		return;

	bitset<256> hash;

	while(*remove)
		hash.set(*remove++);

	int i = 0, j = 0;
	while(source[j])
	{
		if ( !hash.test(source[j]) )
			source[i++] = source[j];
		j++;
	}
	source[i] = '\0';
}

int main()
{
	char  str[] = "amazon development centre";
	char  remove[] = "aenr";
	strRemove(str,remove);
	cout<<str;
	return 0;}