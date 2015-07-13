#include <iostream>
#include <string.h>

using namespace std;
struct test{
    char str[50];
};
int main(){
    struct test st1,st2;
    strcpy(st1.str,"GeeksforGeeks");
    st2=st1;

    st1.str[0]='X';
    st1.str[1]='Y';

    cout<<st1.str<<endl;
    cout<<st2.str<<endl;

    return 0;

}

