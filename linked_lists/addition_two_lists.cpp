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
			cout<<head_ref->data<<"  ";
			head_ref=head_ref->next;
		}
		cout<<endl;
	}
}
static void reverse(struct node** head_ref)
{
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next; 
        current->next = prev;  
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

Node *add(Node *start1, Node *start2)
{
	Node *res=NULL;
	Node *temp=NULL;
	int sum=0,carry=0;
	Node *prev=NULL;
	Node *ptr1=start1;
	Node *ptr2=start2;
	while(ptr1 != NULL || ptr2 != NULL)
	{
		sum=carry+(ptr1?ptr1->data:0)+(ptr2?ptr2->data:0);
		carry=(sum>=10?1:0);
		sum=sum%10;
		temp=New(sum);
		if(res==NULL)
		{
			res=temp;
		}
		else{
			prev->next=temp;
		}
		prev=temp;
		if(ptr1) ptr1=ptr1->next;
		if(ptr2) ptr2=ptr2->next;
	}
	if(carry>0){
		temp=New(carry);
		prev->next=temp;
	}
	reverse(&res);
	return res;
}
void printReverse(struct node* head)
{
  if(head == NULL)
    return;
  printReverse(head->next);
  printf("%d  ", head->data);
}

int main()
{
	Node *head1=NULL;
	Node *head2=NULL;
	Node *result=NULL;
	Node *prev;
	back_push(&head1,6);
	back_push(&head1,4);
	back_push(&head1,9);
	back_push(&head1,5);
	back_push(&head1,7);
	back_push(&head2,4);
	back_push(&head2,8);
	printReverse(head1);
	cout<<endl;
	printReverse(head2);
	cout<<endl;
	result=add(head1,head2);
	print(result);
	return 0;
}
