#include <iostream>
using namespace std;
struct arraystack{
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
 	s->capacity=5;
 	s->array=new int[s->capacity];
 	if(!s->array)
 		return NULL;
 	return s;
}

int isempty(struct arraystack *s)
{
 	return(s->top == -1);
}

int isfull(struct arraystack *s)
{
	return(s->top == (s->capacity)-1);
}

void push(struct arraystack *s, int data)
{
	if(isfull(s)){
 		cout<<"stackoverflow";
 		return;
 	}
 	s->array[++s->top]=data;
 	cout<<"top "<<s->top<<endl;
}

int pop(struct arraystack *s)
{
 	if(isempty(s))
 	{
 		cout<<"stack underflow"<<endl;
 		return 0;
 	}
 	return(s->array[s->top--]);
}

void delete_stack(struct arraystack *s)
{
 	if(s){
 		if(s->array){
 			delete s->array;
 		}
 		delete s;
 	}
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