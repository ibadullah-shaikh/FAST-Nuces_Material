#include<iostream>
#include<fstream>
using namespace std;
class Boggle
{
	char array[999][999];
	int row,col,*score,no_words,sc;
	string *search;
public:
	Boggle()
	{
		sc=0;
		row=0;
		col=0;
	}
	void Set_Data()
	{
		int i=0,j=0;
		string s;
		char n;
		ifstream file;
		file.open("inputA1P1.txt");
		file>>row;
		file>>col;
		row++;
		col++;
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				file>>array[i][j];
			}
		}
		file>>no_words;
		search = new string [no_words];
		score = new int [no_words];
		for(i=0;i<no_words;i++)
		{
			file>>search[i];
		}
		file.close();
	}
	void Horizontal()
	{
		int n=0,i=0,j=0,k=0;
		for(k=0;k<no_words;k++)
		{
			for(i=0;i<row;i++)
			{
				for(j=0;j<col;j++)
				{
					if(search[k][n]==array[i][j])
					{
						n++;
						if(n==search[k].length())
						{
							sc=1000;
							score[k]=sc;
						}
					}
					else
					{
						n=0;
					}
				}
			}
		}
		HorizontalReverse();
		Vertical();
		VerticalReverse();
	}
	void HorizontalReverse()
	{
		int n=0,i=0,j=0,k=0;
		for(k=0;k<no_words;k++)
		{
			n=search[k].length();
			n-=1;
			for(i=0;i<row;i++)
			{
				for(j=0;j<col;j++)
				{
					if(array[i][j]==search[k][n])
					{
						n--;
						if(n<0)
						{
							sc=1000;
							score[k]+=sc;
						}
					}
					else
					{
						n=search[k].length();
						n-=1;
					}
				}
			}
		}
	}
	void Vertical()
	{
		int n=0,i=0,j=0,k=0,l=0;
		for(l=0;l<no_words;l++)
		{
			for(i=0;i<row;i++)
			{
				for(j=0;j<col;j++)
				{
					if(array[i][j]==search[l][n])
					{
						n++;
						int k=i;
						for(k;k<row;k++)
						{
							if(array[k][j]==search[l][n])
							{
								n++;
								if(n==search[l].length())
								{
									sc=1000;
									score[l]+=sc;
								}
							}
						}
					}
					else
					{
						n=0;
					}
				}
			}
		}
	}
	void VerticalReverse()
	{
		int n=0,i=0,j=0,k=0,l=0;
		for(l=0;l<no_words;l++)
		{
			n=search[l].length();
			n-=1;
			for(i=0;i<row;i++)
			{
				for(j=0;j<col;j++)
				{
					if(array[i][j]==search[l][n])
					{
						n--;
						int k=i;
						for(k;k<row;k++)
						{
							if(array[k][j]==search[l][n])
							{
								n--;
								if(n==search[l].length())
								{
									sc=1000;
									score[l]+=sc;
								}
							}
						}
					}
					else
					{
						n=search[l].length();
						n-=1;
					}
				}
			}
		}
	}
	
	void print()
	{
		int i,j;
		cout<<row<<" "<<col<<endl;
		for(i=0;i<=row;i++)
		{
			for(j=0;j<=col;j++)
			{
				cout<<array[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<no_words<<endl;
		for(i=0;i<no_words;i++)
		{
			cout<<search[i]<<"\t\t\t"<<score[i]<<endl;
		}
		ofstream file;
		file.open("outputA1P1.txt",ios::trunc);
		for(i=0;i<no_words;i++)
		{
			file<<search[i]<<"\t"<<score[i]<<endl;
		}
	}
};
int main()
{
	Boggle b;
	b.Set_Data();
	b.Horizontal();
	b.print();
}
