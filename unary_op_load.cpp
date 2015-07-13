#include <iostream>

using namespace std;
class Counter{
public:
	int count;
public:
	Counter():count(0)
	{}
	Counter(int c):count(c)
	{}
	Counter operator++()
	{
		Counter temp;
		temp.count=++count;
		return temp;
	}
	Counter operator++(int)
	{
		Counter temp;
		temp.count=count;
		++count;
		return temp;
	}
	void display(){
		cout<<count<<endl;
	}
	~Counter(){}

};

int main()
{
	Counter c1,c2(1);
	c1.display();
	c2.display();
	c2=c1++;
	c1.display();
	c2.display();
	
	return 0;
}
