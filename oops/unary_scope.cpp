#include <iostream>
using namespace std;
int x=10;
int main()
{
    for(int i=0;i<5;i++){
        static int x=20;
        cout<<"inner "<<x<<endl;
        cout<<"outer "<<::x<<endl;
        ++x;
        ++(::x);
    }
    return 0;
}
