#include<iostream>
#include<fstream>
using namespace std;
class Palindrome
{
	int array[999], reversed[999];
	int count;
public:
	Palindrome()
	{
		count=0;
	}
	void set_count()
	{
		int n;
		ifstream file;
		file.open("inputA1P2.txt");
		while(!file.eof())
		{
			file>>n;
			count=n;
			break;
		}
		file.close();
	}
	void add_nums()
	{
		int n,i=0,a=0;
		ifstream file;
		file.open("inputA1P2.txt");
		while(!file.eof())
		{
			file>>n;
			if(a==0)
			{
				a=100;
			}
			else
			{
				array[i]=n;
				i++;
			}
		}
		file.close();
	}
	void Set_reversed_array()
	{
		int i;
		for(i=0;i<count;i++)
		{
			int temp;
			temp=array[i];
			int rev=0;
			while(array[i]>0)
			{
				rev=rev*10+array[i]%10;
				array[i]=array[i]/10;
			}
			reversed[i]=rev;
			array[i]=temp;
		}
	}
	void disp()
	{
		int i;
		cout<<count<<endl;
		for(i=0;i<count;i++)
		{
			cout<<array[i]<<endl;
		}
	}
	void Reverse_array()
	{
		int i,j;
		for(i=0,j=count-1;i<count/2;i++,j--)
		{
			int temp;
			temp=reversed[i];
			reversed[i]=reversed[j];
			reversed[j]=temp;
		}
	}
	void Output()
	{
		int i,a;
		for(i=0;i<count;i++)
		{
			if(reversed[i]==array[i])
			{
				a=1;
			}
			else
			{
				ofstream file;
				file.open("outputA1P2.txt", ios::trunc);
				file<<"NO.";
				file.close();
				exit(1);
			}
		}
		if(a==1)
		{
			ofstream file;
			file.open("outputA1P2.txt", ios::trunc);
			file<<"YES.";
			file.close();
		}
	}
};

int main()
{
	Palindrome obj;
	obj.set_count();
	obj.add_nums();
	obj.Set_reversed_array();
	obj.Reverse_array();
	obj.disp();
	obj.Output();
}
