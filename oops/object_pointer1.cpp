#include <iostream>
#include <malloc.h>
#include <process.h>
using namespace std;

class Distance
{
	private:
		int feet;
		int inches;
	public:
		Distance():feet(0),inches(0)
		{	}
		Distance(int f, int i):feet(f),inches(i)
		{	}
		void set(int f,int i){
			feet=f;inches=i;
		}
		void show()
		{
			cout<<"feet: "<<feet<<" inches: "<<inches<<endl;
		}
		~Distance(){
		}
};

int main()
{
	Distance *d1,*d2,*d3;
	d1=new Distance();
	if(d1==NULL){
		cout<<"memory not allocated";
		exit(1);
	}
	d2=new Distance(102,12);
	if(d2==NULL){
		cout<<"memory not allocated";
		exit(1);
	}
	d3=(Distance *)malloc(sizeof(Distance));
	if(d3==NULL){
		cout<<"memory not allocated";
		exit(1);
	}
	d1->show();
	d2->show();
	d3->show();
	d3->set(2,4);
	d3->show();
	delete d1;
	delete d2;
	free(d3);
	return 0;
	
}
