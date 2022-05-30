#include <iostream>
using namespace std;
int main()
{
	int array[]={5,4,2,1,3}, i,j, temp, n=5;
	cout<<"Before Sorting...!!"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
	
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(array[j] > array[j+1])
			{
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
	
	cout<<endl<<endl<<"After Sorting...!!"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
}
