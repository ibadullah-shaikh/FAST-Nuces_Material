#include"Student.cpp"
using namespace N;
int main()
{
	int x;
	cout<<"Enter No. of Students:";
	cin>>x;
	Student s;
	Student st[x];
	int i=0;
	system("cls");
	for(i;i<x;i++)
	{
		cout<<"Set Student(s) Data...!!"<<endl;
		st[i].Set_Data();
		system("cls");
		cout<<"Next Student...!!"<<endl<<endl;
	}
	system("cls");
	cout<<"Student(s) Data is set. Now Displaying..!!"<<endl;
	
	for(i=0;i<x;i++)
	{
		st[i].Display();
	}
}
