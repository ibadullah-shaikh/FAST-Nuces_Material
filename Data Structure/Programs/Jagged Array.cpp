#include<iostream>
#include <vector>
using namespace std;
int main()
{
	int i,j,ele, row=0, col;
	vector<vector <int> > vec;
	cout<<"Enter No. Colomns:";
	cin>>col;
	for(i=0;i<col;i++)
	{
		vector<int> t;
		cout<<"Enter No. of Rows in Colom "<<i+1<<":";
		cin>>row;
		for(j=0;j<row;j++)
		{
			cout<<"Enter Row Elements:";
			cin>>ele;
			t.push_back(ele);
		}
		vec.push_back(t);
	}
	
}
