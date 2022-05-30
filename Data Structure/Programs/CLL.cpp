#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
class CLL
{
	node *head, *tail;
public:
	CLL()
	{
		head=NULL;
		tail=NULL;
	}
	void add_node(int x)
	{
		node *last=head;
		if(head==NULL)
		{
			node *temp= new node;
			temp->data=x;
			temp->next=temp;
			head=temp;
			tail=temp;
		}
		else
		{
			node *temp= new node;
			temp->data=x;
			temp->next=last->next;
			last->next=temp;
			last=temp;
		}
	}
	void add_at_posi(int x, int pos)
	{
		int i;
		node *temp= new node;
		node *curr=head;
		temp->data=x;
		for(i=0;i<pos-1;i++)
		{
			curr=curr->next;
		}
		temp->next=curr->next;
		curr->next=temp;
	}
	void Insert_at_head(int x)
	{
		node *curr= head;
		node *temp= new node;
		temp->data=x;
		temp->next=head;
		while(curr->next!=head)
		{
			curr=curr->next;
		}
		curr->next=temp;
		head=temp;
	}
	void print ()
	{
		node *temp= head;
		if(head==NULL)
		{
			cout<<"Empty...!!"<<endl;
		}
		else
		{
			do
			{
				cout<<temp->data<<" ";
				temp=temp->next;
			}while(temp!=head);
		}
	}	
	void dlt_from_head()
	{
		head=head->next;
	}
};

int main()
{
	CLL obj;
	obj.add_node(1);
	obj.add_node(2);
	obj.add_node(3);
	obj.add_node(4);
	obj.add_at_posi(10,2);
	obj.Insert_at_head(0);
	obj.dlt_from_head();
	obj.print();
}
