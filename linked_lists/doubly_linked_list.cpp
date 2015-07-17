#include <iostream>
using namespace std;

struct node{
	struct node *prev;
	int info;
	struct node *next;
};

void display(struct node *start){
	struct node *p=start;
	if(start==NULL){
		cout<<"list is empty"<<endl;
		return;
	}
	while(p!=NULL){
		cout<<p->info<<" ";
		p=p->next; 
	}
	cout<<endl;
	return;
}

void count(struct node *start){
	struct node *p;
	int count=0;
	p=start;
	while(p!=NULL){
		p=p->next;
		count++;
	}
	cout<<"count is "<<count<<endl;
	return;
}

void search(struct node *start, int item){
	struct node *p=start;
	int pos=1;
	while(p!=NULL){
		if(p->info == item){
			cout<<"item found "<<p->info<<endl;
			cout<<"pos is "<<pos<<endl;
			return;
		}
		p=p->next;
		pos++;
	}
	cout<<"not found"<<endl;
	return;
}

struct node *addatbegin(struct node *start,int data){
	struct node *temp;
	temp=new node;
	temp->info=data;
	temp->next=start;
	start=temp;
	temp->prev=NULL;
	if(temp->next!=NULL){
		temp->next->prev=temp;
	}
	return start;
}

struct node *addatend(struct node *start,int data){
	struct node *temp,*p;
	temp=new node;
	temp->info=data;
	if(start==NULL){
		start=temp;
		temp->prev=NULL;
		temp->next=NULL;
		return start;
	}
	p=start;
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=temp;
	temp->next=NULL;
	temp->prev=p;
	return start;
}
 
struct node *addafter(struct node *start,int data,int item){
	struct node *temp,*p;
	p=start;
	while(p!=NULL){
		if(p->info==item){
			temp=new node;
			temp->info=data;
			temp->prev=p;
			temp->next=p->next;
			p->next=temp;
			if(temp->next!=NULL)
				temp->next->prev=temp;
			return start;
		}
		p=p->next;
	}
	cout<<"no item found"<<endl;
	return start;
}

struct node *addbefore(struct node *start,int data, int item){
	struct node *temp,*p;
	p=start;
	if(start==NULL){
		cout<<"Empty List"<<endl;
		return start;
	}
	if(start->info==item){
		temp=new node;
		temp->info=data;
		temp->next=start;
		temp->prev=NULL;
		start=temp;
		temp->next->prev=temp;
		return start;
	}
	while(p->next!=NULL){
		if(p->next->info==item){
			temp=new node;
			temp->info=data;
			temp->next=p->next;
			temp->prev=p;
			p->next=temp;
			temp->next->prev=temp;
			return start;
		}
		p=p->next;
	}
	cout<<"no items found"<<endl;
	return start;

}

struct node *addatpos(struct node *start,int data,int pos){
	struct node *temp,*p;
	p=start;
	temp=new node;
	temp->info=data;
	if(pos==1){
		temp->next=start;
		start=temp;
		temp->prev=NULL;
		temp->next->prev=temp;
		return start;
	}
	for(int i=1;i<pos-1 && p!=NULL;i++){
		p=p->next;
	}
	if(p==NULL){
		cout<<"less elements"<<endl;
		return start;
	}
	else{
		temp->next=p->next;
		temp->prev=p;
		p->next=temp;
		if(temp->next!=NULL){
		temp->next->prev=temp;}

	}
	return start;
}

struct node *create_list(struct node *start){
	start=NULL;
	int n;
	cout<<"Entern number of nodes "<<"\t";
	cin>>n;
	if(n==0){
		return start;
	}
	int data;
	cout<<"Enter beginning node data"<<endl;
	cin>>data;
	start=addatbegin(start,data);
	for(int i=2;i<=n;i++){
		cout<<"enter the element to be inserted"<<endl;
		cin>>data;
		start=addatend(start,data);
	}
	return start;
}

struct node *del(struct node *start,int data){
	struct node *tmp,*p;
	if(start==NULL){
		cout<<"empty list"<<endl;
	}
	if(start->info==data){
		tmp=start;
		if(start->next!=NULL){
			start=start->next;
			tmp->next->prev=NULL;
			delete tmp;
			return start;
		}
		start=NULL;
		delete tmp;
		return start;

	}
	p=start;
	while(p->next!=NULL){
		if(p->next->info==data){
			tmp=p->next;
			p->next=tmp->next;
			tmp->next->prev=tmp->prev;
			delete tmp;
			return start;
		}
		p=p->next;
	}
	cout<<"no item found";
	return start;
}

struct node *reverse(struct node *start){
	struct node *p1,*p2;
	p1=start;
	p2=p1->next;
	p1->next=NULL;
	p1->prev=p2;
	while(p2!=NULL){
		p2->prev=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p2->prev;
	}
	start=p1;
	cout<<"list reversed"<<endl;
	return start;
}

int main(){
	struct node *start;
	int data,choice,item,pos;
	start=NULL;
	while(1){
		cout<<"0. Add to empty list"<<endl;
		cout<<"1. Add at end"<<endl;
		cout<<"2. display"<<endl;
		cout<<"3. add after"<<endl;
		cout<<"4. Add before"<<endl;
		cout<<"5. Add at position"<<endl;
		cout<<"6. Delete"<<endl;
		cout<<"7. reverse"<<endl;
		cout<<"8. create_list"<<endl;
		cout<<"9. count"<<endl;
		cout<<"10. search"<<endl;
		cout<<"11: quit"<<endl;

		cout<<"enter your choice"<<endl;
		cin>>choice;

		switch(choice){
			case 0:
				cout<<"Data to be inserted"<<endl;
				cin>>data;
				start=addatbegin(start,data);
				break;
			case 1:
				cout<<"Data to be inserted at end"<<endl;
				cin>>data;
				start=addatend(start,data);
				break;
			case 2:
				display(start);
				break;
			case 3:
				cout<<"enter data to be inserted"<<endl;
				cin>>data;
				cout<<"search item"<<endl;
				cin>>item;
				start=addafter(start,data,item);
				break;
			case 4:
				cout<<"enter data to be inserted"<<endl;
				cin>>data;
				cout<<"search item"<<endl;
				cin>>item;
				start=addbefore(start,data,item);
				break;
			case 5:
				cout<<"enter the element to be inserted"<<endl;
				cin>>data;
				cout<<"enter the position where to insert"<<endl;
				cin>>pos;
				start=addatpos(start,data,pos);
				break;
			case 6:
				cout<<"enter the element to be deleted"<<endl;
				cin>>data;
				start=del(start,data);
				break;
			case 7:
				start=reverse(start);
				break;
			case 8:
				start=create_list(start);
				break;
			case 9:
				count(start);
				break;
			case 10:
				cout<<"enter the element to be searched"<<endl;
				cin>>data;
				search(start,data);
				break;
			case 11:
				return 0;

			default:
				cout<<"no options"<<endl;
		}
	}
	return 0;
}
