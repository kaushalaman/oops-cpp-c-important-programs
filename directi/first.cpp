#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#define sl strlen
#define sc strcpy
#define FC(i,a,b) for(char i = a; i <= b; ++i)
#define FI(i,a,b) for(int i = a; i <= b; ++i)
#define FOR_c(i,a,b) for(char i = a; i < b; ++i)
#define FOR_i(i,a,b) for(int i = a; i < b; ++i)
#define MAX 0x7fffffff
#define RI(i,n) FOR_i(i,0,(n))
using namespace std;
typedef pair<int,int> intPair;
typedef vector<intPair> dic;
typedef vector<int> vec;
typedef long long ll;
typedef long l;

int array[50];
int preorder_count(int m, int n)
{
    if(m == n)
		return 1;
    int index = MAX, count;
    if(array[m+1] > array[m])
    {
     
    	FI(i,m+2,n){
	    	if(array[i] < array[m])
     	    {     
    			index = i;
				break;
	    	} 
	    }    
    }     
    else     
    {
     FI(i,m+2,n){     
    	if(array[i] > array[m])
      	{     
          index = i;     
          break;
    	}
     
    }     
    if(index == MAX)     
    	return preorder_count(m+1, n);
    else     
    {     
    	count = preorder_count(m+1, index-1);
      	count *= preorder_count(index, n);
        count = count<<1;     
    }
    return count;
}
}
     
int main()
{
  int t, n;
  scanf("%d", &t);
  while(t--)
  {
     scanf("%d", &n);
     FI(i,1,n){
     	scanf("%d",&array[i]);
     }
     int result = preorder_count(1, n);
     cout<<result<<endl;
  }
  return 0;
} 
