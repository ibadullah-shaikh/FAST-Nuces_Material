#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	float data;
	node *next;
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
	void add_node(float x)
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
	void Display()
	{
		node *tmp = head;
		while(tmp!=NULL)
		{
			cout<<tmp->data;
			if(tmp->next!=NULL)
			{
				cout<<", ";
			}
			tmp=tmp->next;
		}
	}
	void reverse()
	{
    	node *curr=head;
		node *prev=NULL,*next=NULL;
		while (curr!=NULL)
		{
        	next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
        }
		head=prev;
	}
	void remove_Duplicates()
	{
		node* curr=head;
		node* nextnode; 
		while (curr->next!=NULL) 
		{
			if (curr->data==curr->next->data) 
			{
				nextnode=curr->next->next; 
				free(curr->next); 
				curr->next=nextnode; 
			}
			else
			{
				curr=curr->next; 
			}
		}
	}
};
int main()
{
	Linked_List l1;
	l1.add_node(1);
	l1.add_node(2);
	l1.add_node(3);
	l1.add_node(3);
	l1.add_node(5);
	l1.add_node(6);
	l1.add_node(6);
	cout<<"Before Sorting: ";
	l1.Display();
	cout<<endl<<endl;
	l1.reverse();
	cout<<"After Sorting: ";
	l1.Display();
	cout<<endl<<endl;
	cout<<"After Removing Duplicate: ";
	l1.remove_Duplicates();
	l1.Display();
}
