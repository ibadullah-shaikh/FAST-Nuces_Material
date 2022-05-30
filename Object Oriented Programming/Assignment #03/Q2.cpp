#include<iostream>
using namespace std;
class Marks
{
protected:
	float totl,per;
public:
	virtual float getPercentage() = 0;
	virtual void calculatePercentage() = 0;
};
class B :virtual public Marks
{
	float subj1,subj2,subj3,subj4;
public:
	B(){}
	B(float s1,float s2,float s3,float s4)
	{
		subj1=s1;
		subj2=s2;
		subj3=s3;
		subj4=s4;
	}
	void calculatePercentage()
	{
		totl=subj1+subj2+subj3+subj4;
		per=(totl/400)*100;
	}
	float getPercentage()
	{
		return per;
	}
};
class A :virtual public Marks
{
	float sub1,sub2,sub3;
public:
	A(){}
	A(float a,float b,float c)
	{
		sub1=a;
		sub2=b;
		sub3=c;
	}
	void calculatePercentage()
	{
		totl=sub1+sub2+sub3;
		per=(totl/300)*100;
	}
	float getPercentage()
	{
		return per;
	}
};
int main()
{
	B b(79.2,88.8,92.65,85);
	A a(56.5,78,84.3);
	
	a.calculatePercentage();
	cout<<"Class A's percentage of 3 Subjects: "<<a.getPercentage()<<endl<<endl;
	
	b.calculatePercentage();
	cout<<"Class B's percentage of 4 Subjects: "<<b.getPercentage()<<endl;;

	return 0;
}
