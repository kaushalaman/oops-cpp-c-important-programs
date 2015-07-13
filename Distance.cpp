#include <iostream>
using namespace std;
class Distance
{
private:
	int feet;
	float inches;
public:
	Distance():feet(0),inches(0.0)
	{ }
	Distance(int f,float in):feet(f),inches(in)
	{ }
	void set_dist(int f,float in){
		feet=f;
		inches=in;
	}

	void get_dist(){
		cout<<"feet - ";
		cin>>feet;
		cout<<"inches - ";
		cin>>inches;
	}

	void show_dist(){
		cout<<"feet: "<<feet<<" inches: "<<inches<<endl;
	}

	void add_distance(Distance,Distance);
	void sub_distance(Distance,Distance);

	~Distance(){
	}

};
void Distance::add_distance(Distance d2,Distance d3){
	feet=d2.feet+d3.feet;
	inches=d2.inches+d3.inches;
	if(inches>12.0){
		inches-=12;
		feet+=1;
	}
}

void Distance::sub_distance(Distance d2, Distance d3){
    feet=d2.feet-d3.feet;
	inches=d2.inches-d3.inches;
	if(inches<0.0){
		inches+=12;
		feet-=1;
	}
}

int main(){
	Distance d1;
    Distance d2(4,6);
    Distance d3(2,7);
    /*cout<<"add_distance"<<endl;
	d1.add_distance(d2,d3);

	d1.show_dist();
	cout<<"sub_distance"<<endl;
	d1.sub_distance(d2,d3);
	d1.show_dist();
	cout<<"get_dist"<<endl;
	d1.get_dist();
	d1.show_dist();*/
	d2.show_dist();
	d3.show_dist();
	return 0;
}


