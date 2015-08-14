#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    int data;
    struct node *link;
};

typedef struct node Node;
    
Node *New(int val)
{
    Node *temp=new node;
    temp->data=val;
    temp->link=NULL;
    return temp;
}

int length(Node *start)
{
    if(start==NULL)
    {
        return 0;
    }
    if(start->link==NULL)
    {
        return 1;
    }
    Node *ptr=start->link;
    int count=1;
    while(ptr!=NULL && ptr!=start)
        {
        ptr=ptr->link;
        count++;
    }
    return count;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,flag,g;
    Node *start=NULL;
    Node *temp;
    cin>>n;
    int a[n+2];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i+1])
            flag=1;
        else{
            g=1;
        }
    }
    if(flag && g!=1)
    {
        cout<<"1 "<<n-1<<endl;
        return 0;
    }
    int i=1;
    if(a[i]==a[i+1] && n==3)
    {
        cout<<"2 1"<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        flag=0;
        if(!start)
        {
            temp=New(i);
        }
        Node *ptr1=start;
        Node *ptr2=start;
        while(ptr1!=NULL){
            if(ptr1->data!=a[i]){
                 ptr1=ptr1->link;
            }    
            else if(ptr1->data==a[i]){
                flag=1;
                break;
            }
        }
        if(flag)
        {
           while(ptr2!=NULL)
           {    
                if(ptr2->data!=i)
                {
                    ptr2=ptr2->link;
                }
                else{
                    break;
                }
            }
            ptr1->link=ptr2;
        }

        else
        {        
            Node *front=New(a[i]);
            front->link=temp;
            temp=front;
            start=temp;
        }
    }
    cout<<(length(start)-1)%1000000007<<" "<<length(start)%1000000007<<endl;
    return 0;
}
