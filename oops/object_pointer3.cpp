#include <iostream>
#include <iomanip>


using namespace std;

class Distance
{
	private:
		int feet;
		int inches;
	public:
		Distance():feet(0),inches(0)
		{	}
		Distance(int f,int i):feet(f),inches(i)
		{ 	}
		void set(int f, int i)
		{
			feet=f;inches=i;
		}		
		void get_dist(){
			cout<<setw(5)<<"feet\t";cin>>feet;
			cout<<setw(5)<<"inches\t";cin>>inches;
		}
		void show(){
			cout<<"feet: "<<feet<<"inches: "<<inches<<endl;
		}
		~Distance(){}
};

int main(){
	Distance *p[5];
	int n=0;
	do{
		p[n]=new Distance;
		p[n]->get_dist();
		p[n]->show();
		n++;
	}while(n<5);
return 0;
}
