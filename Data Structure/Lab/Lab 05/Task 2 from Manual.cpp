#include<iostream>
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
	int total_nodes() const
	{
		int a;
		node *tmp=head;
		while(tmp!=NULL)
		{
			a++;
			tmp=tmp->next;
		}
		return a;
	}
	void calc_avg(Linked_List &list, Linked_List &average)
	{
		float sum=0;
		int i,cnt,nodes;
		node *tmp=list.head;
		node *tmp1=list.head;
		nodes=list.total_nodes();
		for(i=0;i<nodes-3;i++)
		{
			while(cnt!=4)
			{
				sum=sum+tmp->data;
				tmp=tmp->next;
				cnt++;
			}
			tmp1=tmp1->next;
			tmp=tmp1;
			sum=sum/4;
			average.add_node(sum);
			sum=0;
			cnt=0;
		}
	}
};
int main()
{
	Linked_List list, avg;
	float n;
	int i;
	cout<<"Enter 12 Linked Lists's Data Members:";
	for(i=0;i<12;i++)
	{
		cin>>n;
		list.add_node(n);
	}
	system("cls");
	cout<<"Linked List that you set now: ";
	list.Display();
	cout<<endl<<endl;
	list.calc_avg(list,avg);
	cout<<"Average Linked List that is set by this Program: ";
	avg.Display();
	cout<<endl<<endl;
}
