#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct node{
	struct node *lchild;
	int info;
	struct node *rchild;
};

void preorder(struct node *root)
{
	if(root==NULL)
		return;
	cout<<root->info<<" ";
	preorder(root->lchild);
	preorder(root->rchild);
}

void postorder(struct node *root)
{
	if(root==NULL)
		return;
	
	postorder(root->lchild);
	postorder(root->rchild);
	cout<<root->info<<" ";
}

void inorder(struct node *root)
{
	if(root==NULL)
		return;
	
	inorder(root->lchild);
	cout<<root->info<<" ";
	inorder(root->rchild);
}

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

int min(struct node *root)
{
	if(root==NULL)
	{
		cout<<"tree is empty"<<endl;
		return 0;
	}
	struct node *ptr=root;
	int count=0;
	while(ptr->lchild!=NULL)
	{
		ptr=ptr->lchild;
		count++;
	}
	return ptr->info;
}

int max(struct node *root)
{
	if(root==NULL)
	{
		cout<<"tree is empty"<<endl;
		return 0;
	}
	struct node *ptr=root;
	int count=0;
	while(ptr->rchild!=NULL)
	{
		ptr=ptr->rchild;
		count++;
	}
	return ptr->info;
}

int height(struct node *root)
{
	int l_height,r_height;
	if(root==NULL)
	{
		return 0;
	}
	else{
		l_height=height(root->lchild);
		r_height=height(root->rchild);
		if(l_height>r_height)
		{
			return(l_height+1);
		}
		else{
			return(r_height+1);
		}
	}

}


int main()
{
	struct node *root=NULL,*ptr;
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
		cout<<"8: find minimum and maximum"<<endl;
		cout<<"9: Quit"<<endl;

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
			case 4:
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
				cout<<"Minimum key is "<<min(root)<<endl;
				cout<<"Maximum key is "<<max(root)<<endl;
				break;

			case 9:
				return 0;
			default:
				cout<<"wrong choice"<<endl;
		}
	}
	return 0;
}