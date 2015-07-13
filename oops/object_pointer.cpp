#include <iostream>
using namespace std;

class Distance
{
private:
	int feet;
	int inches;
public:
	Distance():feet(0),inches(0)
	{}
	Distance(int f, int i)
	{
		feet=f;
		inches=i;
	}

	void show()
	{
		cout<<"feet-"<<feet<<"inches-"<<inches<<endl;
	}
	~Distance(){}
};

int main()
{
	Distance d1(2,3);
	Distance *p;
	p=&d1;
	d1.show();
	p->show();
	return 0;
}