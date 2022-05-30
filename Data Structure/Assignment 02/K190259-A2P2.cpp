#include<iostream>
#include<fstream>
using namespace std;
struct node
{
	int data;
	node *next;
	int pri;
};
class Queue
{
	node *start;
	int array[3][10],cols;
public:
	Queue()
	{
		start=NULL;
		cols=0;
	}
	void set_Data()
	{
		int i,j;
		ifstream file;
		file.open("input003.txt");
		if(!file)
		{
			cout<<"File not found...!!"<<endl;
			exit(1);
		}
		file>>cols;
		for(i=0;i<3;i++)
		{
			for(j=0;j<cols;j++)
			{
				file>>array[i][j];
			}
		}
		file.close();
	}
	void Display()
	{
		cout<<cols<<endl;
		int i,j;
		for(i=0;i<3;i++)
		{
			for(j=0;j<cols;j++)
			{
				cout<<array[i][j]<<"  ";
			}
			cout<<endl;
		}
	}
	void Logic()
	{
		int l=1,i;
		int j=2;
		for(i=0;i<cols;i++)
		{
			int a=array[j][i]/array[l][i];
			EnQueue(array[0][i],a);
		}
	}
	void EnQueue(int a, int b)
	{
		node *temp, *temp1=new node;
		temp=start;
		temp1->data=a;
		temp1->pri=b;
		if(start==NULL || b<start->pri)
		{
			temp1->next=start;
			start=temp1;
		}
		else
		{
			while(temp->next!=NULL && temp->next->pri <= b)
				temp=temp->next;
				temp1->next=temp->next;
				temp->next=temp1;
		}		
	}
	void DisplayOutput()
	{
		ofstream file;
		file.open("outputA2P2.txt", ios::trunc);
		node *temp = start;
		cout<<endl;
		while(temp!=NULL)
		{
		    cout<<temp->data<<" ";
		    file<<temp->data;
			temp=temp->next;	    
		}
	}
};
int main()
{
	Queue q;
	q.set_Data();
	q.Logic();
	system("cls");
	q.Display();
	q.DisplayOutput();
}
