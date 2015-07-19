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

class B: private A  //class b is private derivation of class A so B inherits all public members of A as private members of B.now 
//in private part of B more functions will be included geta,getb,set
{
	int c;
public:
	int setab(int i, int j){
		set(i,j);//can't direct access set function from object because it is private in B.
	}
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
	b.setab(2,4);
	b.mul();
	b.display();
	return 0;
}