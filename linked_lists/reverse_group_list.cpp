#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct node{
	int data;
	struct node *next;
};

typedef struct node Node;

Node *New(int val)
{
	Node *temp=new node;
	temp->data=val;
	temp->next=NULL;
	return temp;
}

Node *reverse_group(Node *head_ref, int k)
{
	Node *current=head_ref;
	Node *prev=NULL;
	Node *next=NULL;
	int count = 0;
	while(current!=NULL && count < k)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
		count++;
	}	
	if(next!=NULL)
	{
		head_ref->next=reverse_group(next,k);
		return prev;
	}
	return prev;
}

Node *reverse_group_alt(Node *head_ref, int k)
{
	Node *current=head_ref;
	Node *prev=NULL;
	Node *next=NULL;
	int count = 0;
	while(current!=NULL && count < k)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
		count++;
	}	
	if(next!=NULL)
	{
		head_ref->next=current;		
	}
	count=0;
	while(count<k-1 && current != NULL)
	{
		current=current->next;
		count++;
	}
	if(current!=NULL)
	{
		current->next=reverse_group_alt(current->next,k);
	}
	return prev;
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
	back_push(&head,6);
	back_push(&head,7);
	front_push(&head,0);
	print(head);
	/*Node *ptr=head;
	Node *ptr1;
	ptr1=ptr->next->next->next;
	ptr1->next->next=ptr1;
	detect_loop(&head);*/
	
	head=reverse_group_alt(head,3);
	print(head);
	return 0;
}