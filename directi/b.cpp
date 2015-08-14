#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#define INF 0x7fffffff
using namespace std;


int array[50];


int so(int s, int e) 

{
	if(s == e)
		return 1;

	int idx = INF, res;
	if(array[s+1] > array[s]) 

	{

		for(int i=s+2; i<=e; i++)

			if(array[i] < array[s])

			{

				idx = i;

				break;

			} 

	}

	else 

	{

		for(int i=s+2; i<=e; i++)

			if(array[i] > array[s])

			{

				idx = i;

				break;

			}

	}

	if(idx == INF)

		return so(s+1, e);

	else

	{

		res = so(s+1, idx-1);

		res *= so(idx, e);

		res = res<<1;

	}

	

	return res;

}


int main() 
{
	int k, n;scanf("%d", &k);
	for(int t=1; t<=k; t++) 

	{

		scanf("%d", &n);

		for(int i=1; i<=n; i++)
			scanf("%d",&array[i]);


		int res = so(1, n);printf("%d\n", res);

	}

	return 0;

}