#include<iostream>
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
	int Calculate_height(BSTree* node)
	{
		if (node->left==NULL && node->right==NULL) 
        {
			return 0;
		}
		int l=0;
		if(node->left!=NULL)
		{
			l=Calculate_height(node->left);
		}
		int r=0;
		if(node->right!=NULL)
		{
			r=Calculate_height(node->right);
		}
		return(max(l,r)+1);
	}
	void Sum_Level(BSTree* node,int sum[], int cnt)
	{
		if(!node)
		{
			return;
		}
		sum[cnt]+=node->data;
		if(node->left)
		{
			Sum_Level(node->left,sum,cnt+1);
		}
		if(node->right)
		{
			Sum_Level(node->right,sum,cnt+1);
		}
	}
	void Output_to_File(int sum[], int height)
	{
		ofstream out;
		out.open("output000.txt");
		if(!out)
		{
			cout<<"File not found...!!"<<endl;
			exit(1);
		}
		for(int i=0;i<height-1;i++)
		{
			out<<sum[i]<<"-";
		}
		out<<sum[height-1];
		out.close();
	}
};
int main()
{
	BSTree *node=NULL, b;
	int x=0;
	ifstream in;
	in.open("input002.txt");
	if(!in)
	{
		cout<<"File not found...!!"<<endl;
		exit(1);
	}
	in>>x;
	node=b.InsertNode(node,x);
	while(!in.eof())
	{
		in>>x;
		b.InsertNode(node,x);
	}
	in.close();
	b.Inorder(node);
	int height=b.Calculate_height(node);
	height+=1;
	int sum[height]={0};
	b.Sum_Level(node,sum,0);
	b.Output_to_File(sum,height);
}
