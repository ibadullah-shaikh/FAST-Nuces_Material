#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	node *next;
};
class SLL
{
	node *head, *tail;
public:
	SLL()
	{
		head=NULL;
		tail=NULL;
	}
	void add_node(int x)
	{
		node *temp=new node;
		temp->data=x;
		temp->next=NULL;
		if(head==NULL)
		{
			head=temp;
			tail=temp;
		}
		else
		{
			temp->next=head;
			head=temp;
		}
	}
	void sort()
	{
		node *curr = head;
		node *temp= new node;
		while(curr!=NULL)
		{
			temp=curr->next;
			while(temp!=NULL)
			{
				if(curr->data > temp->data)
				{
					int tmp;
					tmp= curr->data;
					curr->data = temp->data;
					temp->data = tmp;
				}
				temp = temp->next;
			}
			curr= curr->next;
		}
	}
	void remove_dup()
	{
		node *curr= head;
		node *temp=new node;
		while(curr!=NULL)
		{
			temp= curr->next;
			while(temp!=NULL)
			{
				if(curr->data == temp->data)
				{
					curr->next= temp->next;
				}
				temp= temp->next;
			}
			curr= curr->next;
		}
	}
	void Reverse()
	{
		node *curr= head;
		node *nxt=NULL, *prev=NULL;
		while(curr!=NULL)
		{
			nxt=curr->next;
			curr->next=prev;
			prev=curr;
			curr=nxt;
		}
		head=prev;
	}
	void print()
	{
		node *temp=head;
		while(temp!= NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		
	}
};
int main()
{
	SLL obj;
	obj.add_node(3);
	obj.add_node(2);
	obj.add_node(8);
	obj.add_node(7);
	obj.add_node(1);
	obj.add_node(6);
	obj.add_node(5);
	obj.add_node(10);
	obj.add_node(9);
	obj.add_node(2);
	obj.add_node(4);
	obj.add_node(10);
	obj.add_node(5);
	
	obj.print();
	cout<<endl<<endl;
	
	obj.sort();
	obj.print();
	cout<<endl<<endl;
	
	obj.Reverse();
	obj.remove_dup();
	obj.print();
	
	cout<<endl<<endl;
	obj.Reverse();
	obj.print();
}
