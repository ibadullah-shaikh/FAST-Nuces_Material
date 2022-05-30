#ifndef ODSA_H
#define ODSA_h
#include"DSA.cpp"
class ODSA : public DSA
{
	public:
		ODSA();
		ODSA(int);
		~ODSA();
		void set_array();
		void order_array();
};
#endif
