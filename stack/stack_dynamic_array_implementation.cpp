#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
using namespace std;

struct arraystack
{
	int top;
	int capacity;
	int *array;
};

struct arraystack *create_stack()
{
	struct arraystack *s=new arraystack;
	if(!s)
		return NULL;
	s->top=-1;
	s->capacity=1;
	s->array=new int[s->capacity];
	if(!s->array)
	{
		return NULL;
	}
	return s;
}

int isfull(struct arraystack *s)
{
	return(s->top==s->capacity-1);
}

int isempty(struct arraystack *s)
{
	return(s->top==-1);
}

void doubling(struct arraystack *s)
{
	s->capacity=(s->capacity)*2;
	s->array=(int *)realloc(s->array,s->capacity);
}

void push(struct arraystack *s,int data)
{
	if(isfull(s))
	{
		doubling(s);

	}
	s->array[++s->top]=data;
}

int pop(struct arraystack *s)
{
	if(isempty(s))
	{
		cout<<"underflow "<<endl;
		return 0;
	}
	return(s->array[s->top--]);
}

int main()
{
	struct arraystack *s=create_stack();
 	cout<<s->top<<" "<<s->capacity<<endl;
 	push(s,0);
 	push(s,2);
 	push(s,3);
 	cout<<"popping "<<pop(s)<<endl;
 	cout<<"popping "<<pop(s)<<endl;
 	cout<<s->top<<endl;
 	return 0;
}