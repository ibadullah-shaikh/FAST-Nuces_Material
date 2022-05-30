#include<iostream>
#include<string.h>
using namespace std;
bool isPalin(char arr[]);
bool PalinRec(char arr[], int, int);
int main()
{
	char array[]={"FAST"};
	
	if(isPalin(array))
	{
		cout<<"Array is Palindrome..!!"<<endl;
	}
	else
	{
		cout<<"Array is Not Palindrome..!!"<<endl;
	}
}
bool isPalin (char arr[])
{
	int n=strlen(arr);
	if(n==0)
	{
		return true;
	}
	
	return PalinRec(arr,0,n-1);
}
bool PalinRec(char arr[], int a, int b)
{
	if(a==b)
	{
		return true;
	}
	else if(arr[a]!=arr[b])
	{
		return false;
	}
	else if(a<b+1)
	{
		return PalinRec(arr, a+1,b-1);
	}
	return true;
}
