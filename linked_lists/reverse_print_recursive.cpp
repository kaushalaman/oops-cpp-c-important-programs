
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

void swap_pair(Node **head_ref)
{
	Node *ptr1=*head_ref;
	Node *ptr2=ptr1->next;
	while(ptr2!=NULL)
	{
		(ptr1->data)^=(ptr2->data)^=(ptr1->data)^=(ptr2->data);
		if(ptr2->next!=NULL){
			ptr1=ptr2->next;
			ptr2=ptr1->next;
		}
		else{
			return;
		}

	}
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
	back_push(&head,3);
	back_push(&head,4);
	back_push(&head,5);
	reverse(head);
	cout<<endl;
	swap_pair(&head);
	print(head);
	return 0;
}