#include<iostream>
#include<fstream>
using namespace std;
class BST
{
	int data,Sum_array[10],cnt;
	BST *left, *right;
public:
	BST()
	{
		cnt=0;
		data=0;
		left=right=NULL;
	}
	BST(int x)
	{
		data=x;
		left=right=NULL;
	}
	BST* Insert(BST *node, int x)
	{
		if(!node)
		{
			return new BST(x);
		}
		if(x>node->data)
		{
			node->right=Insert(node->right, x);
		}
		else
		{
			node->left=Insert(node->left, x);
		}
		return node;
	}
	void Inorder(BST* node)
	{
		if(!node)
		{
			return;
		}
		Inorder(node->left);
		cout<<node->data<<" ";
		Inorder(node->right);
	}
	bool hasLeft(BST *node)
	{
		if(node->left!=NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool hasRight(BST *node)
	{
		if(node->right!=NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Sum(BST* node)
	{
		static int ans=0;
		if(!node)
		{
			return;
		}
		ans+=node->data;
		Sum(node->left);
		Sum(node->right);
		if( !(hasLeft(node)) && !(hasRight(node)) )
		{
			Sum_array[cnt]=ans;
			cnt++;
		}
		ans=ans-node->data;
	}
	void OutputToFile()
	{
		int i=0;
		ofstream file;
		file.open("output000.txt");
		if(!file)
		{
			cout<<"Output file can't opened."<<endl;
			exit(1);
		}
		for(i=0;i<cnt;i++)
		{
			file<<Sum_array[i];
			if(i!=cnt-1)
			{
				file<<"-";
			}
		}
	}
};
int main()
{
	BST *node=NULL, b;
	int cnt=0, arr[20],x=0,i=0;
	ifstream file;
	file.open("input002.txt");
	if(!file)
	{
		cout<<"File not found...!!"<<endl;
		exit(1);
	}
	while(1)
	{
		if(file>>x)
		{
			arr[cnt]=x;
			cnt++;
		}
		else
		{
			break;
		}
	}
	file.close();
	node=b.Insert(node,arr[0]);
	for(i=1;i<cnt;i++)
	{
		b.Insert(node, arr[i]);
	}
	b.Inorder(node);
	b.Sum(node);
	b.OutputToFile();
}
