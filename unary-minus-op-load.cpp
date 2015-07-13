#include <iostream>
using namespace std;

class Space
{
int x;int y; int z;

public:
	void getData(int i, int j, int k){
		x=i;y=j;z=k;
	}

	void display(){
		cout<<"x is= "<<x<<" y is: "<<y<<" z is: "<<z<<endl;
	}

	Space operator-(){
		x=-x;
		y=-y;
		z=-z;
		Space temp;
		temp.x=x;temp.y=y;temp.z=z;
		return temp;
	}

	~Space(){


	}
};

int main(){
	Space s1,s2;
	s1.getData(1,2,3);
	s1.display();
	s2=-s1;
	s2.display();
	s1.display();
	return 0;}