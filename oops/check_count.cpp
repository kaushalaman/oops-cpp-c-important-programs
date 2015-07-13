#include <iostream>
using namespace std;

int count=0;

void increment(int& c){
    c=count;
    ++c;
}

int main(){
    increment(count);
    increment(count);
    cout<<count<<endl;
    return 0;
}
