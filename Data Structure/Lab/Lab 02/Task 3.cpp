#include"Car.cpp"
using namespace N;
int main()
{
	Car c,cc;
	c.Set_Data();
	system("cls");
	c.Display();
	cout<<endl<<endl<<"Now copying object's 1 data to Object to and Displaying..!!"<<endl<<endl;
	cc=c;
	cc.Display();
}
