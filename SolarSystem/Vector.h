#ifndef VECTOR_CW
#define VECTOR_CW

#include "Planet.h"

class Vector{
	unsigned int sizeV;
public:
	Planet ** vector;
	Vector();
	~Vector();
	void insert(int index, Planet * p);
	bool remove(int index);
	Planet * read(int index);
	unsigned int size(){ return sizeV; };
};

#endif
