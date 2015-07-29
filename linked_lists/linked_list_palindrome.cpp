#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stack>
using namespace std;

struct node{
	int data;
	struct node *next;
};

typedef struct node Node;
Node *New(int val)
{
	Node *temp=new node;
	if(!temp)
	{
		cout<<"not done"<<endl;
		return NULL;
	}
	temp->data=val;
	temp->next=NULL;
	return temp;
}
bool palindrome(Node **head_ref)
{
	bool flag;
	int num;
	stack<int> s;
	if(*head_ref==NULL)
	{
		return false;
	}
	Node *last=*head_ref;
	while(last!=NULL)
	{
		s.push(last->data);
		last=last->next;
	}
	Node *start=*head_ref;
	while(start!=NULL)
	{
		num=s.top();
		s.pop();
		if(num == start->data)
		{
			flag=true;
			start=start->next;
		}
		else{

			cout<<"not palindrome"<<endl;
			return false;
		}
	}
	return flag;
}
void front_push(Node **head_ref,int data)
{
	Node *temp=New(data);
	temp->next=*head_ref;
	*head_ref=temp;
}
void back_push(Node **head_ref,int data){
	
	if(*head_ref==NULL)
	{
		Node *temp=New(data);
		*head_ref=temp;
		return;
	}
	Node *start=*head_ref;
	if(start->next==NULL){
		Node *temp=New(data);
		start->next=temp;
		return;
	}
	else
	{	while(start->next!=NULL){
			start=start->next;
		}
		Node *temp=New(data);
		start->next=temp;
	}
	return;
}

int main()
{
	Node *head=NULL;
	back_push(&head,1);
	back_push(&head,2);
	back_push(&head,3);
	back_push(&head,2);
	back_push(&head,1);
	cout<<palindrome(&head);
	cout<<endl;
	return 0;
}