#include"Quadratic.cpp"
using namespace N;
int main()
{
	Quadratic q;
	float a,b,c;
	cout<<"Enter A:"; cin>>a;
	cout<<"Enter B:"; cin>>b;
	cout<<"Enter C:"; cin>>c;
	
	q.Store_Data(a,b,c);
	q.Calc_Quad();
	q.Display();
}
