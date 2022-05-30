#include "Car.h"
#include<iostream>
using namespace N;
using namespace std;
void Car::Set_Data()
{
	cout<<"Enter Model Of Car: ";
	cin>>model;
	
	cout<<"Enter Name of Car: ";
	cin>>name;
	
	cout<<"Enter Color of the Car: ";
	cin>>color;
}

void Car::Display()
{
	cout<<"Model Of Car: "<<model<<endl;
	cout<<"Name of Car: "<<name<<endl;
	cout<<"Color of the Car: "<<color<<endl;
	cout<<"--------------------------------------"<<endl<<endl;
}

Car::Car(const Car &c1)
{
	model=c1.model;
	name=c1.name;
	color=c1.color;
}

void Car::operator =(Car c1)
{
	model=c1.model;
	name=c1.name;
	color=c1.color;
}

Car::~Car()
{
	cout<<"Car Object(s) Destructed Successfully...!!"<<endl;
}

Car::Car() 
{
	
}
