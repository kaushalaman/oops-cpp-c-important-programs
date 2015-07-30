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

void delete_alternate(Node **head_ref)
{
	Node *ptr1=*head_ref;
	Node *ptr2=ptr1->next;
	while(ptr2!=NULL)
	{
		ptr1->next=ptr2->next;
		ptr1=ptr2->next;
		delete ptr2;
		if(ptr1!=NULL)
		{
		ptr2=ptr1->next;
		}
		else{
			return;
		}
	}
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

Node *intersect_list(Node *a, Node *b)
{
	Node *start=NULL;
	while(a != NULL && b!=NULL)
	{
		if(a->data==b->data)
		{
			back_push(&start,a->data);
			a=a->next;
			b=b->next;
		}
		else if(a->data>b->data)
		{
			b=b->next;
		}
		else if(a->data<b->data)
		{
			a=a->next;
		}
	}
	return start;
}

int main()
{
	Node *start1=NULL;
	back_push(&start1,1);
	back_push(&start1,2);
	back_push(&start1,3);
	back_push(&start1,7);

	print(start1);
	Node *ptr1=start1;
	ptr1=start1->next;
	ptr1=ptr1->next;
	Node *start2=NULL;
	back_push(&start2,2);
	back_push(&start2,4);
	back_push(&start2,5);
	back_push(&start2,6);
	back_push(&start2,8);
	//start2->next->next=ptr1;
	print(start2);
	//cout<<intersect(&start1,&start2)<<endl;
	//intersect_point(&start1,&start2);
	Node *ptr=intersect_list(start1,start2);
	print(ptr);
	delete_alternate(&start1);
	print(start1);
	return 0;
}