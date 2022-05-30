#include<iostream>
using namespace std;
struct node
{
	node *next;
	int data;
};
class Linked_List
{
	node *head, *tail;
public:
	Linked_List()
	{
		head=NULL;
		tail=NULL;
	}
	void add_node(int x)
	{
		node *tmp=new node;
		tmp->data=x;
		tmp->next=NULL;
		if(head==NULL)
		{
			head=tmp;
			tail=tmp;
		}
		else
		{
			tail->next=tmp;
			tail=tail->next;
		}
	}
	int GetNth(int x)
	{
		int a,n=0;
		node *tmp = head;
		while(n!=x+1)
		{
			if(n==x)
			{
				a=tmp->data;
				return a;
			}
			n++;
			tmp=tmp->next;
		}
	}
};
int main()
{
	Linked_List l1;
	int n=7;				// 7 Linked List Elements
	l1.add_node(4);
	l1.add_node(2);
	l1.add_node(3);
	l1.add_node(4);
	l1.add_node(5);
	l1.add_node(6);
	l1.add_node(7);
	int z=5,x;			// z=5 to search
	if(z<0 || z>n-1)
	{
		cout<<"Unavailable Index...!!"<<endl;
		exit(1);
	}
	else
	{
		x=l1.GetNth(z);
		cout<<"At "<<z<<" Address, Element is: "<<x<<endl;
	}
}
