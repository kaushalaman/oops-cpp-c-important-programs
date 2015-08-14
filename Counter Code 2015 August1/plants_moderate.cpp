#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
	int n,v,count=0,flag=0,size=0,times=0;
	vector<int> a;
	vector<int>::iterator it;
	cin>>n;

	for(int i=1;i<=n;i++)
	{
		cin>>v;
		a.push_back(v);
	}	
	
	while(1)
	{
		size=a.size();
		flag=0;
		vector<int> b;

		for(int i=0;i<size-1;i++)
		{
			if(a[i]<a[i+1])
			{
				b.push_back(i+1);
			}
		}
	
		for(int i=0;i<b.size();i++)
		{	
			flag=1;
			a.erase(a.begin()+b[i]);
			if(i!=b.size()-1)
			{
				for(int j=i+1;j<b.size();j++)
				{
					if(b[j]!=0){
						b[j]--;
					}
					else{
						break;
					}
				}
			}
		}
		if(!flag){
			break;
		}
		count++;
	}

	cout<<count<<endl;
	return 0;
} 