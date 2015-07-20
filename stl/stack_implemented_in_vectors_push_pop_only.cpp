#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
	vector<int> s;
	s.push_back(1);
	s.push_back(2);
	s.push_back(3);
	s.push_back(4);
	s.push_back(5);
	s.push_back(6);
	s.pop_back();
	for(int i=0;i<s.size();i++){
		cout<<s[i];
	}
	return 0;
}