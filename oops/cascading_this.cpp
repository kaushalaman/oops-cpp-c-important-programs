#include <iostream>
#include <iomanip>
using namespace std;

class Cascade
{
	private:
		int x;
		int y;
		int z;
	public:
		Cascade():x(0),y(0),z(0)
		{
		}
		Cascade(int xx,int yy,int zz){
			x=xx;y=yy;z=zz;
		}
		Cascade &setx(int xx){
			x=xx;
			return *this;
		}
		Cascade &sety(int yy){
			y=yy;
			return *this;
		}
		Cascade &setz(int zz){
			z=zz;
			return *this;
		}
		 void print(){
		 	cout<<"x: "<<x<<" y: "<<y<<" z: "<<z<<endl;
		 }
};

int main(){
	Cascade c1;
	c1.setx(12).sety(10).setz(11);
	c1.print();
	return 0;
}
