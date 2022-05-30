#include<iostream>
using namespace std;
class Salary
{
	string name;
	float hrs, age, exp, rate, net_sal;
	float *hr, *ag, *ex, *rat, *sal;
public:
	Salary()
	{
		hr=&hrs;
		ag=&age;
		ex=&exp;
		rat=&rate;
		sal=&net_sal;
	}
	void set_data(string name, float hrs, float age, float exp)
	{
		this->name=name;
		this->age=age;
		this->hrs=hrs;
		this->exp=exp;
	}
	void Data()
	{
		cout<<"Enter name of Employee: "; cin>>name;
		cout<<"Enter Age: "; cin>>age;
		cout<<"Enter Experience: "; cin>>exp;
		cout<<"Enter Hour(s) Worked: "; cin>>hrs;
	}
	void Display()
	{
		cout<<"Name: "<<name<<endl;
		cout<<"Age: "<<*ag<<endl;
		cout<<"Experience: "<<*ex<<endl;
		cout<<"Hour(s) Worked: "<<*hr<<endl;
		if( *(rat)==0 || *(sal)==0 )
		{
			cout<<"Invalid Parameters...!!"<<endl;
		}
		else
		{
			cout<<"Rate acc: to conditions: "<<*rat<<endl;
			cout<<"Net Salary: "<<*sal<<endl;
		}
		cout<<"-------------------------------------------"<<endl;
	}
	void Calc_rate()
	{
		if( *(ag)>50 && *(ex)>10 && *(hr)>240 )
		{
			*rat=500;
		}
		else if( *(ag)<=50 && *(ag)>40 &&  *(ex)<=10 && *(ex)>6 && *(hr)>200 && *(hr)<=240 )
		{
			*rat=425;
		}
		else if( *(ag)<=40 && *(ag)>30 &&  *(ex)<=6 && *(ex)>3 && *(hr)>160 && *(hr)<=200 )
		{
			*rat=375;
		}
		else if( *(ag)<=30 && *(ag)>22 &&  *(ex)<=3 && *(ex)>1 && *(hr)>120 && *(hr)<=160 )
		{
			*rat=300;
		}
		else
		{
			cout<<"Invalid Parameters...!!"<<endl;
		}
	}
	void Calc_sal()
	{
		*(sal)= ( *(rat) * *(hr) );
	}
	
};
int main()
{
	Salary *sals;
	int i,n;
	cout<<"Enter No. of Employees: "; 
	cin>>n;
	sals= new Salary[n];
	for(i=0;i<n;i++)
	{
		cout<<"Employee: "<<i+1<<" Data...!!"<<endl<<endl;
		sals[i].Data();
		sals[i].Calc_rate();
		sals[i].Calc_sal();
		system("cls");
	}
	
	cout<<"Emplyee's Data set done... Displaying Salary...!!"<<endl;
	
	for(i=0;i<n;i++)
	{
		sals[i].Display();
	}
}
