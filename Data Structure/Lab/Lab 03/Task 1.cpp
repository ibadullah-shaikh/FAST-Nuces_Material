#include "UDSA.cpp"
using namespace N;
int main()
{
	DSA d1(5);
	d1.Searching(0);
	d1.Insertion(1,7);
	d1.Display();
	cout<<endl<<endl;
	cout<<"Another object...!!"<<endl;
	DSA d2(6);
	d2.Searching(3);
	d2.Insertion(7,2);
	d2.Display();
	cout<<endl<<endl;
	cout<<"ODSA Object..!!"<<endl;
	ODSA o(4);
	o.set_array();
	o.order_array();
	o.Searching(4);
	o.Insertion(3,6);
	o.Display();
	cout<<endl<<endl;
	cout<<"UDSA Object...!!"<<endl;
	UDSA u(5);
	u.set_array();
	u.Searching(5);
	u.Insertion(5,7);
	u.Display();
	

}
