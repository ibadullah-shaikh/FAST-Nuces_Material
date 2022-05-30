#include"DSA.h"
#include<iostream>
#include<cstdlib>
#include<string.h>
#include<stdio.h>
using namespace N;
using namespace std;

DSA::DSA()
{
	data=NULL;
	size=0;
}
DSA::DSA(int n)
{
	size=n;
	data=new int[size];
	memset(this->data,0,sizeof(int)*size);
}
DSA::~DSA()
{
	cout<<"Good-bye...!!"<<endl;
	delete [] data;
	data=0;
	size=0;
}
void DSA::Searching(int x)
{
	int i, y, z=0;
	for(i=0;i<size;i++)
	{
		if(x== *(data+i))
		{
			y=i;
		}
		else
		{
			z++;
		}
	}
	if(z>0)
	{
		cout<<"Value not found...!!"<<endl;
	}
	else
	{
		cout<<"Value "<<x<<" found at index: "<<y<<endl;
	}
}
void DSA::Insertion(int index, int val)
{
	if(index<size && index>size-1)
	{
		cout<<"Index out of bound... Exiting"<<endl;
	}
	else
	{
		*(data + index)=val;
	}
}

void DSA::Display()
{
	int i;
	for(i=0;i<size;i++)
	{
		cout<<*(data+i)<<" ";
	}
}
DSA::DSA(const DSA &d)
{
	this->size=size;
	this->data=data;
}
