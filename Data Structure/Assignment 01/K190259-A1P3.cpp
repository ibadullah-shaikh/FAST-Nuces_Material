#include<iostream>
#include<fstream>
using namespace std;
class Subset
{
	int array[999];
	int count, target;
public:
	Subset()
	{
		count=0;
	}
	void set_count()
	{
		int n;
		ifstream file;
		file.open("inputA1P3.txt");
		while(!file.eof())
		{
			file>>n;
			count=n;
			break;
		}
		file.close();
	}
	void Disp()
	{
		int i;
		for(i=0;i<count;i++)
		{
			cout<<array[i]<<endl;
		}
	}
	void add_nums()
	{
		int n,i=0,a=0,bound=0;
		ifstream file;
		file.open("inputA1P3.txt");
		while(!file.eof())
		{
			file>>n;
			if(a==0)
			{
				bound=n;
				a=100;
			//	continue;
			}
			else
			{
				array[i]=n;
				i++;
			}
			target=n;
		}
		file.close();
	}
	void check_subset()
	{
		int i,j,a;
		for(i=0;i<count;i++)
		{
			for(j=0;j<count;j++)
			{
				if(j==i)
				{
					continue;
				}
				else
				{
					a=array[i];
					a+=array[j];
				}
				if(a==target)
				{
					ofstream file;
					file.open("outputA1P3.txt", ios::trunc);
					file<<"YES.";
					file.close();
					exit(1);
				}
				else
				{
					a-=array[j];
				}
			}
		}
		ofstream file;
		file.open("outputA1P3.txt", ios::trunc);
		file<<"NO.";
		file.close();
	}
};

int main()
{
	Subset obj;
	obj.set_count();
	obj.add_nums();
	obj.Disp();
	obj.check_subset();
}
