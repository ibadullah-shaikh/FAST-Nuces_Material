#include<iostream>
using namespace std;
int Sum_Num (int*, int);
int main()
{
	int n=10;
	int array[n], *ptr, i;
	cout<<"Enter 10 the values of Array...!!"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>array[i];
	}
	ptr= array;
	int x;
	x=Sum_Num(ptr, n);
	cout<<"Sum of Even Numbers in array is: "<<x<<endl;
}
int Sum_Num (int *ptr, int n)
{
	if (n==0)
	{
		return 0;
	}
	else
	{
		if(((*ptr+n)%2)==0)
		{
			return *(ptr+n) + Sum_Num(ptr, n-1);
		}
		else
		{
			Sum_Num(ptr, n-1);
		}
	}
}
