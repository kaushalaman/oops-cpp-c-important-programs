#include <iostream>
using namespace std;

class Space{
private:
	int x;
	int y;
	int z;
public:
	void getdata(int i,int j, int k){
		x=i;y=j;z=k;
	}
	void display(){
		cout<<"x is: "<<x<<" y is: "<<y<<" z is: "<<z<<endl;
	}
	friend Space& operator-(Space &s);
	~Space(){}
};

Space& operator-(Space &s){
	s.x=-s.x;
	s.y=-s.y;
	s.z=-s.z;
	
}
int main(){
	Space s1, s2;
	s1.getdata(1,2,3);
	s2=-s1;
	s1.display();
	s2.display();
	return 0;
}