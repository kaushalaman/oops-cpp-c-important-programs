#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;
const int size=3;
class vector{
private:
	int v[size];
public:
	vector();
	vector(int *a);
	void display();
	friend vector operator *(int a,vector b);
	friend vector operator *(vector b,int a);
	friend istream & operator >> (istream &,vector &);
	friend ostream & operator << (istream &,vector &);
	
};
vector::vector()
{
	for(int i=0;i<size;i++){
		v[i]=0;
	}
}
vector::vector(int *a){
	for(int i=0;i<size;i++){
		v[i]=a[i];
		}
	}
vector operator *(int a,vector b){
		vector c;
		for(int i=0;i<size;i++){
			c.v[i]=a*(b.v[i]);
		}
		return c;
	}
vector operator *(vector b,int a){
		vector c;
		for(int i=0;i<size;i++){
			c.v[i]=(b.v[i])*a;
		}
		return c;
	}
/*istream & operator >> (istream &din,vector &b){
		for(int i=0;i<size;i++){
			din >> b.v[i];
		}
		return(din);
	}
ostream & operator << (ostream &dout,vector &b){
	for(int i=0;i<size;i++){
		dout<< ", " << b.v[i];
	}
	return(dout);
}*/
void vector::display(){
	for(int i=0;i<size;i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
int a[size]={1,2,3};

int main(){
	vector m;
	vector n =a;
	n.display();
	vector p;
	p=3*n;
	p.display();
	vector q;
	q=m*2;
	q.display();
	return 0;
}