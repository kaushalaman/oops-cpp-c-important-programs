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

int getcount(Node *head_ref)
{
	static int count=0;
	Node *current=head_ref;
	if(current==NULL)
	{
		return 0;
	}
	return 1+getcount(current->next);
	
}

bool search(Node *head_ref,int val)
{
	if(head_ref==NULL)
	{
		cout<<"not found"<<endl;
		return false;
	}
	if(head_ref->data==val)
	{
		return true;
	}
	return search(head_ref->next,val);
}

void node_delete(Node **head_ref,int val)
{
    if(*head_ref==NULL){
    	cout<<"empty"<<endl;
    	return;
    }
    Node *temp=*head_ref;
    if(temp->data==val)
    {
    	*head_ref=temp->next;
    	delete temp;
    	return;
    }
	
	Node *prev=*head_ref;
	while(temp!=NULL){

		if(temp->data==val)
		{
			prev->next=temp->next;
			delete temp;
			return;	
		}
		prev=temp;
		temp=temp->next;
	}
	return;
}

void delete_pointer_node(Node *ptr)
{
	ptr->data=ptr->next->data;
	Node *temp=ptr->next;
	ptr->next=temp->next;
	delete temp;
}

int getnth(Node *head_ref, int index)
{
	int count=0;
	if(head_ref==NULL)
	{
		return 0;
	}
	while(head_ref!=NULL)
	{
		if(count==index){
			cout<<head_ref->data<<endl;
			return 0;
		}
		count++;
		head_ref=head_ref->next;
	}

}

int main()
{
	Node *head=NULL;
	back_push(&head,1);
	back_push(&head,2);
	back_push(&head,3);
	back_push(&head,4);
	front_push(&head,0);
	insert_after(head->next,1);
	print(head);
	node_delete(&head,0);
	print(head);
	cout<<getcount(head)<<endl;
	cout<<search(head,2)<<endl;
	cout<<search(head,3)<<endl;
	getnth(head,0);
	Node *ptr=head; 
	cout<<ptr->next->next->next->data<<endl;
	delete_pointer_node(ptr->next->next->next);
	print(head);
	return 0;
}