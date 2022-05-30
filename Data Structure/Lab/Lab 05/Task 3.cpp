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
	void Replace(int search, int rep)
	{
		int a=0;
		node *tmp=head;
		while(tmp!=NULL)
		{
			if(tmp->data==search)
			{
				tmp->data=rep;
			}
			tmp=tmp->next;
		}
	}
	void Display()
	{
		node *tmp=head;
		while(tmp!=NULL)
		{
			cout<<tmp->data<<" ";
			tmp=tmp->next;
		}
	}
};
int main()
{
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
	l.add_node(10);
	cout<<"Before Replacing Linked List's Element...!!"<<endl;
	l.Display();
	cout<<endl;
	l.Replace(2,11);
	cout<<endl<<endl<<"After Replacing Linked List's Element...!!"<<endl;
	l.Display();
}
