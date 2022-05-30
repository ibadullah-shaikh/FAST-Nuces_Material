#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Maze
{
	int cost, var, count, path, value, row, col;
	bool status,status1,one,two,three,four;
	char array[15][15];
public:
	Maze()
	{
		cost=var=row=col=count=path=value=0;
		status=status1=one=two=three=four=false;
	}
	void set_Data()
	{
		int i,j;
		ifstream file;
		file.open("inputA2P1.txt");
		if(!file)
		{
			cout<<"File not found...!!"<<endl;
			exit(1);
		}
		file>>row;
		file>>col;
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				file>>array[i][j];
			}
		}
		file.close();
	}
	void Display()
	{
		cout<<row<<" "<<col<<endl;
		int i,j;
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				cout<<array[i][j]<<"  ";
			}
			cout<<endl;
		}
		cout<<endl<<endl;
	}
	void func(int a, int b)
	{
		array[a][b]='1';
		status1=true;
		if(b!=col-1)
		{
			checkNext(a, b + 1);
		}
		if(b!=0) 
		{ 
			checkNext(a, b - 1);
		}
		if(a!=row-1)
		{
			checkNext(a + 1, b);
		}
		if(a!=0)
		{
			checkNext(a - 1, b);
		}
	}
	int checkNext(int a, int b)
	{	
		if (array[a][b]=='e')
		{
			value++;
			cost++;
			cout<<"Path# "<<value<<" ={";
			Print(0, 0);
			cout<<"("<<b<<","<<a<<"),";
			cout<<"} Cost= "<<cost<<endl;
			status=false;
			cost=0;
			maze_maze(0,0);
			exit(1);
		}
		if (array[a][b]=='0')
		{
			count++;
			array[a][b]='!';
			if (b!=col-1)
			{
				checkNext(a, b + 1);
			}
			if(a!=row-1)
			{
				checkNext(a + 1, b);
			}
			if(b!=0)
			{
				checkNext(a, b - 1);
			}	
			if(a!=0)
			{
				checkNext(a - 1, b);
			}
			array[a][b]='1';
			status1=true;
			if (b!=col-1)
			{
				checkNext(a, b + 1);
			}
			if(a!=row-1)
			{
				checkNext(a + 1, b);
			}
			if(b!=0)
			{
				checkNext(a, b - 1);
			}
			if(a=!0)
			{
				checkNext(a - 1, b);
			}
			array[a][b]='1';
			status1=false;
		}
		if (array[a][b]=='1' && count==0)
		{
			if(b!=col-1)
			{ 
				checkNext(a, b + 1);
			}
			else if(a!=row-1)
			{
				checkNext(a + 1, b);
			}
		}
		if(array[a][b]=='1')
		{
			return 0;
		}
		if(array[a][b]=='!' && status1==true)
		{
			status1 = false;
			if(b!=col-1)
			{
				checkNext(a, b + 1);
			}
			if(b!=0)
			{
				checkNext(a, b - 1);
			}
			if(a!=row-1)
			{
				checkNext( a + 1, b);
			}
			if(a!=0)
			{
				checkNext(a - 1, b);
			}
			array[a][b]='1';
			func(a, b);
		}
	}
	void maze_maze(int a, int b)
	{
		for (int i=0;i<row;i++)
		{
			for (int j=0;j<col;j++)
			{
				if (array[i][j] == 's' || array[i][j]=='S')
				{

					if (j!=col-1 && array[i][j+1]=='e' && one==false) 
					{
						one=true;
						cout<<"Path#"<<value<<" ={"<<"("<<j<<","<<i<<"),("<<i<<","<<j+1<<")}"<<" Cost=2"<<endl;
					}
					if(j!=0 && array[i][j-1]=='e' && two==false)
					{
						two=true;
						cout<<"Path#"<<value<<" ={"<<"("<<j<<","<<i<<"),("<<i<<","<<j-1<<")}"<<" Cost=2"<<endl; 
					}
					if(i!=row-1 && array[i+1][j]=='e' && three==false) 
					{
						three=true; 
						cout<<"Path#"<<value<<" ={"<<"("<<j<<","<<i<<"),("<<i+1<<","<<j<<")}"<<" Cost=2"<<endl; 
					}
					if(i!=0 && array[i-1][j]=='e' && four==false)       
					{
						four=true; 
						cout<<"Path#"<<value<<" ={"<<"("<<j<<","<<i<<"),("<<i-1<<","<<j<<")}"<<" Cost=2"<<endl;
					}
					if(j!=col-1 && array[i][j+1]=='0')
					{
						checkNext(i, j + 1);
					}
					if(j!=0 && array[i][j-1]=='0')
					{
						checkNext(i, j - 1);
					}
					if(i!=row-1 && array[i+1][j]=='0')
					{
						checkNext(i + 1, j);
					}
					if(i!=0 && array[i-1][j]=='0')
					{
						checkNext(i - 1, j);
					}
					exit(1);
				}
			}
		}
	}
	bool Print(int a, int b)
	{
		if (status==false)
		{
			if (array[a][b]=='s' || array[a][b]=='!')
			{
				var++;
				if (array[a][b] == 's')
				{
					cost++;
					cout<<"("<<b<<","<<a<<"),";
				}
				if (array[a][b]=='!')
				{
					array[a][b]='@';
					cost++;
					cout<<"("<<b<<","<<a<<"),";
					if(b!=col-1)
					{
						Print(a, b + 1);
					}
					if(a!=row-1)
					{
						Print(a + 1, b);
					}
					if(b!=0)
					{
						Print(a, b - 1);
					}
					if(a!=0)
					{
						Print(a - 1, b);
					}	
				}
			}
			if(array[a][b]=='e')
			{			
				status = true;
				if (var <2)
				{
					status = false;
					return 0;
					if (b!=col-1)
					{
						Print(a, b + 1);
					}
					if(a!=row-1)
					{
						Print(a + 1, b);
					}
					if(b!=0)
					{
						Print(a, b - 1);
					}
					if(a!=0)
					{
						Print(a - 1, b);
					}	
				}
				return 0;
			}
			if(array[a][b]=='@')
			{
				return 0;
			}
			if(array[a][b]=='1')
			{
				return 0;
			}
			if (array[a][b]!='!')
			{
				
				if (b!=col-1)
				{
					Print(a, b + 1);
				}
				if(a!=row-1)
				{
					Print(a + 1, b);
				}
				if(b!=0)
				{
					Print(a, b - 1);
				}
				if(a!=0)
				{
					Print(a - 1, b);
				}	
			}
		}
	}
};
int main()
{	
	Maze m;
	m.set_Data();
	m.Display();
	m.maze_maze(0,0);
}
