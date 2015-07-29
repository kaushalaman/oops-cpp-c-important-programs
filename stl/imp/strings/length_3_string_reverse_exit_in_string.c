#include<iostream>
#include<map>
#include<iterator>
using namespace std;

void Sub( string s )
{
map<string , int> m;
map<string,int>::iterator it;
        int start = 0;
        int end = start+2;
        while( end <= s.length()-1 )
        {

        string a;
        string b;
                for( int i=start ; i<=end ; i++ )
                {
                        a = a+s[i];
                }
                for(int i=end ; i>=start ; i--)
                {
                        b = b+s[i];
                }
                m[a]++;
                m[b]++;
                if( m[a] >= 2 )
                        cout << a << endl;
                start++;
                end++;
        }


}


int main()
{
Sub("abcdcba");

return 0;

}