#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
int t,n;
cin>>t;
while(t--)
{
cin>>n;
int arr[n+3];
for(int i=0;i<n;i++)
cin>>arr[i];

sort(arr,arr+n);
int _max=-1,temp=0;
while(1){
	temp=0;
	//cout<<endl;
	//for(int i=0;i<n;i++)
	//	cout<<arr[i]<<" ";
	//cout<<endl;
	for(int j=1;j<n;j++){
		//cout<<"i "<<arr[j]<<" "<<arr[j-1]<<endl;
		temp+=(j+1)*abs(arr[j]-arr[j-1]);
	}
	//cout<<"temp "<<temp<<endl;
	_max=max(_max,temp);
	if(_max==temp)
{
for(int i=0;i<n;i++)
                cout<<arr[i]<<" ";
        cout<<endl;
	cout<<"temp "<<temp<<endl;
}
	int b=next_permutation(arr,arr+n);
	if(b==0)
		break;
}
cout<<_max<<endl;
}
return 0;
}
