#include"Student.h"
#include<iostream>
#include<math.h>
using namespace N;
using namespace std;
void Student::Set_Stu(int stu)
{
	this->stu=stu;
}
void Student::Set_Data()
{
	int i;
	cout<<"Enter the I'd of Student:"; cin>>id;
	cout<<"Enter the Discipline of Student:"; cin>>dis;
	cout<<"Enter the Batch of Student:"; cin>>batch;
	cout<<"Enter the Expected Graduation Year of Student:"; cin>>g_year;
	cout<<"Enter the No. of Courses Registered:"; cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Course Name: ";
		cin>>course[i];
	}
}

void Student::Display()
{
	cout<<"I'd of Student:"<<id<<endl;
	cout<<"Discipline of Student:"<<dis<<endl;
	cout<<"Batch of Student:"<<batch<<endl;
	cout<<"Expected Graduation Year of Student:"<<g_year<<endl;
	cout<<"No. of Courses Registered:"<<n<<endl;
	cout<<"Courses:"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<".\t"<<course[i]<<endl;
	}
	cout<<"---------------------------------------------"<<endl<<endl;
}
int Student::operator [](int i)
{
	if(i>=stu)
	{
		cout<<"Array index out of bound, Displaying Results...!!"<<endl<<endl<<endl;
	}
	return i;
}
