#ifndef PLANET_H
#define PLANET_H

#include <iostream>

class Planet{
	private:
		unsigned long id;
		static unsigned long planet_id;
		int pos;
		unsigned int distance;
		char type;
	public:
		Planet();
    int orbit();
		unsigned long getID(){return this->id;}
    unsigned int getDistance(){return (unsigned)this->distance;}
		char getType(){return this->type;}
		void setId();
};

// unsigned long Planet::planet_id=0;

#endif
