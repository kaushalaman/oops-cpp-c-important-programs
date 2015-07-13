#include <iostream>

using namespace std;

class Counter{

    private:
        int count;
    public:
        void initialize(int c=0){
            count=c;
        }
        void increment(){
            count++;
        }
        void decrement(){
            count--;
        }
        int get_count(){
            return count;
        }
};

int main(){
Counter c;
c.initialize();
c.increment();
c.increment();
c.increment();
cout<<c.get_count()<<endl;
c.decrement();
cout<<c.get_count()<<endl;
return 0;
}
