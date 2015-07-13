#include <iostream>
#include <cstdio>
#include <process.h>
#include <iomanip>
using namespace std;
class Sample{
	private:
		int *px;
	public:
		Sample(){
			px=new int;
			*px=0;
		}
		Sample(int x){
			px = new int;
			*px=x;
		}
		Sample(Sample &obj){
			px=new int;
			
			*px=*(obj.px);
		}
		
		void set(int x){
			*px=x;
			
		}
		void display(){
			cout<<px;
			cout<<"value: "<<*px<<endl;
		}
		~Sample(){
		}
};

int main(){
	Sample s1(50);
	Sample s2(s1);
	s1.display();
	s2.display();
	s2.set(20);
	s1.display();
	s2.display();
	return 0;
}
