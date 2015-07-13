#include <iostream>
#include <process.h>
#include <iomanip>
using namespace std;
class Distance
{
	private:
		int feet;
		int inches;
	public:
		Distance():feet(0),inches(0)
		{ 	}
		Distance(int f,int i):feet(f),inches(i)
		{	}
		void get_dist()
		{
			cout<<setw(10);
			cout<<"feet\t";
			cin>>feet;
			cout<<"inches\t";
			cin>>inches;
		}
		
		void show(){
			cout<<"feet: "<<feet<<" inches: "<<inches<<endl;
		}
		~Distance(){
		}
};

int main(){
Distance *d;
int n;
cin>>n;
d=new Distance[n];
for(int i=0;i<n;i++){
	d[i].get_dist();
}
for(int i=0;i<n;i++){
	d[i].show();
}
return 0;}
