#include<iostream>
using namespace std;
class Student
{
	string name;
	int roll;
	string dept;
	float cgpa;
public:
	Student(){}
	void Store_Data(string name, string dept, int roll, float cgpa)
	{
		this->name=name;
		this->dept=dept;
		this->roll=roll;
		this->cgpa=cgpa;
	}
	void Display()
	{
		cout<<"Name: "<<name<<endl;
		cout<<"Roll No. "<<roll<<endl;
		cout<<"Department: "<<dept<<endl;
		cout<<"CGPA: "<<cgpa<<endl;
		cout<<"---------------------------------------------"<<endl;
	}
};
int main()
{
	int n,i,a;
	string b,c;
	float d;
	cout<<"Enter Number of Students:";
	cin>>n;
	Student s[n];
	for(i=0;i<n;i++)
	{
		system("cls");
		cout<<"Student No. "<<i+1<<" Data...!!"<<endl;
		cout<<"Enter Name:";
		cin>>b;
		cout<<"Enter Roll No:";
		cin>>a;
		cout<<"Enter Department:";
		cin>>c;
		cout<<"Enter CGPA:";
		cin>>d;
		s[i].Store_Data(b,c,a,d);
	}
	
	system("cls");
	cout<<"Data stored of "<<n<<" Students...!!"<<endl;
	cout<<"Now Displaying whole data acc: to Descending Order in Names...!!"<<endl<<endl;
	for(i=n-1;i>=0;i--)
	{
		s[i].Display();
	}
}
