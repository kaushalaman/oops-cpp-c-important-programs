#include <iostream>

using namespace std;

class M
{
protected:
	int m;
public:
	int set_m(int i){
		m=i;
	}
	int get_m(){
		return m;
	}
};

class N{
protected:
	int n;
public:
	int set_n(int j){
		n=j;
	}
	int get_n(){
		return n;
	}
};

class multiple:public M,public N{
public:
	void display(){
		cout<<"m is: "<<m<<endl;
		cout<<"n is: "<<n<<endl;
	}
};

int main(){
	multiple m;
	m.set_m(4);
	m.set_n(2);
	m.display();
	return 0;
}