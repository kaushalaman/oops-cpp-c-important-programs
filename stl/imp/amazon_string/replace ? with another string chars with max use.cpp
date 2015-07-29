/*you are given two strings lets say S which consist Upper cae
alphabets and ? character only and p. You are required to eplace 
? with some alphabet so that resulting string have maximum number of p*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main() {
    char s[] = "ABAAMA????MAZON????????";
    char t[] = "AMAZON";

    int j = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == t[j]) {
            j++;
            j = j % strlen(t);
        }
        if (s[i] == '?') {
            s[i] = t[j++];
            j = j % strlen(t);
        }
    }

    cout << s;
    
    /* It Prints -- "ABAAMAZONAMAZONAMAZONAM"
     */

}