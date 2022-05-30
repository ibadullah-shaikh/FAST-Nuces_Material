#include<iostream>
using namespace std;
class HeartRates
{
	string fname,lname;
	int date,month,year;
	float max;
public:
	HeartRates(string fn,string ln,int d,int m,int y)
	{
		fname=fn;
		lname=ln;
		date=d;
		month=m;
		year=y;
	}
	string get_fname()
	{
		return fname;
	}
	string get_lname()
	{
		return lname;
	}
	int get_date()
	{
		return date;
	}
	int get_month()
	{
		return month;
	}
	int get_year()
	{
		return year;
	}
	int getAge(int yyy) //function to calculate age and return it...
	{
		int yy;
		yy=yyy-year;
		return yy;
	}
	int getMaximumHeartRate(int x) //function to calculate Max: heart rate and return it...
	{
		max=220-x;
		return max;
	}
	float gethighTargetHeartRate() //function to calculate High Target heart rate and return it...
	{
		float per;
		per=(max*0.85);
		return per;
	}
	float getlowTargetHeartRate() //function to calculate Low Target heart rate and return it...
	{
		float per;
		per=(max*0.50);
		return per;
	}
};
int main()
{
	string x,y;
	int m,n,o,p,q,r,a,c,d,e,f,curryear,dt,mt,yr,currdate,curmonth;
	float b,g;
	string name1,name2;
	cout<<"Enter your First Name:";
	cin>>name1;
	cout<<"Enter your Last Name:";
	cin>>name2;
m:
	cout<<"Enter your Date of Birth (1-31):";
	cin>>dt;
	if(dt>31 || dt<1)
	{
		cout<<"Enter between 1 - 31..."<<endl;
		goto m;
	}
n:
	cout<<"Enter your Month of Birth (1-12):";
	cin>>mt;
	if(mt>12 || mt<1)
	{
		cout<<"Enter between 1 - 12..."<<endl;
		goto n;
	}
o:
	cout<<"Enter your Year of Birth(xxxx-2020):";
	cin>>yr;
	if(yr>2020)
	{
		cout<<"Enter correct year..."<<endl;
		goto o;
	}
p:
	cout<<"Enter Current Date:";
	cin>>currdate;
	if(currdate>31 || currdate<1)
	{
		cout<<"Enter between 1 - 31..."<<endl;
		goto p;
	}
q:
	cout<<"Enter Current Month:";
	cin>>curmonth;
	if(curmonth>12 || curmonth<1)
	{
		cout<<"Enter between 1 - 12..."<<endl;
		goto q;
	}
r:
	cout<<"Enter Current year:";
	cin>>curryear;
	if(curryear>2020)
	{
		cout<<"Enter correct year..."<<endl;
		goto r;
	}
	HeartRates obj(name1,name2,dt,mt,yr);
	x=obj.get_fname();
	y=obj.get_lname();
	c=obj.get_date();
	d=obj.get_month();
	e=obj.get_year();
	f=obj.getAge(curryear);
	a=obj.getMaximumHeartRate(f);
	b=obj.gethighTargetHeartRate();
	g=obj.getlowTargetHeartRate();
	system("cls");
	cout<<"First Name:"<<x<<endl;
	cout<<"Last Name:"<<y<<endl;
	cout<<"Date of Birth:"<<c<<"-"<<d<<"-"<<e<<endl;
	cout<<"Age:"<<f<<endl;
	cout<<"Maximum Heart Rate per minute:"<<a<<endl;
	cout<<"Target Heart Rate:"<<g<<" - "<<b<<endl;
}
