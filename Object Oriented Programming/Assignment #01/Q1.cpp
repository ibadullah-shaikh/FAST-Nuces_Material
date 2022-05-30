#include<iostream>
#include<conio.h>
using namespace std;
class Movie
{
	string name;
	int mpaarating,count=0,total=0,rating;
	
public:
	void set_name(string n) //setter for movie name.
	{
		name=n;
	}
	void set_mpaarating(int x) //setter for MPAA Rating.
	{
		mpaarating=x;
	}
	void addRating(int a) //function to add rating
	{
		rating=a;
		count++;
		total=total+a;
	}
	int get_average() // Getter to calculate and return average rating
	{
		int avg=0;
		avg=total/count;
		return avg;
	}
	Movie(string x,int mpaa) // constructor to set movie name and MPAA Rating
	{
		name=x;
		mpaarating=mpaa;
	}
	int get_mpaa() // Getter to get MPAA Rating.
	{
		return mpaarating;
	}
	string get_name() // Getter to get movie name.
	{
		return name;
	}
};
int main()
{
	int h,j,i,n,m,a,b,mp1,mp2,x,y;
	string movie1,movie2,mo1,mo2;
	cout<<"Enter First Movie Name:";
	cin>>movie1;
x:
	cout<<"Enter MPAA Rating for this Movie\n1.G\n2.PG\n3.PG-13\n4.r\nYourChoice:";
	cin>>mp1;
	if(mp1<1 || mp1>4)
	{
		cout<<"Enter Correct MPAA Rating...\n";
		goto x;
	}
	Movie m1(movie1,mp1);
	cout<<"Enter 5 ratings (1-5):"<<endl;
	for(i=0;i<5;i++)
	{
	a:
		cout<<"Rating "<<i+1<<":";
		cin>>n;
		if(n<1||n>5)
		{
			cout<<"Enter Between 1-5"<<endl;
			goto a;
		}
		else
		{
			m1.addRating(n);
		}
	}
	cout<<"Enter Second Movie Name:";
	cin>>movie2;
y:
	cout<<"Enter MPAA Rating for this Movie\n1.G\n2.PG\n3.PG-13\n4.r\nYourChoice:";
	cin>>mp2;
	if(mp2<1 || mp2>4)
	{
		cout<<"Enter Correct MPAA Rating...\n";
		goto y;
	}
	Movie m2(movie2,mp2);
	cout<<"Enter 5 ratings (1-5):"<<endl;
	for(i=0;i<5;i++)
	{
	b:
		cout<<"Rating "<<i+1<<":";
		cin>>m;
		if(m<1||m>5)
		{
			cout<<"Enter Between 1-5"<<endl;
			goto b;
		}
		else
		{
			m2.addRating(m);	
		}
	}
	system("cls");
	int p,r;
	h=m1.get_mpaa();
	j=m2.get_mpaa();
	mo1=m1.get_name();
	mo2=m2.get_name();
	p=m1.get_average();
	r=m2.get_average();
	
	cout<<"Movie Name:"<<mo1<<endl;
	switch(h)
	{
		case 1:
			{
				cout<<"MPAA Rating for this Movie: G"<<endl;
				break;
			}
		case 2:
			{
				cout<<"MPAA Rating for this Movie: PG"<<endl;
				break;
			}
		case 3:
			{
				cout<<"MPAA Rating for this Movie: PG-13"<<endl;
				break;
			}
		case 4:
			{
				cout<<"MPAA Rating for this Movie: r"<<endl;
				break;
			}
	}
	cout<<"Average Rating:"<<p<<endl;
	switch(p)
	{
		case 1:
			{
				cout<<"Remarks: Terrible."<<endl;
				break;
			}
		case 2:
			{
				cout<<"Remarks: Bad."<<endl;
				break;
			}
		case 3:
			{
				cout<<"Remarks: OK."<<endl;
				break;
			}
		case 4:
			{
				cout<<"Remarks: Good."<<endl;
				break;
			}
		case 5:
			{
				cout<<"Remarks: Great."<<endl;
				break;
			}
	}
	cout<<endl<<"-------------------------------------"<<endl;
	cout<<endl<<"Movie Name:"<<mo2<<endl;
	switch(j)
	{
		case 1:
			{
				cout<<"MPAA Rating for this Movie: G"<<endl;
				break;
			}
		case 2:
			{
				cout<<"MPAA Rating for this Movie: PG"<<endl;
				break;
			}
		case 3:
			{
				cout<<"MPAA Rating for this Movie: PG-13"<<endl;
				break;
			}
		case 4:
			{
				cout<<"MPAA Rating for this Movie: r"<<endl;
				break;
			}
	}
	cout<<"Average Rating:"<<r<<endl;
	switch(r)
	{
		case 1:
			{
				cout<<"Remarks: Terrible."<<endl;
				break;
			}
		case 2:
			{
				cout<<"Remarks: Bad."<<endl;
				break;
			}
		case 3:
			{
				cout<<"Remarks: OK."<<endl;
				break;
			}
		case 4:
			{
				cout<<"Remarks: Good."<<endl;
				break;
			}
		case 5:
			{
				cout<<"Remarks: Great."<<endl;
				break;
			}
	}
	getch();
}
