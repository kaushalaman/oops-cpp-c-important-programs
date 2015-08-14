/* 
Shil likes to perform Crazy Operation on an array A1,A2,...AN.

Given an array A1,A2,...AN and permutation P1,P2, ..,PN, a Crazy Operation consists of two parts:

        Perform Operation Bi = Ai for every i in 1..N

        Perform Operation Ai = BPi for every i in 1..N. Here P is a permutation from 1 to N.

Shil asks you to print the resulting array A1, A2,...AN after doing Crazy Operation on it , T times.

Input format:
The first line of input consists of two integers N and T. The next line consists of N integers A1, A2,...AN. The next line consists of permutation P1,P2,...PN.

Output format:
Print the resulting A1,A2,...AN after doing Crazy operations on it T times.

Constraints:
1≤N≤105
1≤T≤1018
1≤Ai≤109
Sample Input
(Plaintext Link)

5 3
1 2 3 4 5
3 4 5 2 1

Sample Output
(Plaintext Link)

1 4 3 2 5

Explanation

On doing Crazy Operation 1st time resulting array will be (3,4,5,2,1).
On doing second time , resulting array will be (5,2,1,4,3).
On doing third time, resulting array will be (1,4,3,2,5)
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
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;
     
void mnoz(vi & a, vi b) {
    int n = sz(a);
    vi pom(n);
    REP(i,n) pom[i] = a[b[i]];
    a = pom;
}
     
int in[nax];
     
int main()
{
    int n;
    ll k;
    scanf("%d%lld", &n, &k);
    RI(i, n) scanf("%d", &in[i]);
    vi w(n);
    REP(i,n) {
    scanf("%d", &w[i]);
    w[i]--;
    }
    vi id(n);
    REP(i,n) id[i] = i;
    vi res = id;
    while(k) {
    if(k % 2) mnoz(res, w);
    mnoz(w, w);
    k /= 2;
    }
    REP(i, n) printf("%d ", in[res[i]+1]);
    puts("");
    return 0;
}
