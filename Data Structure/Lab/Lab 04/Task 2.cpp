#include<iostream>
using namespace std;
int Reverse_Array(int* ,int, int, int copyarr[]);
int main()
{
	int n=10,i,*ptr;
	int array[n], copyarr[n];
	cout<<"Enter the 10 values of an Array:"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>array[i];
		copyarr[i]=array[i];
	}
	ptr=array;
	system("cls");
	cout<<"Actual Array: ";
	for(i=0;i<n;i++)
	{
		cout<<*(ptr+i)<<" ";
	}
	Reverse_Array(ptr, n, 0, copyarr);
	cout<<endl<<endl;
	cout<<"Reversed Array: ";
	for(i=0;i<n;i++)
	{
		cout<<*(ptr+i)<<" ";
	}
	
}

int Reverse_Array (int *ptr, int n, int initial, int copyarr[])
{
	if(n==0)
	{
		return 1;
	}
	else
	{
		*(ptr+initial)=copyarr[n-1];
		Reverse_Array(ptr, n-1, initial+1, copyarr);
	}
}
