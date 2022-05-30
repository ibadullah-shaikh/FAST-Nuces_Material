#include<iostream>
using namespace std;
class MinHeap
{
	int *harr;
	int capacity;
	int heap_size;
public:
	MinHeap(int cap)
	{
		heap_size = 0;
		capacity = cap;
		harr = new int[cap];
	}
	void MinHeapify(int i)
	{
		int l=left(i);
		int r=right(i);
		int smallest=i;
		if(l<heap_size && harr[l]<harr[i])
		{
			smallest = l;
		}
		if(r<heap_size && harr[r]<harr[smallest])
		{
			smallest=r;
		}
	    if (smallest!=i)
		{
			swap(&harr[i], &harr[smallest]);
			MinHeapify(smallest);
		}
	}
	int parent(int i)
	{
		return (i-1)/2;
	}
	int left(int i)
	{
		return (2*i + 1);
	}
	int right(int i)
	{
		return (2*i + 2);
	}
	int getMin()
	{
		return harr[0];
	}
	void insertKey(int k)
	{
		if (heap_size == capacity)
		{
			cout<<endl<<"Overflow: Could not insertKey\n"<<endl;
			return;
		}
		heap_size++;
		int i = heap_size - 1;
		harr[i] = k;
		while (i != 0 && harr[parent(i)] > harr[i])
		{
			swap(&harr[i], &harr[parent(i)]);
			i=parent(i);
		}
	}
	void swap(int *x, int *y)
	{
		int temp = *x;
		*x = *y;
		*y = temp;
	}
	void Print()
	{
		for(int i=0;i<capacity;i++)
		{
			cout<<harr[i]<<" ";
		}
	}
};
int main() 
{ 
	MinHeap h(6);
	h.insertKey(3);
	h.insertKey(2);
	h.insertKey(15);
	h.insertKey(5);
	h.insertKey(4);
	h.insertKey(45);
	h.Print();
}
