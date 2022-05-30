#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
class BSTree
{
	int data;
	BSTree *left, *right;
public:
	BSTree()
	{
		data=0;
		left=NULL;
		right=NULL;
	}
	BSTree(int x)
	{
		data=x;
		left=NULL;
		right=NULL;
	}
	BSTree* InsertNode(BSTree *node, int x)
	{
		if(!node)
		{
			return new BSTree(x);
		}
		if(x>node->data)
		{
			node->right=InsertNode(node->right, x);
		}
		else
		{
			node->left=InsertNode(node->left, x);
		}
		return node;
	}
	void Inorder(BSTree* node)
	{
		if(!node)
		{
			return;
		}
		Inorder(node->left);
		cout<<node->data<<" ";
		Inorder(node->right);
	}
	void PreOrder(BSTree* node)
	{
		cout<<node->data<<" ";
		Inorder(node->left);
		Inorder(node->right);
	}
	void PostOrder(BSTree* node)
	{
		Inorder(node->left);
		Inorder(node->right);
		cout<<node->data<<" ";
	}
	BSTree* Delete(BSTree* node, int data)
	{
		if(!node)
		{
			return node;
		}
		if(data<node->data)
		{
			node->left=Delete(node->left,data);
		}
		if(data>node->data)
		{
			node->right=Delete(node->right,data);
		}
		else
		{
			if(node->left==NULL)
			{
				BSTree *temp=node->left;
				free(node);
				return temp;
			}
			else if(node->right==NULL)
			{
				BSTree *temp=node->right;
				free(node);
				return temp;
			}
			else
			{
				BSTree* temp=node->right;
				while(temp && temp->left!=NULL)
				{
					temp=temp->left;
				}
				node->data=temp->data;
				node->right=Delete(node->right, node->data);
			}
		}
		return node;
	}
	int Height(BSTree* node)
	{
		if(!node)
		{
			return 0;
		}
		if(node->left==NULL && node->right==NULL)
		{
			return 1;
		}
		int l=0;
		l=Height(node->left);
		int r=0;
		r=Height(node->right);
		
		return( max(l,r)+1 );
	}
};
int main()
{
	BSTree *node=NULL, b;
	node=b.InsertNode(node, 3);
	b.InsertNode(node,1);
	b.InsertNode(node,5);
	b.InsertNode(node,7);
	b.InsertNode(node,2);
	b.InsertNode(node,9);
	cout<<"Inorder: ";
	b.Inorder(node);
	cout<<endl<<endl<<"Pre-order: ";
	b.PreOrder(node);
	cout<<endl<<endl<<"Post-order: ";
	b.PostOrder(node);
	cout<<endl<<endl<<"After deleting 9 PostOrder BST: ";
	b.Delete(node,9);
	b.PostOrder(node);
	int h=b.Height(node);
	h++;
	cout<<endl<<"Height: "<<h<<endl;
}
