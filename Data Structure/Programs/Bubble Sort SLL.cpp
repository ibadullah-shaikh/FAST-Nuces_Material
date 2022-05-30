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
	void print ()
	{
		node *temp=head;
		while(temp!= NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
	void sort()
	{
		node *curr= head;
		while(curr!=NULL)
		{
			node *temp= curr->next;
			while(temp!=NULL)
			{
				if(curr->data > temp->data)
				{
					int tmp;
					tmp=curr->data;
					curr->data=temp->data;
					temp->data=tmp;
				}
				temp=temp->next;
			}
			curr=curr->next;
		}
	}
};
int main()
{
	SLL obj;
	obj.add_at_begin(5);
	obj.add_at_begin(3);
	obj.add_at_begin(4);
	obj.add_at_begin(1);
	obj.add_at_begin(2);
	obj.add_at_begin(6);
	cout<<"Before Sorting...!!"<<endl;
	obj.print();
	
	cout<<endl<<endl<<"After Sorting...!!"<<endl;
	obj.sort();
	obj.print();

}
