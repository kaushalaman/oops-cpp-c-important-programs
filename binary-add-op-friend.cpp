#include <iostream>
using namespace std;

class complex
{
	int x;int y;
public:
	complex():x(0),y(0)
	{}
	complex(int i,int j):x(i),y(j)
	{}
	friend complex operator+(complex c1,complex c2);
	void display();
};

void complex::display(){
	cout<<x<<"+i"<<y<<endl;
}

/*complex operator+(complex c1,complex c2){
	complex temp;
	temp.x=c1.x+c2.x;
	temp.y=c1.y+c2.y;
	return temp;
}*/

complex operator+(complex c1,complex c2){ //No name object method
	return complex(c1.x+c2.x,c1.y+c2.y);
}


int main(){
	complex c1(1,2),c2(2,3),c3;
	c3=c1+c2;
	c3.display();
	return 0;
}
