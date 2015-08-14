#include <cstdio>
#include <cmath>
#include <vector>
#include <stack>
#include <numeric> 
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string.h>
#define sl strlen
#define sc strcpy
#define FC(i,a,b) for(char i = a; i <= b; ++i)
#define FI(i,a,b) for(int i = a; i <= b; ++i)
#define FOR_c(i,a,b) for(char i = a; i < b; ++i)
#define FOR_i(i,a,b) for(int i = a; i < b; ++i)
#define RI(i,n) FOR_i(i,0,(n))
using namespace std;
typedef pair<int,int> intPair;
typedef vector<intPair> dic;
typedef vector<int> vec;
typedef long long ll;
typedef long l;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int a=0,i;
		int b=0;
		dic pair_a(1000);
		dic pair_b(1000);

		RI(i,s.length())
		{
			if(s[i]=='a')
				a++;
			else if(s[i]=='b')
				b++;
		}
		if(a==s.length())
		{
			cout<<'0'<<endl;
			return 0;
		}
		else if(b==s.length())
		{
			cout<<'0'<<endl;
			return 0;
		}
		cout<<"hey"<endl;
		a=0;b=0;
		RI(i,s.length())
		{
			cout<<"hey"<<endl;
			break;
			if(s[i]=='a')
			{
				a++;
				cout<<a<<endl;
				break;
				pair_a[i].first=i;
				cout<<pair_a[i].first<<endl;
				pair_a[i].second=a;
				
			}
			else if(s[i]=='b')
			{
				b++;
				pair_b[i].first=i;
				pair_b[i].second=b;
			}
		}
		for(dic::iterator it=pair_a.begin();it!=pair_a.;it++)
		{
			cout<<it->first<<" "<<it->second<<endl;
		}
		int size_a=pair_a.size();
		int size_b=pair_b.size();
		string ss;
		int i_a=pair_a[size_a-1].first;
		int i_b=pair_b[0].first;
		if(i_a<i_b){
		for(i=i_a;i<=i_b;i++)
			ss[i]=s[i];

		}
		else if(i_a>i_b)
		{
			for(i=i_b;i<=i_a;i++)
				ss[i]=s[i];	
		}
		reverse(ss.begin(),ss.end());
		cout<<ss<<endl;

	}


}