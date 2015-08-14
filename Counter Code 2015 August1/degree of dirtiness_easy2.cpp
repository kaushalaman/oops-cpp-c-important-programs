/* 
Problem Statement

There are N toilets in a row indexed from 1 to N. At a time, 2 people enter the washroom. The degree of dirtiness of each toilet is 0 initially and it increases by 1 after it is used each time. The 1st person occupies the 1st toilet with the lowest degree of dirtiness moving from 1 to N. The 2nd person occupies the toilet with the lowest degree of dirtiness moving from N to 1. The next two people enter the toilet when the first two people have left. Find the index of toilet and degree of dirtiness for the Mth person.

Note In case M is odd, the last person walks into the washroom alone and occupies the least dirty toilet moving from 1 to N.

Input Format
The first line contains T, the number of test cases. Each test case consists of one line containing N, the number of toliets, and M, the person to enter the toilet, seperated by space.

Output Format
The index of the toilet used by M and its degree of dirtiness D.

Constraints
1≤T≤10
1≤N≤50000
1≤M≤106

Sample Input

3  
10 3  
5 8  
4 26 

Sample Output

2 0  
4 1  
4 6  
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int a[MAX];
    int t,n,m,x,y,k,l,index;
    cin>>t;
    while(t){
        cin>>n>>m;
        k=1;
        l=n;
        x=0;y=0;index=0;
        for(int i=1;i<=n;i++)
        {
            a[i]=0;
        }
        for(int i=1;i<=m;i++)
        {
            if(i%2!=0){
                x=a[k];
                index=k;
                a[k]+=1;
                if(i%n==0){
                    l=n;
                    k=1;
                }
                else{
                    k++;
                }
            }
            else if(i%2==0)
            {
                y=a[l];
                index=l;
                a[l]+=1;
                if(i%n==0)
                {
                    l=n;
                    k=1;
                }
                else{
                    l--;
                }
            }
        }

        if(m%2==0)
        {
            cout<<index<<" "<<y<<endl;
        }
        else if(m%2!=0)
        {
            cout<<index<<" "<<x<<endl;
        }
        t--;
    }
    return 0;
}
