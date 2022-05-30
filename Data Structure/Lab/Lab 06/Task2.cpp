#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
	node *prev;
};
class DLL
{
	int cabins;
	node *head , *tail;
public:
	DLL()
	{
		cabins=0;
		head=NULL;
		tail=NULL;
	}
	void add_node(int x)
	{				
		node *temp=new node;
		temp->data=x;
		temp->next=NULL;
		temp->prev=NULL;
		if (head==NULL && tail==NULL)
		{
			head=temp;
			tail=temp;
		}
    	else
        {
			tail->next=temp;
			temp->prev=tail;
			tail=temp;
		}
		cabins++;
	}
	void search()
	{
		node *temp=head;
		node *back=tail;
		while(temp!=NULL)
		{
			if(temp->data==-1)
			{
 				cout<<"Hijacked Cabin has been found...!"<<endl;
			}
			temp=temp->next;
		}
		while(back!=NULL)
		{
		   if(back->data==0)
			{
		    	cout<<"Culprit has been found in Engine: "<<back->data<<endl;	
			}
			back=back->prev;
		}
	}
	void print()
    {
		node *temp= head;
		while(temp != NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
};
int main()
{
	DLL obj;
	obj.add_node(1);
	obj.add_node(2);
	obj.add_node(3);
	obj.add_node(-1);
	obj.add_node(0);
	obj.add_node(4);
	obj.add_node(5);
	obj.search();
	cout<<endl<<endl<<"Total Linked List: ";
	obj.print();
}
