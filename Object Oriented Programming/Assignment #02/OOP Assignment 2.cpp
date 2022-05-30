#include<iostream>
#include<conio.h>
using namespace std;
class Polynomial
{
	int coeff,pow;
	char variable;
public:
	Polynomial()		//default constructor because I've made paramaterized.
	{
	}
	Polynomial(float x,char y,int z) //paramaterized constructor to set values.
	{
		coeff=x;
		variable=y;
		pow=z;
	}
	int get_coeff() const //getter to get co-effecient
	{
		return coeff;
	}
	int get_pow() const		//getter to get power
	{
		return pow;
	}
	char get_variable() const		//getter to get variable
	{
		return variable;
	}
	void operator =(Polynomial poly) //overloading (=) operator
	{
			coeff=poly.coeff;
			pow=poly.pow;
			variable=poly.variable;
	}
	Polynomial operator -(Polynomial poly)  	//overloading (-) operator
	{
		Polynomial poly_4;
		if(pow==poly.pow && variable==poly.variable)
		{
			poly_4.coeff=coeff-poly.coeff;
			poly_4.variable=poly.variable;
			poly_4.pow=poly.pow;
			return poly_4;
		}
		else
		{
			cout<<endl<<"Subtraction not Possible, because either power or variable doesn't match."<<endl;
			exit(1);
		}
	}
	Polynomial operator +(Polynomial poly)		//overloading (+) operator
	{
		Polynomial poly_4;
		if(pow==poly.pow && variable==poly.variable)
		{
			poly_4.coeff=coeff+poly.coeff;
			poly_4.variable=poly.variable;
			poly_4.pow=poly.pow;
			return poly_4;
		}
		else
		{
			cout<<endl<<"Addition not Possible, because either power or variable doesn't match."<<endl;
			exit(1);
		}
	}
	Polynomial operator / (Polynomial poly)		//overloading (/) operator
	{
		Polynomial poly_4;
		if(variable==poly.variable)
		{
			poly_4.coeff=coeff/poly.coeff;
			poly_4.variable=poly.variable;
			poly_4.pow=pow-poly.pow;
			return poly_4;
		}
		else
		{
			cout<<endl<<"Division not possible,  because either variable doesn't match.";
			exit(1);
		}
	}
	Polynomial operator *(Polynomial poly)		//overloading (*) operator
	{
		Polynomial poly_4;
		if(variable==poly.variable)
		{
			poly_4.coeff=coeff*poly.coeff;
			poly_4.variable=poly.variable;
			poly_4.pow=pow+poly.pow;
			return poly_4;
		}
		else
		{
			cout<<endl<<"Multiplication not possible,  because variable doesn't match.";
			exit(1);
		}
	}
	void operator *=(Polynomial poly)		//overloading (*=) operator
	{
		if(variable==poly.variable)
		{
			coeff*=poly.coeff;
			pow+=poly.pow;
			variable==poly.variable;
		}
		else 
		{
			cout<<endl<<"*= not possible, variable doesn't match."<<endl;
			exit(1);
		}
	}
	void operator -=(Polynomial poly) //overloading (-=) operator
	{
		if(variable==poly.variable && pow==poly.pow)
		{
			coeff-=poly.coeff;
			pow==poly.pow;
			variable==poly.variable;
		}
		else 
		{
			cout<<endl<<"-= not possible,  because either power or variable doesn't match."<<endl;
			exit(1);
		}
	}
	void operator +=(Polynomial poly) //overloading (+=) operator
	{
		if(variable==poly.variable && pow==poly.pow)
		{
			coeff+=poly.coeff;
			pow==poly.pow;
			variable==poly.variable;
		}
		else 
		{
			cout<<endl<<"+= not possible, because either power or variable doesn't match."<<endl;
			exit(1);
		}
	}
	~Polynomial() //destructor to destroy all values.
	{
	}
};
class Equation
{
	int power,coeffi;
	char var;
	public:
	Equation(){} 			//Default Constructor
	Equation(int c,char v,int p) 		//Constructor to assign values
	{
		coeffi=c;
		var=v;
		power=p;
	}
	int get_coeffi() const 		//getter to get co-effecient of class Equation
	{
		return coeffi;
	}
	int get_power() const		//getter to get power of class Equation
	{
		return power;
	}
	char get_var() const		//getter to get variable of class Equation
	{
		return var;
	}
	Equation operator +(Equation e)			//overloading (+) operator for Equation to be added
	{
		Equation ee;
		ee.coeffi=coeffi+e.coeffi;
		ee.var=e.var;
		ee.power=e.power;
		return ee;
	}
	~Equation()   //Destructor of Equation Class.
	{
	}
};

int main()
{
	Equation eq1[3]={	Equation(-4,'x',3),Equation(3,'m',2),Equation(-2,'n',3) }; //Equation No. 1			(2x^4 + 3y^2 + 1x^1)
	Equation eq2[3]={	Equation(-4,'m',2),Equation(1,'n',3),Equation(4,'x',3) }; ////Equation No. 1	(3x^2 + 2x^4 + -3y^1)
	Equation eqadd[6]; //array for storing answer of both equations
	int co,co1,po,po1,op,i,j,n=0;
	char var,var1;
	cout<<"\t\t\tSolving the Equation...!!"<<endl<<"\t\t--------------------------------------------"<<endl<<endl;
	//printing equation no. 1.
	for(i=0;i<3;i++)
	{
		cout<<eq1[i].get_coeffi()<<eq1[i].get_var()<<"^"<<eq1[i].get_power();
		if(i<2 && eq1[i+1].get_coeffi()>0) //condition to print (+) sign between polynomials
		{
			cout<<" + ";
		}
		else
		{
			cout<<" ";
		}
	}
	cout<<endl;
	//printing equation no. 2.
	for(i=0;i<3;i++)
	{
		cout<<eq2[i].get_coeffi()<<eq2[i].get_var()<<"^"<<eq2[i].get_power();
		if(i<2 && eq2[i+1].get_coeffi()>0) //condition to print (+) sign between polynomials
		{
			cout<<" + ";
		}
		else
		{
			cout<<" ";
		}
	}
	//creating difference with equations and answer's equation.
	cout<<endl<<"-----------------------------------"<<endl;
	//comparing first equation with second one.
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(eq1[i].get_power()==eq2[j].get_power() && eq1[i].get_var()==eq2[j].get_var())
			{
				eqadd[n]=eq1[i]+eq2[j];
				j++;
				n++;
				continue;
			}
			if(j==2)
			{
				eqadd[n]=eq1[i];
				n++;
			}				
		}
	}
	//comparing second equation with first.
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(eq2[i].get_power()!=eq1[j].get_power() && eq2[i].get_var()!=eq1[j].get_var())
			{
				j++;
				continue;
			}
			if(j==2)
			{
				eqadd[n]=eq2[j];
				n++;
			}
		}
	}
	//printing equation after adding.
	for(i=0;i<n;i++)
	{
		//if coefficient of any polynomial is 0, so donot print that as it will become 0.
		if(eqadd[i].get_coeffi()==0)
		{
			continue;
		}
		else if(eqadd[i].get_power()==1) //condition if power=1 of any variable so donot print that.
		{
			cout<<eqadd[i].get_coeffi()<<eqadd[i].get_var();//<<" + ";
			if(i<n-1 && eqadd[i+1].get_coeffi()>0) //condition to print (+) sign between polynomials.
			{
				cout<<" + ";
			}
			else
			{
				cout<<" ";
			}
		}
		else
		{
			//if power > 1 then printing power as well.
			cout<<eqadd[i].get_coeffi()<<eqadd[i].get_var()<<"^"<<eqadd[i].get_power();//<<" + ";
			if(i<n-1 && eqadd[i+1].get_coeffi()>0) //condition to print (+) sign between polynomials.
			{
				cout<<" + ";
			}
			else 
			{
				cout<<" ";
			}
		}
	}
	cout<<endl<<endl;
	cout<<"Now other Arithematic(s)...!!"<<endl;
	cout<<endl<<"Equation:1"<<endl<<"-------------------------"<<endl;
	cout<<"Enter Co-efficient 1:";
	cin>>co;
	cout<<"Enter Letter 1:";
	cin>>var;
	cout<<"Enter Power 1:";
	cin>>po;
	Polynomial poly1(co,var,po);
	cout<<endl<<endl<<"Equation:2"<<endl<<"-------------------------"<<endl;
	cout<<"Enter Co-efficient 2:";
	cin>>co1;
	cout<<"Enter Letter 2:";
	cin>>var1;
	cout<<"Enter Power 2:";
	cin>>po1;
	Polynomial poly2(co1,var1,po1);
	cout<<endl<<"Enter Number equivalent to operator...What do you want to do...?\n1.(+)\n2.(-)\n3.(*)\n4.(/)\n5.(+=)\n";
	cout<<"6.(-=)\n7.(*=)\n8.(=)\n9.Exit\n\n";
	cout<<"Choose any one by number (1-9):";
	cin>>op;
	system("cls");
	if(op==1) //adding two polynomials.
	{
		cout<<poly1.get_coeff()<<poly1.get_variable()<<"^"<<poly1.get_pow()<<" + ";
		cout<<poly2.get_coeff()<<poly2.get_variable()<<"^"<<poly2.get_pow()<<" = ";
		Polynomial poly3=poly1+poly2;
		cout<<poly3.get_coeff()<<poly3.get_variable()<<"^"<<poly3.get_pow()<<endl;
	}
	else if(op==2) //Subtracting two polynomials.
	{
		cout<<poly1.get_coeff()<<poly1.get_variable()<<"^"<<poly1.get_pow()<<" - ";
		cout<<poly2.get_coeff()<<poly2.get_variable()<<"^"<<poly2.get_pow()<<" = ";
		Polynomial poly3=poly1-poly2;
		cout<<poly3.get_coeff()<<poly3.get_variable()<<"^"<<poly3.get_pow()<<endl;
	}
	else if(op==3) //Multiplying two polynomials.
	{
		cout<<poly1.get_coeff()<<poly1.get_variable()<<"^"<<poly1.get_pow()<<" * ";
		cout<<poly2.get_coeff()<<poly2.get_variable()<<"^"<<poly2.get_pow()<<" = ";
		Polynomial poly3=poly1*poly2;
		cout<<poly3.get_coeff()<<poly3.get_variable()<<"^"<<poly3.get_pow()<<endl;
	}
	else if(op==4) //Dividing two polynomials. (Additional)
	{
		cout<<poly1.get_coeff()<<poly1.get_variable()<<"^"<<poly1.get_pow()<<" / ";
		cout<<poly2.get_coeff()<<poly2.get_variable()<<"^"<<poly2.get_pow()<<" = ";
		Polynomial poly3=poly1/poly2;
		if(poly3.get_coeff()==0) // if coefficient becomes zero as it is of int size then printing in fraction form
		{
			cout<<poly1.get_coeff()<<"/"<<poly2.get_coeff();
			cout<<poly3.get_variable()<<"^"<<poly3.get_pow()<<endl;
		}
		else
		{
			cout<<poly3.get_coeff()<<poly3.get_variable()<<"^"<<poly3.get_pow()<<endl;
		}
	}
	else if(op==5) //Adding and assigning first with second polynomial.
	{
		cout<<poly1.get_coeff()<<poly1.get_variable()<<"^"<<poly1.get_pow()<<" += ";
		cout<<poly2.get_coeff()<<poly2.get_variable()<<"^"<<poly2.get_pow()<<" = ";
		poly1+=poly2;
		cout<<poly1.get_coeff()<<poly1.get_variable()<<"^"<<poly1.get_pow();
	}
	else if(op==6) //Subtracting and assigning first with second polynomial.
	{
		cout<<poly1.get_coeff()<<poly1.get_variable()<<"^"<<poly1.get_pow()<<" -= ";
		cout<<poly2.get_coeff()<<poly2.get_variable()<<"^"<<poly2.get_pow()<<" = ";
		poly1-=poly2;
		cout<<poly1.get_coeff()<<poly1.get_variable()<<"^"<<poly1.get_pow();
	}
	else if(op==7) //Multiplying and assigning first with second polynomial.
	{
		cout<<poly1.get_coeff()<<poly1.get_variable()<<"^"<<poly1.get_pow()<<" *= ";
		cout<<poly2.get_coeff()<<poly2.get_variable()<<"^"<<poly2.get_pow()<<" = ";
		poly1*=poly2;
		cout<<poly1.get_coeff()<<poly1.get_variable()<<"^"<<poly1.get_pow();
	}
	else if(op==8) //Assigning second polynomial int the first.
	{
		cout<<"Before Overloadng (=) operator...!!"<<endl;
		cout<<poly1.get_coeff()<<poly1.get_variable()<<"^"<<poly1.get_pow()<<endl<<endl;
		poly1=poly2;
		cout<<"After Overloadng (=) operator...!!"<<endl;
		cout<<poly1.get_coeff()<<poly1.get_variable()<<"^"<<poly1.get_pow();
	}
	else if(op==9)
	{
		//exit from the pogram.
		cout<<"\t\t\t\tThankyou so much...!!\n\t\t\tYou have been exited from the program...!!"<<endl;
		exit(1);
	}
	else //else condition of all.
	{
		cout<<"Invalid Choice...!";
	}
	
	getch();
	return 0;
	
}

