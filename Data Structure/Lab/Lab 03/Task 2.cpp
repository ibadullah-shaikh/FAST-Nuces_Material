#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int j,i,r=0,n=0,c=0;
	vector< vector<int> >v;
	cout<<"Enter No. Of Rows:";
	cin>>r;
	for(i=0;i<r;i++)
	{
		vector<int>z;
		cout<<"Enter No. of Colomns:";
		cin>>c;
		for(j=0;j<c;j++)
		{
			cout<<"Enter "<<j+1<<" coloumn element:";
			cin>>n;
			z.push_back(n);
		}
		v.push_back(z);
	}
	system("cls");
	cout<<"Jagged Array Set done..!! Now Displaying...!!"<<endl<<endl;
	for(i=0;i<v.size();i++)
	{
		for(j=0;j<v[i].size();j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}
