#include <iostream>
#include <string>
#include <string.h>
#include <cctype>
#include <cstdlib>
#include <cstdio>
using namespace std;
int main()
{
	string s,str="This is a text example";
	int found;
	cout<<str.size()<<endl;
	cout<<str.length()<<endl;
	str.insert(3,"am");
	cout<<str<<endl;
	str.erase(3,2);
	cout<<str<<endl;
	str.append("dhud");
	cout<<str<<endl;
	cout<<"enter substring to be found"<<endl;
	cin>>s;
	found=str.find(s);
	cout<<"found"<<found<<endl;
	for(string::iterator it=str.begin();it!=str.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	str[1]=toupper(str[1]);
	cout<<str<<endl;
	if(str.find("ami")!=string::npos)
	{
		cout<<"found"<<endl;
	}
	else{
		cout<<"not found"<<endl;
	}
	char g[100];
	strcpy(g,"sklakdlnc");
	cout<<g<<endl;
	return 0;

}