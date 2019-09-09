#ifndef STAR_H
#define STAR_H

#include "Planet.h"
#include <vector>

class Star{
	private:
    int current_planets;
    unsigned long next_id;
	public:
		std::vector<Planet> vect;
    unsigned long addPlanet();
		bool removePlanet(unsigned long);
		Planet * getPlanet(unsigned long);
		std::vector<Planet> & getPlanets();
    int getCurrentNumPlanets(){return this->current_planets; }
};

#endif
