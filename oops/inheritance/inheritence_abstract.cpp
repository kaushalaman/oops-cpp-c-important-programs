#include <iostream>
using namespace std;

class shape
{
protected:
	double width;
	double height;
public:
	virtual double area()=0;
	double setwidth(double i)
	{
		width=i;
	}
	double setheight(double i)
	{
		height=i;
	}
};

class rectangle:public shape
{
public:

	double area(){
		return width*height;
	}
};

class triangle:public shape{
public:
	double area(){
		return (width*height)/2;
	}
};

int main(){
	rectangle r;
	r.setheight(2);
	r.setwidth(4);
	cout<<r.area()<<endl;
	triangle t;
	t.setwidth(2);
	t.setheight(4);
	cout<<t.area()<<endl;
	return 0;
}