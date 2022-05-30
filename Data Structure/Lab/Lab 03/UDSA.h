#ifndef UDSA_H
#define UDSA_h
#include"ODSA.cpp"
class UDSA : public DSA
{
	public:
		UDSA();
		UDSA(int);
		~UDSA();
		void set_array();	
};

#endif
