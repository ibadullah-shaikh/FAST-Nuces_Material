#include<iostream>
using namespace std;
int main()
{
	int array[]={9,5,6,8,1,2,5,7},n=8,i,j,temp;
	
	for(i=0;i<n;i++)
	{
		temp=array[i];
		j=i-1;
		while(j>=0 && array[j]>temp)
		{
			array[j+1]=array[j];
			j--;
		}
		array[j+1]=temp;
	}
	for(i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
}
