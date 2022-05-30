#include<iostream>
#include<fstream>
using namespace std;
class BST
{
	int array[15],i,cnt;
	int data;
	BST *left, *right;
public:
	BST()
	{
		i=0;
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
	int Calculate_height(BST* node)
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
		if(l>r)
		{
			l+=1;
			return l;
		}
		if(r>l)
		{
			r+=1;
			return r;
		}
		if(l==r)
		{
			l+=1;
			return l;
		}
	}
	void Sum(BST* node,int sum[], int cnt)
	{
		if(!node)
		{
			return;
		}
		sum[cnt]+=node->data;
		if(node->left)
		{
			Sum(node->left,sum,cnt+1);
		}
		if(node->right)
		{
			Sum(node->right,sum,cnt+1);
		}
	}
	void minheap(BST *node)
	{
		if(!node)
		{
			return;
		}
		array[cnt]=node->data;
		cnt++;
		minheap(node->left);
		minheap(node->right);
		for(i=0;i<cnt;i++)
		{
			for(int j=i+1;j<cnt;j++)
			{
				if(array[i]>array[j])
				{
					int temp=array[i];
					array[i]=array[j];
					array[j]=temp;
				}
			}
		}
	}
	void disp()
	{
		for(i=0;i<cnt;i++)
		{
			cout<<array[i]<<" ";
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
	int h=b.Calculate_height(node);
	h++;
	int sum[h]={0};
	b.Sum(node,sum,0);
	ofstream fil;
	fil.open("output000.txt", ios::trunc);
	if(!fil)
	{
		cout<<"File not found...!!"<<endl;
		exit(1);
	}
	for(i=0;i<h;i++)
	{
		fil<<sum[i];
		if(i!=h-1)
		{
			fil<<"-";
		}
	}
	cout<<endl;
	b.minheap(node);
	b.disp();
}
