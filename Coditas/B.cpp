#include<iostream>
using namespace std;
#define mod 1000000007

long long arr[1777];
long long cat[600];

void fun()
{
	long long res=1;
	arr[0]=1;
	for(int i=1;i<1666;i++)
	{
		arr[i]=(arr[i-1]*i)%mod;
	}
}

long long power(long long a,long long b){
	long long res=1;
	while(b){
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

void catlan()
{
	cat[0]=1;cat[1]=1;cat[2]=2;cat[3]=5;
	long long n1,d1,d2;

	for(int i=4;i<505;i++)
	{
		n1=arr[2*i];
		d1=arr[i+1];
		d2=arr[i];
											//cout<<"n d1 d2 "<<i<<" "<<n1<<" "<<d1<<" "<<d2<<endl;
		n1=(n1*power(d1,mod-2))%mod;
		n1=(n1*power(d2,mod-2))%mod;
											//cout<<"ans "<<n1<<endl;
		cat[i]=n1;
	}
}

long long res[600][600];
int main()
{
	fun();
							if(0)
							for(int i=0;i<10;i++)
							{
								cout<<arr[i]<<endl;
							}
	catlan();
							//cout<<"catlan\n";
							if(0)
							for(int i=0;i<15;i++)
							{
								cout<<cat[i]<<endl;
								}
	int n,h;
	cin>>n>>h;
	arr[1][1]=1;
	arr[2][1]=0;
	arr[2][2]=2;
	arr[3][1]=0;
	arr[3][2]=1;
	arr[3][3]=5;
	for(int i=4;i<=n;i++){
		for(int j=1;j<i;j++)
		{
			arr[][]
		}


	}

return 0;
}
