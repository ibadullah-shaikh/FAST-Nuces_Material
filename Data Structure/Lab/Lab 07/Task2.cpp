#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
class Sorting
{
	int size;
	node *head, *tail;
public:
	Sorting()
	{
		size=0;
		head=NULL;
		tail=NULL;
	}
	void add_node(int x)
	{
		node *temp= new node;
		temp->data=x;
		temp->next=NULL;
		if(head==NULL)
		{
			head=temp;
			tail=temp;
		}
		else
		{
			tail->next=temp;
			tail=tail->next;
		}
		size++;
	}
	void Bubble_Sort()
	{
		node *temp = head;
		node *temp1 = head;
		while(temp1->next!=NULL)
		{
			
			temp=head;
			while(temp->next!= NULL)
			{
				if(temp->data > temp->next->data)
				{
					int tmp;
					tmp= temp->data;
					temp->data= temp->next->data;
					temp->next->data=tmp;
				}
				temp=temp->next;
			}
			temp1=temp1->next;
		}
	}
	void print()
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
};
int main()
{
	Sorting obj;
	obj.add_node(5);
	obj.add_node(3);
	obj.add_node(2);
	obj.add_node(1);
	obj.add_node(4);
	obj.print();
	cout<<endl<<endl;
	obj.Bubble_Sort();
	obj.print();
	return 0;
}
