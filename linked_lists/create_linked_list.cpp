#include <iostream>
using namespace std;

struct node{
	int info;
	struct node *link;
};

void display(struct node *start){
	struct node *p;
	p=start;
	if(start == NULL){
		cout<<"empty liist"<<endl;
		return;
	}
	while(p!=NULL){
		cout<<p->info<<" ";
		p=p->link;
	}
	cout<<endl;
	return;
}

void count(struct node *start){
	struct node *p;
	int count=0;
	p=start;
	while(p!=NULL){
		p=p->link;
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
		p=p->link;
		pos++;
	}
	cout<<"not found"<<endl;
	return;
}

struct node *addatbegin(struct node *start,int data){
	struct node *temp;
	temp=new node;
	temp->info=data;
	temp->link=start;
	start=temp;
	return start;
}

struct node *addatend(struct node *start,int data){
	struct node *temp,*p;
	temp=new node;
	temp->info=data;
	p=start;
	while(p->link!=NULL){
		p=p->link;
	}
	temp->link=p->link;
	p->link=temp;
	return start;
}

struct node *addbefore(struct node *start,int data,int item){
	struct node *p;
	
	if(start==NULL){
		cout<<"empty list";
		return start;
	}
	else if(start->info==item){
		struct node *temp;
		temp=new node;
		temp->info=data;
		temp->link=start;
		start=temp;
		return start;
	}
	p=start;
	while(p->link!=NULL){
		if(p->link->info==item){
			struct node *temp;
			temp=new node;
			temp->info=data;
			temp->link=p->link;
			p->link=temp;
			return start;
		}
		p=p->link;
	}
	cout<<"not found item"<<endl;
	return start;
}

struct node *addafter(struct node *start,int data, int item){
	struct node *tmp,*p;
	p=start;
	while(p!=NULL){
		if(p->info==item){
			tmp=new node;
			tmp->info=data;
			tmp->link=p->link;
			p->link=tmp;
			return start;
		}
		p=p->link;
	}
	cout<<"Not found item"<<endl;
	return start;

}

struct node *addatpos(struct node *start,int data,int pos){
	struct node *temp,*p;
	p=start;
	temp=new node;
	temp->info=data;
	if(pos==1){
		temp->link=start;
		start=temp;
		return start;
	}
	for(int i=1;i<pos-1 && p!=NULL;i++){
		p=p->link;
	}
	if(p==NULL){
		cout<<"less elements"<<endl;
		return start;
	}
	else{
		temp->link=p->link;
		p->link=temp;

	}
	return start;
}

struct node *insert_s(struct node *start,int data){
	struct node *temp,*ptr,*p;
	if(start==NULL){
		temp=new node;
		temp->info=data;
		temp->link=start;
		start=temp;
		return start;
	}

	if(data <= start->info){
		temp=new node;
		temp->info=data;
		temp->link=start;
		start=temp;
		return start;
	}
	p=start;ptr=start;
	while(p!=NULL){
		if(p->info<=data){
			ptr=p;
			p=p->link;
			continue;
		}
		break;
	}
	temp=new node;
	temp->info=data;
	temp->link=ptr->link;
	ptr->link=temp;
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
	struct node *temp,*p;
	p=start;
	if(start==NULL){
		cout<<"list is empty"<<endl;
		return start;
	}
	else if(start->info==data){
		temp=start;
		start=start->link;
		delete temp;
		return start;
	}
	p=start;
	while(p->link!=NULL){
		if(p->link->info==data){
			temp=p->link;
			p->link=temp->link;
			delete temp;
			return start;
		}
		p=p->link;
	}
	cout<<"no item"<<endl;
	return start;
}

struct node *reverse_list(struct node *start){
	struct node *prev,*ptr,*next;
	prev=NULL;
	ptr=start;
	while(ptr!=NULL){
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}
	start=prev;
	return start;
}
int main(){
	struct node *start=NULL;
	int choice,data,item,pos;
	while(1)
	{
		cout<<"1. create list"<<endl;
		cout<<"2. display"<<endl;
		cout<<"3. count"<<endl;
		cout<<"4. search"<<endl;
		cout<<"5. Add to empty list"<<endl;
		cout<<"6. Add at end"<<endl;
		cout<<"7. Add after node"<<endl;
		cout<<"8. Add before node "<<endl;
		cout<<"9. Add at position"<<endl;
		cout<<"10. Delete"<<endl;
		cout<<"11. reverse"<<endl;
		cout<<"12. sorted insert data"<<endl;
		cout<<"13: quit"<<endl;

		cout<<"enter your choice"<<endl;
		cin>>choice;

		switch(choice){
			case 1:
				start=create_list(start);
				break;
			case 2:
				display(start);
				break;
			case 3:
				count(start);
				break;
			case 4:
				cout<<"enter the element to be searched"<<endl;
				cin>>data;
				search(start,data);
				break;
			case 5:
				cout<<"enter the element to be inserted"<<endl;
				cin>>data;
				start=addatbegin(start,data);
				break;
			case 6:
				cout<<"enter the element to be inserted at end"<<endl;
				cin>>data;
				start=addatend(start,data);
				break;
			case 7:
				cout<<"enter the element to be inserted"<<endl;
				cin>>data;
				cout<<"enter the element after which to insert"<<endl;
				cin>>item;
				start=addafter(start,data,item);
				break;
			case 8:
				cout<<"enter the element to be inserted"<<endl;
				cin>>data;
				cout<<"enter the element before which to insert"<<endl;
				cin>>item;
				start=addbefore(start,data,item);
				break;
			case 9:
				cout<<"enter the element to be inserted"<<endl;
				cin>>data;
				cout<<"enter the position where to insert"<<endl;
				cin>>pos;
				start=addatpos(start,data,pos);
				break;
			case 10:
				cout<<"enter the element to be deleted"<<endl;
				cin>>data;
				start=del(start,data);
				break;
			case 11:
				start=reverse_list(start);
				break;
			case 12:
				cout<<"insert data"<<endl;
				cin>>data;
				start=insert_s(start,data);
				break;
			case 13:
				return 0;
			default:
				cout<<"Wrong choice"<<endl;
		}

	}
	return 0;
}