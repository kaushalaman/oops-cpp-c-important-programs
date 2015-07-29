#include <iostream> 
#include <cstring> 
#include <cstdlib> 

void reverse (char * string, char * newstring) { 
	char * oldstring = new char (strlen(string));
	strcpy (oldstring, string);
	char * token = strtok (oldstring, "%20");
	while (token !=NULL) { 
		strcat(newstring, token); 
		strcat(newstring," ");
		token = strtok(NULL, "%20");		
	}
}

int main (int argc, char * * argv) {
	char string [] = "This%20is%20a20%string";
	int size = strlen (string);
	//printf ("size:%u\n", size);
	char * newstring = new char (size);
	reverse (string, newstring);
	printf ("Original string: %s\n", string); 
	printf ("New string: %s\n", newstring);
}

