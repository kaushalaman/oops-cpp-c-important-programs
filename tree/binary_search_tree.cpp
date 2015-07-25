#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct node{
	struct node *lchild;
	int info;
	struct node *rchild;
};

struct node *search(struct node *root,int dkey)
{
	if(root == NULL)
	{
		return root;
	}

	struct node *ptr = root;
	struct node *prev=ptr;

	while(ptr != NULL)
	{
		if(ptr->info == dkey)
		{
			cout<<"key found "<<ptr->info<<" "<<prev->info<<endl;
			return ptr;
		}
		else if(ptr->info < dkey)
		{
			if(ptr->rchild!=NULL)
			{
				prev=ptr;
				ptr=ptr->rchild;
			}
			else{
				return NULL;
			}
		}
		else if(ptr->info > dkey){
			if(ptr->lchild!=NULL)
			{
				prev=ptr;
				ptr=ptr->lchild;
			}
			else{
				return NULL;
			}
		}

	}

}

struct node *insert(struct node *root, int dkey)
{
	struct node *temp=new node;
	temp->info=dkey;
	if(root == NULL)
	{
		temp->lchild=NULL;
		temp->rchild=NULL;
		root=temp;
		return root;
	}
	struct node *ptr=root;
	struct node *prev=NULL;
	while(ptr!=NULL)
	{
		if(ptr->info==dkey)
		{
			cout<<"duplicate Keys"<<prev->info<<endl;
			return root;
		}
		else if(ptr->info > dkey)
		{
			prev=ptr;
			ptr=ptr->lchild;
		}
		else if(ptr->info < dkey)
		{
			prev=ptr;
			ptr=ptr->rchild;
		}

	}
	if(prev->info>dkey)
	{
		prev->lchild=temp;
		return root;
	}
	else if(prev->info<dkey){
	prev->rchild=temp;
	return root;}
}

struct node *del(struct node *root, int dkey)
{
	if(root == NULL)
	{
		cout<<"Not found"<<endl;
		return root;
	}
	struct node *ptr=root;
	struct node *prev,*next;
	while(1)
	{
		if(ptr->info==dkey)
		{
			if(ptr==root)
			{
				root=NULL;
				return root;
			}
			break;
		}
		else if(ptr->info > dkey)
		{
			prev=ptr;
			ptr=ptr->lchild;
		}
		else if(ptr->info < dkey)
		{
			prev=ptr;
			ptr=ptr->rchild;
		}
	}
	if(ptr->rchild == NULL && ptr->lchild == NULL)
	{
		if(dkey< prev->info)
		{
			prev->lchild=NULL;
		}
		else if(dkey > prev->info)
		{
			prev->rchild=NULL;
		}
		delete ptr;
		return root;
	}
	else if(ptr->rchild != NULL && ptr->lchild == NULL)
	{
		if(dkey<prev->info)
		{
			prev->lchild=ptr->rchild;
			delete ptr;
			return root;
		}
		else if(dkey>prev->info)
		{
			prev->rchild=ptr->rchild;
			delete ptr;
			return root;
		}
		
	}
	else if(ptr->lchild != NULL && ptr->rchild == NULL)
	{
		if(dkey<prev->info)
		{
			prev->lchild=ptr->lchild;
			delete ptr;
			return root;
		}
		else if(dkey>prev->info)
		{
			prev->rchild=ptr->lchild;
			delete ptr;
			return root;
		}
		

	}
	else if(ptr->rchild!=NULL && ptr->lchild!=NULL)
	{
		next=ptr->rchild;
		prev=next;
		while(next->lchild!=NULL)
		{
			prev=next;
			next=next->lchild;
		}
		ptr->info=next->info;
		if(next->rchild!=NULL)
		{
			prev->lchild=next->rchild;
		}
		else{
			prev->lchild=NULL;
		}
		delete next;
		return root;
	}
}


int main()
{
	struct node *root=NULL,*ptr;
	/*struct node *node1=new node;
	node1->info=10;
	struct node *node2=new node;
	node2->info=13;
	struct node *node3=new node;
	node3->info=9;
	struct node *node4=new node;
	node4->info=11;
	root=new node;
	if(!root)
		return 0;
	root->info=12;
	root->lchild=node1;
	root->rchild=node2;
	node1->lchild=node3;
	node1->rchild=node4;
	cout<<root->rchild->info<<endl;*/

	int choice,k;
	
	while(1)
	{
		cout<<endl;
		cout<<"1. search"<<endl;
		cout<<"2. Insert"<<endl;
		cout<<"3. Delete"<<endl;
		cout<<"4. Preorder Traversal"<<endl;
		cout<<"5. Inorder Traversal"<<endl;
		cout<<"6. Postorder Traversal"<<endl;
		cout<<"7. Height of tree"<<endl;
		cout<<"find minimum and maximum"<<endl;
		cout<<"Quit"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter the key to be searched"<<endl;
				cin>>k;
				ptr=search(root,k);

				if(ptr==NULL)
				{
					cout<<"Key not present"<<endl;
				}
				else{
					cout<<"key present"<<endl;
				}
				break;
			case 2:
				cout<<"enter the key to be inserted"<<endl;
				cin>>k;
				root=insert(root,k);
				break;
			case 3:
				cout<<"enter the key to be deleted"<<endl;
				cin>>k;
				root=del(root,k);
				break;
			/*case 4:
				preorder(root);
				break;
			case 5:
				inorder(root);
				break;
			case 6:
				postorder(root);
				break;
			case 7:
				cout<<"height of the tree"<<endl;
				cout<<height(root)<<endl;
				break;
			case 8:
				ptr=min(root);
				if(ptr!=NULL)
				{
					cout<<"minimum key is "<<ptr->info<<endl;
				}
				ptr=max(root);
				if(ptr!=NULL)
				{
					cout<<"maximum key is "<<ptr->info<<endl;
				}
				break;*/
			case 9:
				return 0;
			default:
				cout<<"wrong choice"<<endl;
		}
	}
}