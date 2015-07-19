#include <iostream>

using namespace std;

class alpha
{
	int x;
public:
	alpha(int i)
	{
		x=i;
		cout<<"alpha initialized"<<endl;
	}

	void show_x(void)
	{
		cout<<"x= "<<x<<endl;
	}
};

class beta
{
	int y;
public:
	beta(int i)
	{
		y=i;
		cout<<"beta initialized"<<endl;
	}

	void show_y(void)
	{
		cout<<"y= "<<y<<endl;
	}
};

class gamma:public beta,public alpha
{
	int m,n;
public:
	gamma(int a,int b,int c):alpha(a+b),beta(b),m(a*2),n(m)
	{
		cout<<"gamma initialized "<<endl;
	}

	void show_mn(void)
	{
		cout<<"m= "<<m<<endl;
		cout<<"n= "<<n<<endl;
	}
};

int main()
{
	gamma g(5,10,20);
	g.show_x();
	g.show_y();
	g.show_mn();
	return 0;
}