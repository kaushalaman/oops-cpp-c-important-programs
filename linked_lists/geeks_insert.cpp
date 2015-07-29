#include <iostream>
#include <cstdlib>
#include <cstdio>
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

void insert_after(Node *prev_node,int data)
{
	if(prev_node->next==NULL)
	{
		return;
	}
	Node *temp=New(data);
	temp->next=prev_node->next;
	prev_node->next=temp;
}

void print(Node *head_ref)
{
	if(head_ref == NULL) 
	{
		cout<<"nothing to display"<<endl;
		return;
	}
	else
	{
		while(head_ref!=NULL)
		{
			cout<<head_ref->data<<" ";
			head_ref=head_ref->next;
		}
		cout<<endl;
	}
}

int main()
{
	Node *head=NULL;
	back_push(&head,1);
	back_push(&head,2);
	front_push(&head,0);
	insert_after(head->next,1);
	print(head);
	return 0;
}