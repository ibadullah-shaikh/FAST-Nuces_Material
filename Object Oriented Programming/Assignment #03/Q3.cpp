#include<iostream>
#include<conio.h>
using namespace std;
class Information
{
protected:
	string pick,drop,name;
	long long cell,cnic[10];
	int i,count;
public:
	Information()
	{
		i=0;
		count=0;
	}
	Information(string name, string pick, string drop, long long cell)
	{
		this->name = name;
		this->pick = pick;
		this->drop = drop;
		this->cell = cell;
	}
	void set_Cnics(long long cn)
	{
		cnic[i]=cn;
		i++;
		count++;
	}
	void Display_Information()
	{
		cout<<"Name of Customer:"<<name<<endl;
		cout<<"Pickup Location:"<<pick<<endl;
		cout<<"Drop-off Location:"<<drop<<endl;
		cout<<"Cell- Phone Number: +92"<<cell<<endl;
		cout<<"CNIC Number(s):"<<endl;
		for(i=1;i<=count;i++)
		{
			cout<<cnic[i]<<endl;
		}
	}
};

class Fare
{
protected:
	float miles,total_fare;
public:
	Fare(){}
	Fare(float mile)
	{
		miles=mile;
	}
	virtual void Calculate_Fare()=0;
	float get_TotalFare()
	{
		return total_fare;
	}
};

class Taxi :public Fare,public Information
{
	static float fare_per_mile;
public:
	Taxi(){}
	Taxi(float mil,string n,string p,string d,long long c):Information(n,p,d,c),Fare(mil){}
	void Calculate_Fare()
	{
		total_fare=miles*fare_per_mile;
	}
};
float Taxi :: fare_per_mile=5.83;

class Shuttle : public Fare, public Information
{
	static float fare_per_mile;
public:
	Shuttle(){}
	Shuttle(float mil,string n,string p,string d,long long c):Information(n,p,d,c),Fare(mil){}
	void Calculate_Fare()
	{
		total_fare=miles*fare_per_mile;
	}
};
float Shuttle :: fare_per_mile=4.37;

int main()
{
	char av;
	int n;
	cout<<"Which Service do you want ?\n1.Taxi.\n2.Shuttle\nYour Choice:";
	cin>>n;
	if(n<1 || n>2)
	{
		cout<<"Inavlid Choice.!!"<<endl;
		exit(1);
	}
	cout<<endl<<"Is it available ?\n->Y for Yes.\n->N for No.\nYour Choice:";
	cin>>av;
	if(av=='y' || av=='Y')
	{
		long long no,cn[10];
		string na,pi,dr;
		float mil;
		int numb,x;
		cout<<"Enter your name:";cin>>na;
		cout<<"Enter your Cell-Phone Number:";cin>>no;
		cout<<"Enter Number of Person(s):";cin>>numb;
		cout<<"Enter pickup point:";cin>>pi;
		cout<<"Enter dropoff point:";cin>>dr;
		cout<<"Enter Miles from "<<pi<<" to "<<dr<<":";cin>>mil;
		if(n==1)
		{
			Taxi t(mil,na,pi,dr,no);
			if(numb>1)
			{
				for(x=0;x<numb;x++)
				{
					cout<<"Enter CNIC Number of person "<<x+1<<":";
					cin>>cn[x];
					t.set_Cnics(cn[x]);
				}
			}
			system("cls");
			t.Calculate_Fare();
			t.Display_Information();
			cout<<"Total Fare:"<<t.get_TotalFare()<<endl;
			getch();
		}
		else if(n==2)
		{
			Shuttle s(mil,na,pi,dr,no);
			if(numb>1)
			{
				for(x=0;x<numb;x++)
				{
					cout<<"Enter CNIC Number of person "<<x+1<<":";
					cin>>cn[x];
					s.set_Cnics(cn[x]);
				}
			}
			system("cls");
			s.Calculate_Fare();
			s.Display_Information();
			cout<<"Total Fare:"<<s.get_TotalFare()<<endl;
			getch();
		}
		else
		{
			cout<<"Invalid Choice.!!"<<endl;
		}
	}
	else if(av=='n' || av=='N')
	{
		cout<<endl<<"We are Sorry...!! Vehichle not available right now, please try again later."<<endl;
		getch();
		system("cls");
	}
}
