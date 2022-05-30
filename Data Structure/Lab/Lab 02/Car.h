#define CAR_H
#include<iostream>
using namespace std;
namespace N
{
	class Car
	{
		int model;
		string name, color;
		public:
			Car(); 
			~Car();	
			Car(const Car &c1);
			void Set_Data();
			void Display();
			void operator =(Car c1);
	};
}
