#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *new_node(int val)
{
	struct node *newnode=new struct node;
	newnode->data=val;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}


void inorder(struct node *root)
{
	if(root==NULL)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}


struct node* insert(struct node *root, int val)
{
	if(root==NULL)
	return new_node(val);
	
	if(root->data<val)
	root->right=insert(root->right,val);
	
	else if(root->data>val)
	root->left=insert(root->left,val);
	
	return root;
}

struct node* findLargestNode(struct node *root)
{
	while(root->right!=NULL)
	{
		root = root->right;
	}
	return root;	
}

void del(struct node *&root, int val)
{
	struct node *temp;

	if(root == NULL)
	{
		cout<<val<<"Not found in tree"<<endl;
	}
	else if(val<root->data)
	{
		del(root->left,val);
	}
	else if(val> root->data)
	{
		del(root->right,val);
	}
	else if(root->left && root->right)
	{
		temp = findLargestNode(root->left);
		root->data = temp->data;
		del(root->left, temp->data);
	}
	else
	{
		temp = root;
		if(root->left == NULL && root->right == NULL)
			root=NULL;
		else if(root->left!=NULL)
			root = root->left;
		else
			root = root->left;
		
		free(temp);
	}

}

int main(){
	struct node *root=NULL;
	cout<<"Main Menu"<<endl;
	cout<<"1.Insert"<<endl;
	cout<<"2.Display"<<endl;
	cout<<"3.Delete"<<endl;
	cout<<"4.EXIT"<<endl;
	int k,val;
	while(1)
	{
		cout<<"Enter your choice";
		cin>>k;
		switch(k)
		{
			case 1:
				cout<<"Enter the number to insert in the tree"<<endl;
				cin>>val;
				root=insert(root,val);
				break;
			case 2:
				inorder(root);
				break;

			case 3:
				cout<<"Enter value to delete: ";
				cin>> val;
				del(root, val);
				break;

			case 4:
				exit(0);
			default:
				cout<<"INVALID INPUT";
				break;
		}
	}
return 0;
}

