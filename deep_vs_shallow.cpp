#include <iostream>
#include <string.h>

using namespace std;

struct test
{
    char *str;
};

int main(){
    struct test st1, st2;
    st1.str = new char[20];
    strcpy(st1.str,"GeeksforGeeks");
    st2=st1;

    st1.str[0]='X';
    st2.str[1]='Y';

    cout <<st1.str<<endl;
    cout<< st2.str<<endl;

    return 0;

}



