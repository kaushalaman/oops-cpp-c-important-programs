/*
Shil decided to go for hill climbing on this weekend, but he doesn't have the map of all the hills. However, he's smart enough to make his own map.

There are N hills arranged on a line, each in the form of a vertical line segment with one endpoint on the ground. The hills are numbered with numbers from 1 to N from left to right. The ith hill stands at the position xi with its top at height yi.

A pair (a, b) ( where a < b ) is called beautiful if and only if Shil will be able to see the peak of bth hill standing on the top of ath hill.

In order to make his own map, Shil needs total number of beautiful pairs. As Shil is not a very good programmer, he asks for your help.

Assume that Shil's height is very small as compared to the height of hills. (Really!) Thus, we can assume that Shil's eyes are exactly at the height of peak if he is standing at peak of some hill.

You can also assume that Shil is able to see peak of certain hills if distance between peak and Shil's sight is less than 10-4.

Input format:
The first line of the input contains a single integer N , the number of hills. The next N lines describe the hills. The ith of them contains two space-separated integers xi, yi , the position and the height of the ith hill. The hills are given in the ascending order of xi, i.e., xi < xj for i < j.

Output format:
Print the total number of beautiful pairs.

Constraints:
2 ≤ N ≤ 1000
1 ≤ xi , yi ≤ 109
Sample Input
(Plaintext Link)

4
1 9
2 3
3 7
4 1

Sample Output
(Plaintext Link)

4

Explanation

All the beautiful pairs are (1,2),(1,3),(2,3),(3,4)

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
     
struct P {
    ll x, y;
    P() { x = y = 0; }
    P(ll a, ll b) { x = a; y = b;}
    P operator - (const P & b) const { return P(x-b.x, y-b.y); }
    bool operator <= (const P & b) const { return x*b.y-y*b.x <= 0; };
} p[1005];
     
int main(int argc, char *argv[])
{
    debug = argc > 1;
    assert(P(4,4) <= P(5,2));
    int n;
    scanf("%d", &n);
    REP(i, n) scanf("%lld%lld", &p[i].x, &p[i].y);
    int r = 0;
    REP(i, n - 1) {
    ++r;
    P best = p[i+1];
    FOR(j, i + 2, n - 1) {
    if((p[j] - p[i]) <= (best - p[i])) {
    best = p[j];
    ++r;
    }
    }
    }
    printf("%d\n", r);
    return 0;
}
