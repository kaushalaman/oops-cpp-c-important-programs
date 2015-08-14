#include <bits/stdc++.h>

#define for_each(it,lines) for(map<int, pair<int,int> >::const_iterator it = lines.begin();it != lines.end(); ++it) 
#define P pair<int ,int >
#define M map< P ,int >
#define M_I map< int , P >
using namespace std;

int main()
{
	int t;
	cin>>t;

	M m;
	M_I lines;
	M mm;
	for(int i=1;i<=t;i++)
	{
		int a,b,c,d;
		cin>>a>>b>>c;
		if(a==0 and  b!=0){
				mm[make_pair(0,1)]++;
		}
		if(a!=0 and  b==0){
				mm[make_pair(1,0)]++;
		}

		if(a!=0 and b!=0){
			d=__gcd(abs(a),abs(b));
			a=a/d;
			b=b/d;
		}
		lines[i]=make_pair(a,b);
		m[make_pair(a,b)]++;		
	}

	int q;
	cin>>q;
	while(q--)
	{
		int qq=0;
		cin>>qq;
		P x =lines[qq];
		int a=x.first;
		int b=x.second;

		if(a==0 and b==0)
		{
			cout<<"0\n";
			continue;
		}
		if(a==0 and b!=0){
			int count=0;
			count=mm[make_pair(1,0)];
			cout<<count<<endl;
			continue;
		}
		else if(a!=0 and b==0){
			int count=0;
			count=mm[make_pair(0,1)];
			cout<<count<<endl;
			continue;
		}
		else
		{
			cout<<(m[make_pair(-b,a)]+m[make_pair(b,-a)])<<endl;
		}
	}
	return 0;
}