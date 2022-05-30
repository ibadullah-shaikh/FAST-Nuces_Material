#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
class Linked_List
{
	node *head , *tail;
public:
	Linked_List()
	{
		head= NULL;
		tail= NULL;
	}
	void add_node(int n)
	{
		node *tmp= new node;
		tmp->data =n;
		tmp->next=NULL;
		if(head==NULL)
		{
			head= tmp;
			tail= tmp;
		}
		else
		{
			tail->next=tmp;
			tail=tail->next;
		}
	}
	int Count(int n)
	{
		int a=0;
		node *tmp=head;
		while(tmp!=NULL)
		{
			if(tmp->data==n)
			{
				a++;
			}
			tmp=tmp->next;
		}
		return a;
	}
	void Display()
	{
		while(head->next->next!=NULL)
		{
			cout<<head->data<<" ";
		}
	}
};
int main()
{
	int count;
	Linked_List l;
	l.add_node(1);
	l.add_node(2);
	l.add_node(3);
	l.add_node(4);
	l.add_node(5);
	l.add_node(6);
	l.add_node(2);
	l.add_node(5);
	l.add_node(2);
	count=l.Count(2);
	cout<<"Element occurs "<<count<<" times..!!"<<endl;
}
