#include <iostream>
#include <cstdlib>
#include <list>
#include <cstdio>
using namespace std;

int main()
{
	int arr[]={1,4,5,6,6,7,3,0};
	int arr1[]={2,4,5,11};
	int item;

	list<int> l(arr1,arr1+sizeof(arr1)/sizeof(int));
	list<int> ls(arr,arr+sizeof(arr)/sizeof(int));
	list<int>::iterator it;

	cout<<"list elements are: ";
	for(it=ls.begin();it!=ls.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	cout<<"size of list"<<endl;
	cout<<ls.size();
	cout<<endl;

	cout<<"start of the list "<<endl;
	cout<<ls.front()<<endl;

	cout<<"last item of the list"<<endl;
	cout<<ls.back()<<endl;

	cout<<"insert at beginning"<<endl;
	cin>>item;
	ls.push_front(item);

	cout<<"insert at end"<<endl;
	cin>>item;
	ls.push_back(item);

	cout<<"list elements are: ";
	for(it=ls.begin();it!=ls.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
		

	cout<<"delete item at beginning"<<endl;
	ls.pop_front();

	cout<<"delete item at end"<<endl;
	ls.pop_back();

	cout<<"list elements are: ";
	for(it=ls.begin();it!=ls.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	cout<<"remove item"<<endl;
	cin>>item;
	ls.remove(item);

	cout<<"list elements are: "<<endl;
	for(it=ls.begin();it!=ls.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	cout<<"reverse the list"<<endl;
	ls.reverse();

	cout<<"list elements are: "<<endl;
	for(it=ls.begin();it!=ls.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	cout<<"sort the list"<<endl;
	ls.sort();
 
    cout<<"list elements are: "<<endl;
	for(it=ls.begin();it!=ls.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	cout<<"unique elements"<<endl;
	ls.unique();

	cout<<"list elements are: "<<endl;
	for(it=ls.begin();it!=ls.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	cout<<"list l elements are: "<<endl;
	for(it=l.begin();it!=l.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	cout<<"Enter new size of the List: ";
    cin>>item;
    if (item <= l.size())
        l.resize(item);
    else
        l.resize(item);
    
    cout<<"list elements are: "<<endl;
	for(it=l.begin();it!=l.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	cout<<"merge lists"<<endl;
	ls.sort();
	l.sort();
	ls.merge(l);


	cout<<"list elements are: "<<endl;
	for(it=ls.begin();it!=ls.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<"\n";
    return 0;
}