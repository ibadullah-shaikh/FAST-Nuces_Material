#include "ODSA.h"
using namespace std;

void ODSA::order_array()
{
	int temp, i, j;
	for(i=0;i<size;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if( *(data+i) > *(data+j) )
			{
				temp= *(data+i);
				*(data+i)=*(data+j);
				*(data+j)=temp;
			}
		}
	}
}
ODSA::ODSA(int n)
{
	size=n;
	data=new int[size];
}
ODSA::~ODSA()
{
	cout<<"Good-bye...!!"<<endl;
	delete [] data;
	data=0;
	size=0;
}
void ODSA::set_array()
{
	int i;
	for(i=0;i<size;i++)
	{
		cout<<"Enter "<<i+1<<" Element Data:";
		cin>>*(data+i);
	}
}
