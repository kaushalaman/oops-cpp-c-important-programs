#include <iostream>
using namespace std;

struct node{
	int info;
	struct node *link;
};

void display(struct node *last){
	if(last==NULL){
		cout<<"list is empty"<<endl;
		return;
	}
	struct node *p=last->link;
	
	
	while(p->link != last->link){
		cout<<p->info<<" ";
		p=p->link;
	}
	if(p==last){
		cout<<p->info<<endl;
		return;
	}
	return;
}

struct node *addatbegin(struct node *last,int data){
	struct node *p,*temp;
	temp=new node;
	temp->info=data;
	if(last==NULL){
		last=temp;
		last->link=last;
		return last;
	}
	temp->link=last->link;
	last->link=temp;
	return last;
}

struct node *addatend(struct node *last, int data){
	if(last==NULL){
		cout<<"list is empty"<<endl;
		return last;
	}
	struct node *temp;
	temp=new node;
	temp->info=data;
	temp->link=last->link;
	last->link=temp;
	last=temp;
	return last;
}

struct node *addafter(struct node *last,int data,int item)
{
	struct node *temp,*p;
	if(last==NULL){
		cout<<"empty list"<<endl;
		return last;
	}
	if(last->link==last){
		if(last->info==item){
			temp=new node;
			temp->info=data;
			temp->link=last->link;
			last->link=temp;
			last=temp;
			return last;
		}
		cout<<"item not found"<<endl;
		return last;
	}
	p=last->link;
	while(p->link!=last->link){
		if(p->info==item){
			temp=new node;
			temp->info=data;
			temp->link=p->link;
			p->link=temp;
			return last;
		}
		p=p->link;
	}
	if(p->info==item){
		temp=new node;
		temp->info=data;
		temp->link=p->link;
		p->link=temp;
		last=temp;
	}
	return last;
}

struct node *create_list(struct node *last){
	last=NULL;
	int n;
	cout<<"Entern number of nodes "<<"\t";
	cin>>n;
	if(n==0){
		return last;
	}
	int data;
	cout<<"Enter beginning node data"<<endl;
	cin>>data;
	last=addatbegin(last,data);
	for(int i=2;i<=n;i++){
		cout<<"enter the element to be inserted"<<endl;
		cin>>data;
		last=addatend(last,data);
	}
	return last;
}

struct node *del(struct node *last,int data){
	struct node *temp,*p;
	if(last==NULL){
		cout<<"list is empty"<<endl;
		return last;
	}
	if(last->link==last){
		if(last->info==data){
			temp=last;
			last=NULL;
			delete temp;
			return last;
		}
		cout<<"item not found"<<endl;
		return last;
	}
	p=last->link;
	if(p->info==data){
		temp=p;
		last->link=temp->link;
		p=p->link;
		delete temp;
		return last;
	}

	while(p->link!=last->link)
	{
		if(p->link->info==data){
			temp=p->link;
			p->link=temp->link;
			temp->link=NULL;
			delete temp;
			return last;
		}
		p=p->link;
	}
	return last;

}
int main(){
	struct node *last;
	int data,choice,item,pos;
	last=NULL;
	while(1){
		cout<<"0. Add to empty list"<<endl;
		cout<<"1. Add at end"<<endl;
		cout<<"2. display"<<endl;
		cout<<"3. add after"<<endl;
		cout<<"4. Delete"<<endl;
		cout<<"5. create_list"<<endl;
		cout<<"6: quit"<<endl;

		cout<<"enter your choice"<<endl;
		cin>>choice;

		switch(choice){
			case 0:
				cout<<"Data to be inserted"<<endl;
				cin>>data;
				last=addatbegin(last,data);
				break;
			case 1:
				cout<<"Data to be inserted at end"<<endl;
				cin>>data;
				last=addatend(last,data);
				break;
			case 2:
				display(last);
				break;
			case 3:
				cout<<"enter data to be inserted"<<endl;
				cin>>data;
				cout<<"search item"<<endl;
				cin>>item;
				last=addafter(last,data,item);
				break;
			case 4:
				cout<<"enter the element to be deleted"<<endl;
				cin>>data;
				last=del(last,data);
				break;
			case 5:
				last=create_list(last);
				break;
			
			case 6:
				return 0;

			default:
				cout<<"no options"<<endl;
		}
	}
	return 0;
}