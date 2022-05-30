#include<iostream>
#define QUEUE 50
using namespace std;
struct QNode
{
	int data;
	QNode *next;
};
class Queue
{
public:
	int count;
	QNode *front,*rear;
	Queue()
	{
		count=0;
		front=NULL;
		rear=NULL;
	}
	void enQueue(int x)
	{
		if(count==QUEUE)
		{
			cout<<"Queue Overflow...!!"<<endl<<"Returning...!!"<<endl;
			return;
		}
		else
		{
			QNode *temp=new QNode;
			temp->data=x;
			temp->next=NULL;
			if(front==NULL)
			{
				front=temp;
				rear=temp;
			}
			else
			{
				rear->next=temp;
				rear=rear->next;
			}
			count++;
		}
	}
	void deQueue() 
	{
		if(count==0)
		{
			cout<<"Queue is empty to be deQueued...!!";
			return;
		}
		else
		{
			front=front->next;
			count--;
		}
	}
	void Display()
	{
		QNode *temp=front;
		cout<<"Queue: ";
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
	int get_size() const
	{
		return count;
	}
	bool empty()
	{
		if(count==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void dlt_neg()
	{
		QNode *prev=0;
		QNode *curr=front;
		QNode *tmp=new QNode;
		while(curr!=NULL) 
		{
			if(curr->data<0)
			{
				if (prev!=0)
				{
					prev->next = curr->next;
					count--;
				}
				else
				{
					count--;
					front=curr->next;
				}
				tmp=curr;
				curr=curr->next;
				delete tmp;
			}
			else
			{
				prev=curr;
				curr=curr->next;
			}
	   	}
	}
	void reverse()
	{
		QNode* curr=front;
		QNode *prev=NULL, *next=NULL;
		while (curr!=NULL)
		{
			next = curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
		}
		front=prev;
    }
};
// Driven Program 
int main()
{
	Queue q;
	q.enQueue(10);
	q.enQueue(20);
	q.deQueue();
	q.deQueue();
	q.enQueue(30);
	q.enQueue(40);
	q.enQueue(-3);
	q.enQueue(100);
	q.enQueue(-10);
	q.enQueue(50);
	q.deQueue();
	q.Display();
	q.dlt_neg();
	cout<<endl<<endl<<"After deleteing negative nodes ";
	q.Display();
	cout<<endl<<endl<<"Elements present in Queue is/are: "<<q.get_size()<<endl<<endl;
	cout<<"Queue Front :"<<(q.front)->data<<endl<<endl;
	cout<<"Queue Rear :"<<(q.rear)->data<<endl<<endl;
	q.reverse();
	cout<<"Reversed ";
	q.Display();
	cout<<endl<<endl;
	if(q.empty())
	{
		cout<<"Queue is Empty...!!"<<endl<<endl;
	}
	else
	{
		cout<<"Queue is not Empty...!!"<<endl<<endl;
	}
	
}
