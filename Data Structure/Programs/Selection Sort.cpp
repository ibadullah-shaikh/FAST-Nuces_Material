#include<iostream>
using namespace std;
int main()
{
	int array[]={64,12,22,11,16,5}, i,j, n=6;
	cout<<"Before Insertion Sorting...!!"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
	
	cout<<endl<<endl;
	int min;
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i;j<n;j++)
		{
			if(array[j] < array[min])
			{
				min= j;
			}
		}
		if(min!= i)
		{
			int temp= array[i];
			array[i]= array[min];
			array[min]= temp;
		}
	}
	
	cout<<"After Insertion Sorting...!!"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
}
