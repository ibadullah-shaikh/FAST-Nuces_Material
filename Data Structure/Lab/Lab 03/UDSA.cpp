#include "UDSA.h"
using namespace std;

UDSA::UDSA()
{
	data=NULL;
	size=0;
}
UDSA::UDSA(int n)
{
	size=n;
	data=new int[size];
}
void UDSA::set_array()
{
	int i;
	for(i=0;i<size;i++)
	{
		cout<<"Enter "<<i+1<<" Element Data:";
		cin>>*(data+i);
	}
}
UDSA::~UDSA()
{
	cout<<"Good-bye...!!"<<endl;
	delete [] data;
	data=0;
	size=0;
}
