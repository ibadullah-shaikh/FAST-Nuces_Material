#include<iostream>
#include<bits/stdc++.h> 
using namespace std;
struct node 
{
	node *next;
	char data;
};
class Palindrome
{
	node *head, *tail;
public:
	Palindrome()
	{
		head=NULL;
		tail=NULL;
	}
	void add_node(char x)
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
	void print()
	{
		node *temp=head;
		while(temp!= NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
	void palindrome()
	{
		node *temp=head;
		node *curr=head;
		stack <char> s;
		while(temp!=NULL)
		{
			s.push(temp->data);
			temp=temp->next;
		}
		while(curr!=NULL)
		{
			int i=s.top();
			s.pop();
			if(i!= curr->data)
			{
				cout<<"Not Palindrome...!!"<<endl;
				return;
			}
			curr=curr->next;
		}
		cout<<"Palindromee...!!"<<endl;
	}
};
int main()
{
	Palindrome obj;
	obj.add_node('a');
	obj.add_node('b');
	obj.add_node('c');
	obj.add_node('b');
	obj.add_node('a');
	obj.print();
	cout<<endl;
	obj.palindrome();
}
