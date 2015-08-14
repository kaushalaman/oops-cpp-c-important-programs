/* 
Problem Statement

Time is running out. You have a final match to play as a counter terrorist. You have N players each having a distinct ID from 1 to N. You have to choose some players on your team from these N players such that no two chosen players have consecutive numbers (as they tend to kill each other). Also you definitely have to choose some K players whose numbers are given. They are the snipers. Find the maximum number of players that you can choose.

Input Format

The first line contains 2 space-separated integers, N and K, where N is the total number of players and K is the number of players that have to be definitely in the team (the snipers).
The second line contains K space-separated integers that are the IDs of the snipers.

NOTE: There are no two snipers with consecutive numbers.

Constraints
2≤N≤2×106
1≤K≤N/2
1≤ ID of each sniper ≤N

Output Format

You need to print the maximum number of players that you can have in your team.

Sample Input

8 2
6 2

Sample Output

4

Explanation

There are 8 players in total, among which you have to definitely choose players with ID 2 and 6.
To maximize the number of players in the team, you will choose the players with IDs 4 and 8, so that you will have a total of 4 players.  */

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  int m,n,s;
  cin>>n>>m;
  int a[10000000000000];
  int count=0;
  
  for(int i=0;i<m;i++)
  {
    cin>>s;
    a[s]=1;
    count=count+1;
  }
  for(int i=1;i<n+1;i++)
  {
    if(a[i-1]==1 || a[i]==1 ||a[i+1]==1)
    {
      continue;
    }
    else{
      count++;
      a[i]=1;
    }
  }
  cout<<count<<endl;
  return 0;
}
