#include <iostream>
using namespace std;


class invent2;
class invent1{
	int code;
	int items;
	float price;
public:
	invent1(int a,int b,int c){
		code=a;
		items=b;
		price=c;
	}

	void putdata()
	{
		cout<<"Code: "<<code<<endl;
		cout<<"items: "<<items<<endl;
		cout<<"price: "<<price<<endl;
	}

	int getcode(){
		return code;
	}
	int getitems(){
		return items;
	}
	float getprice(){
		return price;
	}
	operator float(){
		return items*price;
	}
	operator invent2(){
		invent2 temp;
		temp.code=code;
		temp.value=items*price;
		return temp;
	}
};
class invent2
{
	int code;
	float value;
public:
	invent2():code(0),value(0.0)
	{ }
	invent2(int x,float y)
	{
		code=x;
		value=y;
	}
	void putdata()
	{
		cout<<"code is "<<code<<endl;
		cout<<"value is "<<value<<endl;
	}
	/*invent2(invent1 p){
		code=p.getcode();
		value=p.getitems()*p.getprice();
	}*/
};


int main()
{
	invent1 s1(100,5,140.0);
	invent2 d1=invent2(s1);
	float total_value;
	total_value=s1; //invent1 to float
	cout<<"total_value "<<total_value<<endl;
	 //invent1 to invent2
	s1.putdata();
	d1.putdata();
	return 0;
}