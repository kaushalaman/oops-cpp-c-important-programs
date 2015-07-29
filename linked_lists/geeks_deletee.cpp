#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

struct node{
	int data;
	struct node *next;
	bool visited=false;
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
int detect_loop(Node **head_ref)
{
	if(*head_ref==NULL)
	{
		cout<<"no loop"<<endl;
		return 0;
	}
	Node *ptr=*head_ref;

	while(1)
	{
		ptr->visited=true;
		ptr=ptr->next;
		if(ptr->visited)
		{
			cout<<"loop is detected at "<<ptr->data<<endl;
			return 0;
		}
	}

	
}
void middle_element(Node **head_ref)
{
	if(*head_ref==NULL)
	{
		cout<<"not found middle element"<<endl;
		return;
	}	
	Node *ptr1=*head_ref;
	if(!ptr1){
		return;
	}
	if(ptr1->next==NULL)
	{
		return;
	}
	Node *ptr2=*head_ref;
	if(!ptr2){
		return;
	}
	if(ptr1==*head_ref && ptr2->next->next==NULL)
	{
		cout<<"middle node value is "<<ptr1->data<<endl;
		return;
	}
	while(ptr2->next != NULL)
	{
		ptr2=ptr2->next->next;
		ptr1=ptr1->next;
		if(ptr2==NULL){
			break;
		}
	}
	cout<<"middle node value is "<<ptr1->data<<endl;
	return;

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
void nth_node_back(Node **head_ref,int n)
{
	Node *current=*head_ref;
	int count=0;
	while(current!=NULL){
		count++;
		current=current->next;
	}
	if(n>count)
	{
		cout<<"Not so list items"<<endl;
		return;
	}
	int m=(count-n)+1;
	current=*head_ref;
	while(m!=1)
	{
		current=current->next;
		m--;
	}
	cout<<current->data<<endl;
	return;
}

void reverse(Node **head_ref){
	Node *prev,*link;
	Node *current=*head_ref;
	prev=current;
	link=current->next;
	current=link;
	prev->next=NULL;
	while(current!=NULL)
	{
		link=current->next;
		current->next=prev;
		prev=current;
		current=link;
	}
	*head_ref=prev;
}

void delete_list(Node **head_ref)
{
	Node *current=*head_ref;
	Node *temp=NULL;
	while(current!=NULL)
	{
		temp=current;
		current=current->next;
		delete temp;
	}
	*head_ref=NULL;
	cout<<"List is deleted"<<endl;
	return;
}

void delete_list_single(Node **head_ref)
{
	Node *current=*head_ref;
	*head_ref=NULL;
	Node *temp=NULL;
	while(current!=NULL)
	{
		temp=current;
		current=current->next;
		delete temp;
	}
	cout<<"List is deleted"<<endl;
	return;
}

void count_int(Node **head_ref,int val)
{
	Node *current=*head_ref;
	int count=0;
	while(current!=NULL)
	{
		if(current->data==val){
			count++;
		}
		current=current->next;

	}
	cout<<count<<endl;
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
	/*Node *ptr=head;
	Node *ptr1;
	ptr1=ptr->next->next->next;
	ptr1->next->next=ptr1;
	detect_loop(&head);*/
	insert_after(head->next,1);
	print(head);
	node_delete(&head,0);
	print(head);
	cout<<getcount(head)<<endl;
	cout<<search(head,2)<<endl;
	cout<<search(head,3)<<endl;
	getnth(head,0);
	Node *ptr2=head; 
	cout<<ptr2->next->next->next->data<<endl;
	delete_pointer_node(ptr2->next->next->next);
	print(head);
	middle_element(&head);
	nth_node_back(&head,5);
	count_int(&head,1);
	count_int(&head,2);
	reverse(&head);
	print(head);
	delete_list_single(&head);
	print(head);
	return 0;
}