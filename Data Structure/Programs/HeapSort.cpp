#include<iostream>
using namespace std;
void Swap(int*, int *);
void HeapSort(int[], int);
void Heapify(int [],int,int);
int main()
{
	int arr[]={8,1,4,3,2,7,5,9},n=8;
	HeapSort(arr,n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
void HeapSort(int arr[],int n)
{
	for(int i=n/2-1;i>=0;i--)
	{
		Heapify(arr,n,i);
	}
	for(int i=n-1;i>=0;i--)
	{
		Swap(&arr[0],&arr[i]);
		Heapify(arr,i,0);
	}
}
void Swap(int *a, int *b)
{
	int temp;
	temp=*(a);
	*(a)=*(b);
	*(b)=temp;
}
void Heapify(int arr[], int n, int i)
{
	int large=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && arr[l]>arr[large])
	{
		large=l;
	}
	if(r<n && arr[r]>arr[large])
	{
		large=r;
	}
	if(large!=i)
	{
		Swap(&arr[i],&arr[large]);
		Heapify(arr,n,large);
	}
}
