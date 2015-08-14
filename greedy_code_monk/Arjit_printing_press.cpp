#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#define sl strlen
#define sc strcpy
#define FC(i,a,b) for(char i = a; i <= b; ++i)
#define FI(i,a,b) for(int i = a; i <= b; ++i)
#define FOR_c(i,a,b) for(char i = a; i < b; ++i)
#define FOR_i(i,a,b) for(int i = a; i < b; ++i)
#define RI(i,n) FOR_i(i,0,(n))
using namespace std;
    
char *replace_char(char *s1,char *s2,int i, int j)
{
   s1[i]=s2[j];
   return s1;
}
   
void sort(char *s)
{
    int c, d = 0, length;
    char *pointer, *result, ch;
    length = sl(s);
    result = (char*)malloc(length+1);
    pointer = s;
    FC(ch,'a','z')
    {
       RI(c,length)
       {
    		if ( *pointer == ch )
    		{
    			*(result+d) = *pointer;
    			d++;
    		}
    		pointer++;
       }
       pointer = s;
    }
    *(result+d) = '\0';
    sc(s, result);
    free(result);
}
     
int main()
{
    int t;
    scanf("%d\n",&t);
    while(t)
    {
	    int i,j;
    	char *s1=(char *)malloc(100001);
    	char *s2=(char *)malloc(100001);
    	scanf("%s",s1);
    	scanf("%s",s2);
    	sort(s2);
    	RI(i,sl(s1))
    	{
    		if(sl(s2)==0)
    		{
    			break;
    		}
    		RI(j,sl(s2))
    		{
    			if(s1[i]>s2[j])
    			{
    				s1=replace_char(s1,s2,i,j);
    				memmove(&s2[j], &s2[j + 1], sl(s2) - j);
    				break;
    			}
    		}
    	}
    	printf("%s\n",s1);
    	t=t-1;
    }
    return 0;
}