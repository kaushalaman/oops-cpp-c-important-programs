#include <iostream>
#include <iomanip>
#include <cstdio>
#include <process.h>
//shallow copy
using namespace std;

class Sample{
	int *px;
	public:
		Sample(int x){
			px=new int;
			*px=x;
		}
		void set(int x=0)
		{
			*px=x;
		}
		void display()
		{
			cout<<px<<" "<<*px<<endl;
		}
		~Sample(){
		}
};

int main(){
	int x = 10;
	Sample s1(x);
	s1.display();
	Sample s2 = s1;
	s2.set(20);
	s2.display();
	s1.display();
	return 0;
	
	
}
