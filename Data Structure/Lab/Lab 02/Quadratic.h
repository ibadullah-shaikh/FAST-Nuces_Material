//#ifndef QUADRATIC_H
#define QUADRATIC_H

namespace N
{
	class Quadratic
	{
		float a,b,c,x1,x2;
		public:
			void Store_Data(float a, float b, float c);
			void Calc_Quad();
			void Display();
	};
}
