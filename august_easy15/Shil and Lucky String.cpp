/*
Shil is your new boss and he likes lucky strings very much. A string is called lucky if and only if each character from first half of the string can be paired to each character from second half of the string. AND:

    In each pair, a character from the first half is strictly greater than a character from the second half OR
    In each pair, a character from the first half is strictly lesser than a character from the second half OR
    In each pair, a character from the first half is equal to character from the second half.

Each character should be used exactly once in pairing.

Your are given a string S. You want to change the minimum number of characters to make this string lucky so that you can gift it to your boss.

Note that each character in lucky string should be in lower case alphabet ( 'a' - 'z' ).

Input format:
The first line consists of an integer N. The second line consists of N lower case characters.

Output format:
Print minimum number of changes required to make given string lucky.

Constraints:
1 < N ≤ 105
N will be an even integer.
Sample Input
(Plaintext Link)

6
aabbbb

Sample Output
(Plaintext Link)

1

Explanation

To satisfy case 1, number of changes required is 3.
To satisfy case 2, number of changes requires is 1.
To satisfy case 3,number of changes required is 2.

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
     
char sl[nax];
int cyf(char z) { return z - 'a'; }
int t[2][26];

int eq() 
{
   int r = 0;
    REP(i, 26) if(t[0][i] < t[1][i]) r += t[1][i] - t[0][i];
    return r;
}
int le(int I) 
{
    int r = 0;
    multiset<int> s;
    REP(i, 26) REP(k, t[1^I][i]) s.insert(i);
    REP(i, 26) REP(k, t[I][i]) 
    {
    	auto it = s.upper_bound(i);
    	if(it != s.end()) s.erase(it);
    	else ++r;
    }
    return r;
}
     
int main(int argc, char *argv[])
{
    debug = argc > 1;
    int n;
    scanf("%d", &n);
    scanf("%s", sl);
    REP(i, n/2) t[0][cyf(sl[i])]++;
    FOR(i,n/2,n-1) t[1][cyf(sl[i])]++;
    int res = inf;
    mini(res, eq());
    REP(i,2) mini(res, le(i));
    printf("%d\n", res);
    return 0;
}



