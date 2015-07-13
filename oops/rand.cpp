#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
int main(){
    int a,b,n,x,seed;

    cin>>n;
    a=0;
    b=4;
    srand(time(0));
    for(int i=0;i<n;i++){
        x=a+rand()%b;
        cout<<x<<endl;
    }
}
