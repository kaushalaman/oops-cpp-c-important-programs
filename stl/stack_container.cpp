#include <iostream>
#include <stack>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	stack<int> s;
	s.push(12);
	s.push(10);
	s.push(11);
	s.push(12);
	s.push(2);
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.size()<<endl;
	cout<<s.empty()<<endl;
	return 0;
}