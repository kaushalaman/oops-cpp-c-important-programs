
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
void reverse(Node *start)
{
	if(start==NULL)
	{
		return;
	}
	reverse(start->next);
	cout<<start->data;
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
	back_push(&head,4);
	front_push(&head,0);
	reverse(head);
	cout<<endl;
	return 0;
}