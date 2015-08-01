#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct node{
	int data;
	struct node *next;
	bool visited;
};

typedef struct node Node;

Node *New(int val)
{
	Node *temp=new node;
	temp->data=val;
	temp->next=NULL;
	return temp;
} 

void detect_remove(Node **head_ref)
{
	if(*head_ref == NULL)
	{
		cout<<"not a loop found"<<endl;
		return;
	}
	Node *ptr1=*head_ref;
	while(ptr1->next!=NULL)
	{
		ptr1->visited=true;
		if(ptr1->next->visited!=true)
			ptr1=ptr1->next;
		else{
			ptr1->next=NULL;
			return;
		}
	}
}void front_push(Node **head_ref,int data)
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
	Node *prev;
	back_push(&head,1);
	back_push(&head,2);
	back_push(&head,3);
	back_push(&head,4);
	back_push(&head,5);
	back_push(&head,6);
	back_push(&head,7);
	Node *start=head;
	while(start->data!=4)
	{
		start=start->next;
	}
	Node *start1=head;
	while(start1->data!=7)
	{
		start1=start1->next;
	}
	start1->next=start;
	//print(head);
	/*Node *ptr=head;
	Node *ptr1;
	ptr1=ptr->next->next->next;
	ptr1->next->next=ptr1;
	detect_loop(&head);*/
	detect_remove(&head);
	print(head);
	return 0;
}


	
