#include <iostream>
using namespace std;

class Distance
{
private:
	int feet;
	float inches;
public:
	Distance():feet(0),inches(0.0) // default constructor
	{}
	Distance(int f, int inch):feet(f),inches(inch) // parametrized constructor
	{}

	void set(int f, int inch)
	{
		feet=f;
		inch=inches;
	}

	void show()
	{
		cout<<"feet: "<<feet<<" inches: "<<inches;
	}

	Distance add_dist(Distance);
	Distance sub_dist(Distance);

};

Distance Distance::add_dist(Distance d2)
{
	Distance temp;
	temp.inches=inches+d2.inches;
	temp.feet=feet+d2.feet;
	if(temp.inches>12.0)
	{
		temp.inches-=12;
		temp.feet+=1;
	}
	return temp;

}
Distance Distance::sub_dist(Distance d2)
{
	Distance temp;
	temp.inches=inches-d2.inches;
	temp.feet=feet-d2.feet;
	if(temp.inches<0.0)
	{
		temp.inches+=12;
		temp.feet-=1;
	}
	return temp;

}

int main()
{
	Distance d1(2,9);
	Distance d3(2,4);
	Distance d2;
	d2=d1.add_dist(d3);
	d2.show();

	return 0;
}