
#ifndef STAR_CW
#define STAR_CW
#include "Planet.h"
#include "List.h"
#include "Vector.h"


class Starlist{
public:
	List * stars;
	Starlist();
	~Starlist();
	long addPlanet();
	bool removePlanet(long);
	Planet * getPlanet(long);
	void orbit();
	void printStarInfo();
	unsigned int getCurrentNumPlanets();
};


class Starvector{
public:
	Vector * planets;
	Starvector();
	~Starvector();
	long addPlanet();
	bool removePlanet(long);
	Planet * getPlanet(long);
	void orbit();
	void printStarInfo();
	unsigned int getCurrentNumPlanets(){ return planets->size(); };
};



#endif
