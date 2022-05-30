#ifndef DSA_H
#define DSA_H

namespace N
{
	class DSA
	{
		protected:
		int size;
		int *data;
		public:
			DSA();
			~DSA();
			DSA(int);
			DSA(const DSA &d);
			void Searching(int);
			void Insertion(int,int);
			void Display();
	};
}
#endif
