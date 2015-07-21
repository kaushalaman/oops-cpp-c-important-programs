#include <iostream>
using namespace std;

struct stacknode{
	int data;
	int top;
	struct stacknode *next;
};

struct stacknode *create_stack()
{
	struct stacknode *start=new stacknode;
	if(!start){
		cout<<"memory not allocated"<<endl;
		return start;
	}
	start->top=-1;
	start->data=0;
	start->next=NULL;
	return start;
}

int isempty(struct stacknode *start)
{
	return(start->top==-1);
}



struct stacknode *push(struct stacknode *start,int item)
{

	struct stacknode *temp=new stacknode;
	temp->next=start;
	temp->data=item;
	temp->top=(start->top)+1;
	start=temp;
	return start;
}

struct stacknode *pop(struct stacknode *start)
{
	if(isempty(start))
	{
		cout<<"stack underflow"<<endl;
	}
	else{
		struct stacknode *temp;
		temp=start;
		start=start->next;
		delete temp;
	}

	return start;
}

void delete_stack(struct stacknode *start)
{
	struct stacknode *temp;
	temp=start;
	struct stacknode *next;
	while(temp!=NULL)
	{
		next=temp->next;
		delete temp;
		temp=next;
	}

}

void size(struct stacknode *start)
{
	int count=0;
	struct stacknode *temp=start;
	while(temp!=NULL)
	{
		temp=temp->next;
		count++;
	}
	cout<<count-1<<endl;
}

int main()
{
	struct stacknode *s=create_stack();
	cout<<s->top<<" "<<s->data<<" "<<s->next<<endl;
	s=push(s,1);
	s=push(s,2);
	s=push(s,3);
	s=pop(s);
	size(s);
	cout<<"top is now: "<<s->top<<" top value is: "<<s->data<<endl;
	delete_stack(s);
	return 0;
}