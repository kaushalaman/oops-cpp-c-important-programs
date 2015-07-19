#include <iostream>
using namespace std;

class complex
{
float x;
float y;
public:
	complex():x(0.0),y(0.0)
	{}
	complex(int i,int j)
	{
		x=i;
		y=j;
	}
	complex operator+(complex);
	friend void display(complex);

};
complex complex::operator+(complex c1){
	/*complex temp;
	temp.x=x+c1.x;
	temp.y=y+c1.y;
	return temp;*/
	return complex(x+c1.x,y+c1.y);
}

void display(complex c){
	cout<<c.x<<" + i"<<c.y<<endl;
}

int main(){
	complex c(1,2);
	complex d(2,3);
	complex e;
	e=c+d;
	display(e);
	return 0;

}
