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
	void add_at_begin(int x)
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
	void add_at_end(int x)
	{
		node *curr = head;
		node *temp = new node;
		temp->data=x;
		temp->next=NULL;
		if(head==NULL)
		{
			head=temp;
			tail=temp;
		}
		else
		{
			while(curr->next!=NULL)
			{
				curr=curr->next;
			}
			curr->next=temp;
		}
	}
	void add_at_posi(int x, int posi)
	{
		node *curr=head;
		node *temp= new node;
		temp->data=x;
		temp->next=NULL;
		if(head==NULL)
		{
			cout<<"Empty Linked List..."<<endl;
		}
		else
		{
			posi--;
			while(posi!=1)
			{
				posi--;
				curr=curr->next;
			}
			temp->next=curr->next;
			curr->next=temp;
		}
	}
	void dlt_at_head()
	{
		head=head->next;
	}
	void dlt_at_tail()
	{
		node *curr=head;
		if(head==NULL)
		{
			cout<<"Empty Linked List..."<<endl;
		}
		else
		{
			while(curr->next->next!=NULL)
			{
				curr=curr->next;
			}
			curr->next=NULL;
			curr=NULL;
			free(curr);
		}
	}
	void dlt_at_posi(int posi)
	{
		node *curr= head;
		node *temp=curr->next;
		if(head==NULL)
		{
			cout<<"Empty Linked List..."<<endl;
		}
		else if(posi==1)
		{
			head=head->next;
		}
		else
		{
			while(posi!=1)
			{
				temp=curr;
				curr=curr->next;
				posi--;
			}
			temp->next=curr->next;
			curr=NULL;
			free(curr);
		}
	}
	void print ()
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
	obj.add_at_begin(2);
	obj.add_at_begin(1);
	obj.add_at_end(4);
	obj.add_at_posi(3,3);
	obj.add_at_begin(0);
	obj.add_at_end(5);
	obj.dlt_at_head();
	obj.print();
}
