#include<iostream>
#include<queue>
using namespace std;
class BT
{
	int data;
	BT *left, *right;
public:
	BT()
	{
		data=0;
		left=right=NULL;
	}
	BT(int x)
	{
		data=x;
		left=right=NULL;
	}
	BT *Insert(BT *node, int x)
	{
		if(!node)
		{
			return new BT(x);
		}
		queue<BT*>q;
		q.push(node);
		while(!q.empty())
		{
			BT* temp=q.front();
			q.pop();
			if(temp->left!=NULL)
			{
				q.push(temp->left);
			}
			else
			{
				temp->left= BT(x);
				return node;
			}
			if(temp->right!=NULL)
			{
				q.push(temp->right);
			}
			else
			{
				temp->right=BT(x);
				return node;
			}
		}
	}
	void Inorder(BT *node)
	{
		Inorder(node->left);
		cout<<node->data<<" ";
		Inorder(node->right);
	}
};

int main()
{
	BT *node, b;
	node=b.Insert(node, 5);
	b.Insert(node,2);
	b.Insert(node,6);
	b.Inorder(node);
}
