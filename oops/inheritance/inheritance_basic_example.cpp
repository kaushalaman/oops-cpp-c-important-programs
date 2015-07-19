#include <iostream>
using namespace std;

class A
{
	int a;
	int b;
public:
	A():a(0),b(0)
	{ }
	void set(int i, int j)
	{
		a=i;
		b=j;
	}

	int geta()
	{
		return a;
	}
	int getb()
	{
		return b;
	}

};

class B: public A //class b is public derivation of class A so B inherits all public members of A.now 
//in public part of B more functions will be included geta,getb,set
{
	int c;
public:
	int mul(){
		c=geta()*getb();
		return c;
	}

	void display(){
		cout<<"multiplication is "<<c<<endl;
	}
};

int main(){
	B b;
	b.set(2,4);
	b.mul();
	b.display();
	return 0;
}