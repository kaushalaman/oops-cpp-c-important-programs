/*
Shil, Aditya and Utkarsh go to a candy shop. There are N candies present in the shop, which are indexed from 1 to N. All three of them select one candy to eat.

However, a candy tastes delicious if and only if, the index of candy chosen by Shil is strictly less than the index of candy chosen by Aditya and the index of candy chosen by Aditya is strictly greater than index of candy chosen by Utkarsh.

To state in simple Mathematical terms, if Shil chooses ith candy, Aditya chooses jth candy and Utkarsh chooses kth candy, then the candies would taste delicious

    if and only if i < j and j > k.

You have to find the total number of ways in which they can choose candies such that the candies would taste delicious to them. Note that all of them choose distinct number of candies i.e., i!=j and j!=k and i!=k.

Input format:
The only line of input consists of a single integer N denoting the total number of candies.

Output format:
Find the total number of ways by which all three can choose candies such that the candies would taste delicious to them.

Constraints:
3 ≤ N ≤ 1000
Sample Input
(Plaintext Link)

4

Sample Output
(Plaintext Link)

8

Explanation

All the possible ways to choose candies are:

    [1,3,2]
    [2,3,1]
    [2,4,3]
    [3,4,2]
    [1,4,3]
    [3,4,1]
    [2,4,1]
    [1,4,2]

The first integer in all the tuples denotes index of candy chosen by Shil, the second integer denotes index of candy chosen by Aditya and the third integer denotes index of candy chosen by Utkarsh.

*/

#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;
     
     
     
int main(int argc, char *argv[])
{
    debug = argc > 1;
    int n;
    scanf("%d", &n);
    int r = 0;
    RI(c, n) r += (c-1) * (c-2);
    printf("%d\n", r);
    return 0;
}
