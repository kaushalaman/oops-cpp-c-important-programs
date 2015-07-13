#include <iostream>
using namespace std;
void repchar(char ch ='+',int n=40);
int main(){
    repchar();
    repchar('$');
    repchar('*',30);
    return 0;
}

void repchar(char ch, int n){
    for(int i=0;i<n;i++){
        cout<<ch;
    }
    cout<<endl;
}
