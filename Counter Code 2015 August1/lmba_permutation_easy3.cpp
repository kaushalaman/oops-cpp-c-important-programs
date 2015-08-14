/* 
Problem Statement

A DOTA game has N heroes, each with a distinct rank from [1..N]. In DOTA every formation is characterized as a permutation [1...N] of ranks of players.
A formation is Imba when the sum of ranks of every two consecutive players is less than or equal to (N+1). Given N, you are to print the lexicographically smallest permutation of ranks [1...N] that makes the formation Imba.

Input Format

The first line will contain an integer T, i.e. the number of the test cases followed by T lines, each containing the value of N.

Constraints
1≤T≤5
2≤N≤105

Output Format

T lines each containing the permutation; the numbers in each line should be seperated by a single space.

Sample Input

2
2
3

Sample Output

1 2
2 1 3

Explanation

In the first case there are two possible permutations [1,2] and [2,1]. Both of the given permutations satisfy the given constraints and [1,2] is lexicographically smaller than [2,1].
In the second case, the two possible permutations are [2,1,3] and [3,1,2], of which the former is lexicographically smaller.

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

void lmba(int n, int flag){
	int middle,middle_next,i,j;
	if(flag){
		middle=(n/2)+1;
		i=middle-1;
		j=middle+1;
		cout<<middle<<" ";
	}
	else
	{
		middle=(n/2);
		middle_next=(n/2)+1;
		i=middle-1;
		j=middle_next+1;
		cout<<middle<<" "<<middle_next<<" ";
	}
	while(i!=0 && j!=n+1)
	{
		cout<<i<<" "<<j<<" ";
		i--;j++;
	}
}

int main()
{
	int t,n,flag;
	cin>>t;
	while(t--)
	{
		cin>>n;
		flag=(n%2!=0)?1:0;
		lmba(n,flag);
		cout<<endl;
	}
	return 0;
}