#include <iostream>
using namespace std;

class Counter
{
    private:
        int count;
        const int incr;
    public:

        Counter():incr(1)
        {count=0; }
        Counter(int c,int in):incr(in)
        {count=c; }
        void set_count(int c){
            count=c;
        }
        int get_count(){
            return count;
        }
        void increment(){
            count+=incr;
        }
        void decrement(){
            count-=incr;
        }

};
int main(){
    Counter c1;
    Counter c2 (100,2);
    cout<<c1.get_count()<<" "<<c2.get_count()<<endl;
    c1.increment();
    c1.increment();
    c2.decrement();
    cout<<c1.get_count()<<" "<<c2.get_count()<<endl;
    return 0;



















}
