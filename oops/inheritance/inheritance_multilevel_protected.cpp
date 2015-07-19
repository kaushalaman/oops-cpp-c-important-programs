#include <iostream>
using namespace std;

class student{
protected:
	int roll_number;
	static int count;
public:
	student():roll_number(0)
	{ count++;}
	int set_roll_number(){
		cout<<"enter roll number:"<<"\t";
		cin>>roll_number;
	}
	int get_roll_number(){
		return roll_number;
	}
	void show_student(){
		cout<<"student roll number is "<<roll_number<<endl;
	}

};

int student::count=0;

class test: public student{
protected:
	int sub1;
	int sub2;
public:
	test():sub1(0),sub2(0)
	{ }

	test(int i,int j){
		sub1=i;
		sub2=j;
	}

	int set_marks(){
		cout<<"Enter marks of both subjects: "<<endl;
		cin>>sub1;
		cin>>sub2;
	}

	int getsub1(){
		return sub1;
	}

	int getsub2(){
		return sub2;
	}

	void show_test(){
		cout<<"student roll "<<roll_number<<" subject 1 marks: "<<sub1<<endl;
		cout<<"student roll "<<roll_number<<" subject 2 marks: "<<sub2<<endl;
	}

	
};

class student_result: public test{
private:
	float total;
public:
	student_result():total(0)
	{ }

	int show_result(){
		cout<<"student roll "<<roll_number<<" has final result is ";
		total=(float(sub1)+float(sub2))/2;
		cout<<total<<"%"<<endl;
	}

	~student_result(){}

};

int main(){

student_result s[5];

for(int i=0;i<5;i++){
	if(i==0){
		cout<<endl;
	cout<<"Get Student result"<<endl;
	cout<<endl;
	}
	else{
		cout<<"Get another student result"<<endl;
		cout<<endl;
	}
	s[i].set_roll_number();
	s[i].set_marks();
	cout<<endl;
	cout<<"#####################"<<endl;
	cout<<endl;
	s[i].show_student();
	s[i].show_test();
	s[i].show_result();
	cout<<endl;
}

return 0;

}
