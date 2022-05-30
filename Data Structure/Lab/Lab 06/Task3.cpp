#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};

class Circular_Linked
{
	node* last;
public:
	Circular_Linked() 
	{
		node* last = new node;
	}
	Add(int data) 
	{
    	node *temp=new node;
    	temp->data=data; 
    	last=temp;
    	last->next=last; 
	}
	int add_at_Begin(int data) 
	{ 
    	if (last==NULL) 
		{
			return Add(data);
		}
		node *temp=new node;
   		temp->data=data; 
    	temp->next=last->next; 
    	last->next=temp; 
	}
	int add_at_End(int data) 
	{
		if (last == NULL)
		{
			return Add(data);
		}
		node *temp=new node;
		temp->data=data; 
		temp->next=last->next; 
		last->next=temp; 
		last=temp; 
	}
	void Traverse() 
	{ 
		node *p;
		if(last==NULL) 
		{ 
	    	cout<<"Empty Linked List."<<endl; 
	    	return; 
		}
		p=last->next; 
		do
		{
	   		cout<<p->data<<" "; 
	    	p=p->next; 
		}
		while(p!=last->next); 
	}
	void Remove()
	{
		node* tmp=new node();
		tmp=last;
		while(tmp->next != last)
		{
			tmp=tmp->next;
		}
		tmp->next=last->next;
		last=tmp;	 
	}
};

int main()
{
	Circular_Linked l1;
	l1.Add(6);
	l1.add_at_End(10);
	l1.add_at_Begin(4);
	l1.add_at_Begin(1);
	cout<<"Linked List: ";
	l1.Traverse();
	cout<<endl<<endl<<"After Removing Last Element: ";
	l1.Remove();
	l1.Traverse();
}
