#include<iostream>
using namespace std;
void BubbleSort(int [], int);
void SelectionSort(int [], int);
void InsertionSort(int [], int);
int main()
{
	int n=5,array[5]={2,3,1,5,4},i,j;
	int arr[5]={5,4,3,2,1};
	int arr2[5]={4,2,1,5,3};
	cout<<"Actual Array: ";
	for(i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl<<endl;
	InsertionSort(array,n);
	cout<<endl<<endl;
	SelectionSort(arr,n);
	cout<<endl<<endl;
	BubbleSort(arr2,n);
	
	return 0;
}
void BubbleSort(int array[], int size)
{
	int i,j;
	for(i=0;i<size-1;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
			if(array[j]>array[j+1])
			{
				int temp;
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
	cout<<"Bubble Sorted Array: ";
	for(i=0;i<size;i++)
	{
		cout<<array[i]<<" ";
	}

}
void SelectionSort(int array[], int size)
{
	int i,j,min;
	for (i=0;i<size-1;i++)  
    {  
        min=i;  
        for(j=i+1;j<size;j++)  
        if (array[j]<array[min])  
    	{
    		min=j;
		}
		int temp;
		temp=array[min];
		array[min]=array[i];
		array[i]=temp;  
    }
	cout<<"Selection Sorted Array: ";
	for(i=0;i<size;i++)
	{
		cout<<array[i]<<" ";
	}
}
void InsertionSort(int array[], int size)
{
	int i,j,n;  
	for (i=1;i<size;i++) 
	{  
		n=array[i];
		j=i-1;
		while (j>=0 && array[j]>n)
		{
			array[j+1]=array[j];
			j=j-1;
		}
		array[j+1]=n;
	}
	cout<<"Insertion Sorted Array: ";
	for(i=0;i<size;i++)
	{
		cout<<array[i]<<" ";
	}
}
