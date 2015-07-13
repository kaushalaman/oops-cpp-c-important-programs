#include <iostream>
#include <iomanip>
#include <process.h>
using namespace std;
class Sample
{
	private:
		int x;
		mutable int y;
	public:
		Sample():x(0),y(0)
		{}
		Sample(int xx,int yy):x(xx),y(yy)
		{}
		void setx(int xx)
		{
			x=xx;
		}
		void sety(int yy) const
		{
			y=yy;
		}
		int getx(){
			return x;
		}
		int gety(){
			return y;
		}
		void show() const
		{
			cout<<"x is "<<x<<" y is "<<y<<endl;
		}
};
int main()
{
	const Sample o1(10,12),o2(12,13);
	o1.sety(2);
	o1.setx(4);
	o1.show();
	return 0;
}
