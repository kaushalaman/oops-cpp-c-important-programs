#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct node{
	int data;
	struct node *next;
	bool visited = false;
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
bool intersect(Node **start1, Node **start2)
{
	Node *ptr1=*start1;
	Node *ptr2=*start2;
	while(ptr1->next!=NULL)
	{
		ptr1=ptr1->next;
	}
	while(ptr2->next!=NULL)
	{
		ptr2=ptr2->next;
	}
	if(ptr1==ptr2)
	{
		return true;
	}
	return false;
}

int intersect_point(Node **start1,Node **start2)
{
	Node *ptr1=*start1;
	while(ptr1!=NULL)
	{
		ptr1->visited=true;
		ptr1=ptr1->next;
	}
	Node *ptr2=*start2;
	while(ptr2!=NULL)
	{
		if(ptr2->visited==true)
		{
			cout<<"intersect point is "<<ptr2->data<<" in address "<<ptr2<<endl;
			return 1;
		}
		ptr2=ptr2->next;
	}
	cout<<"no intersection"<<endl;
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
	Node *start1=NULL;
	back_push(&start1,1);
	back_push(&start1,2);
	back_push(&start1,3);
	back_push(&start1,2);
	back_push(&start1,1);
	print(start1);
	Node *ptr1=start1;
	ptr1=start1->next;
	ptr1=ptr1->next;
	Node *start2=NULL;
	back_push(&start2,4);
	back_push(&start2,0);
	start2->next->next=ptr1;
	print(start2);
	cout<<intersect(&start1,&start2)<<endl;
	intersect_point(&start1,&start2);
	return 0;
}