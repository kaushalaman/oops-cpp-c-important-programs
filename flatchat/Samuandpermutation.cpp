#include <bits/stdc++.h>
#define RP(i,n) for(int i=0;i<n;++i)
using namespace std;
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef map<int,int> M;
M l[1<<20];
int arr[20],n;
int permute(int,int,int);
int main()
{
    int t;
    scanf("%d\n",&t);
    RP(i,t)
    {
    	RP(i,(1<<20)){
    	l[i].clear();
    	}
    scanf("%d\n",&n);
    RP(i,n){
    scanf("%d",&arr[i]);
    }
    printf("%d\n",permute(0,0,0));
    }
    return 0;
    }
     
int permute(int index,int front,int back)
{
    if(l[front].count(back))
    return l[front][back];
    if(front==(1<<n)-1)
    return 0;
    if(!index)
    {
    int total = 0;
    RP(i,n)
    {
    total = max(total,permute(index+1,front|(1<<i),arr[i]));
    }
    return l[front][back] = total;
    }
    else
    {
    int total = 0;
    RP(i,n)
    {
    if(!(front&(1<<i)))
    {
    total = max(total,permute(index+1,front|(1<<i),arr[i])+(index+1)*abs(arr[i]-back));
    }
    }
    return l[front][back] = total;
    }
}


