#include<iostream>
using namespace std;
struct node
{
	node *prev;
	int data;
	node *next;
};
class DLL
{
	node *head, *tail;
public:
	DLL()
	{
		head=NULL;
		tail=NULL;
	}
	void add_node(int x)
	{
		node *temp= new node;
		temp->data=x;
		temp->next=NULL;
		temp->prev=NULL;
		if(head==NULL)
		{
			tail=temp;
			head=temp;
		}
		else
		{
			temp->prev=tail;
			temp->next=NULL;
			tail->next=temp;
			tail=temp;
		}
	}
	void print ()
	{
		node *temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
	void add_at_head(int x)
	{
		node *temp= new node;
		temp->data=x;
		temp->next=temp->prev=NULL;
		if(head==NULL)
		{
			tail=temp;
 			head=temp;
		}
		else
		{
			temp->next=head;
			head->prev=temp;
			head=temp;
		}
	}
	void add_at_posi(int x, int posi)
	{
		node *curr= head;
		node *temp = new node;
		temp->data=x;
		for(int i=0;i<posi-1;i++)
		{
			curr=curr->next;
		}
		temp->next=curr->next;
		temp->prev=curr;
		if(curr->next!=NULL)
		{
			curr->next->prev=temp;
		}
		curr->next= temp;
	}
	void dlt_from_head()
	{
		head=head->next;
	}
	void dlt_from_posi(int posi)
	{
		node *curr=head;
		for(int i=0;i<posi-2;i++)
		{
			curr=curr->next;
		}
		curr->next=curr->next->next;
 		curr->next->prev=curr;
	}
	void reverse()
	{
		node *temp=head;
		node *tmp= new node;

		while(temp!=NULL)
		{
			tmp=temp->next;
			temp->next=temp->prev;
			temp->prev=tmp;			
			temp=temp->prev;
			if(temp!=NULL && temp->next==NULL)
			{
				head=temp;
			}
		}
	}
};
int main()
{
	DLL obj;
	obj.add_node(5);
	obj.add_node(6);
	obj.add_node(7);
	obj.add_at_head(1);
	obj.add_at_posi(10,3);
	obj.dlt_from_head();
	obj.dlt_from_posi(3);
	obj.print();
	cout<<endl<<endl;
	obj.reverse();
	obj.print();
}
