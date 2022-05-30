#include"Quadratic.h"
#include<iostream>
#include<math.h>
using namespace N;
using namespace std;

void Quadratic :: Store_Data(float a, float b, float c)
{
	this->a=a;
	this->b=b;
	this->c=c;
}

void Quadratic::Calc_Quad()
{
	x1=(-b+( sqrt(b*b)-(4*a*c)))/2*a;
	x2=(-b-( sqrt(b*b)-(4*a*c)))/2*a;
}

void Quadratic::Display()
{
	cout<<"Quadraction Equation: -"<<b<<"+- SQRT("<<b<<"^2 - 4"<<"*"<<a<<"*"<<c<<")"<<"2*"<<a<<endl<<endl;
	cout<<"Answer: X1="<<x1<<endl<<"\tX2="<<x2<<endl;
}
