#include<iostream>
#include<stdlib.h>
using namespace std;
struct AVL
{
	int data,height;
	AVL *left, *right;
};
int height(AVL *node)
{
	if(node==NULL)
	{
		return 0;
	}
	else
	{
		return node->height;
	}
}
AVL *newNode(int x)
{
	AVL *temp= new AVL;
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	temp->height=1;
	return temp;
}
AVL *rightRotate(AVL *node)
{
	AVL *l=node->left;
	AVL *r=l->right;
	l->right=node;
	node->left=r;
	node->height=max(height(node->left),height(node->right))+1;
	l->height=max(height(l->left),height(l->right))+1;
	return l;
}
AVL *leftRotate(AVL *node)  
{
	AVL *r=node->right;
	AVL *l=r->left;
	r->left=node;
	node->right=l;
	node->height=max(height(node->left),height(node->right)) + 1;
	r->height=max(height(r->left),height(r->right)) + 1;
	return r;
}
int getBalance(AVL *node)  
{
	if(node==NULL)
	{
		return 0;
	}
	return height(node->left) - height(node->right);  
}
AVL *Insert(AVL *node, int x)
{
	if(node==NULL)
	{
		return newNode(x);
	}
	if(x<node->data)
	{
		node->left=Insert(node->left,x);
	}
	else if(x>node->data)
	{
		node->right=Insert(node->right,x);
	}
	else
	{
		return node;
	}
	node->height=1+max(height(node->left),height(node->right));
	int balance= getBalance(node);
	if(balance>1 && x<node->left->data)
	{
		return rightRotate(node);
	}
	if(balance<-1 && x>node->right->data)
	{
		return leftRotate(node);
	}
	if(balance>1 && x>node->left->data)
	{
		node->left=leftRotate(node->left);
		return rightRotate(node);
	}
	if(balance<-1 && x<node->right->data)
	{
		node->right=rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}
AVL *minValue(AVL *node)
{
	AVL *temp=node;
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp;
}
void PreOrder(AVL *node)
{
	if(node==NULL)
	{
		return;
	}
	cout<<node->data<<" ";
	PreOrder(node->left);
	PreOrder(node->right);
}
AVL *Delete(AVL *node, int x)
{
	if(node==NULL)
	{
		return node;
	}
	if(x<node->data)
	{
		node->left=Delete(node->left,x);
	}
	else if (x>node->data)
	{
		node->right=Delete(node->right,x);
	}
	if(node->data==x)
	{
		if(node->left==NULL || node->right==NULL)
		{
			AVL *temp=node->left ? node->left: node->right;
			if(temp==NULL)
			{
				temp=node;
				node=NULL;
			}
			else
			{
				*node=*temp;
			}
			free(temp);
		}
		else
		{
			AVL *temp=minValue(node->right);
			node->data=temp->data;
			node->right= Delete(node->right,temp->data);
		}
	}
	if(node==NULL)
	{
		return node;
	}
	node->height=1+max(height(node->left),height(node->right));
	int balance=getBalance(node);
	if(balance>1 && x<node->left->data)
	{
		return rightRotate(node);
	}
	if(balance<-1 && x>node->right->data)
	{
		return leftRotate(node);
	}
	if(balance>1 && x>node->left->data)
	{
		node->left=leftRotate(node->left);
		return rightRotate(node);
	}
	if(balance<-1 && x<node->right->data)
	{
		node->right=rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}
int main()
{
	AVL *root=NULL;
	root = Insert(root, 10);  
    root = Insert(root, 20);  
    root = Insert(root, 30);  
    root = Insert(root, 40);  
    root = Insert(root, 50);  
    root = Insert(root, 25);
	PreOrder(root);
	root = Delete(root, 30);
	cout<<endl;
	PreOrder(root);
}
