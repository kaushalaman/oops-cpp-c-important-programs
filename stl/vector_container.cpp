#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
	vector<int> ss;
	int choice,data,i;
	vector<int>::iterator it;
	for(int j=0;j<=5;j++){
		cout<<"enter your choice"<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"push element in vector"<<endl;
				cin>>data;
				ss.push_back(data);
				break;
			case 2:
				cout<<"pop the element at the end"<<endl;
				ss.pop_back();
				break;
			case 3:
				cout<<"insert data"<<endl;
				cin>>data;
				cout<<"enter index"<<endl;
				cin>>i;
				ss.insert(ss.begin()+i,data);
				break;
			case 4:
				cout<<"erase item so give index"<<endl;
				cin>>i;
				ss.erase(ss.begin()+i);
				break;
			case 5:
				exit(1);
			default:
				cout<<"give no choice"<<endl;
		}
	}
	int sizes=ss.size();
	for(it=ss.begin();it!=ss.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	ss.clear();
	return 0;
}