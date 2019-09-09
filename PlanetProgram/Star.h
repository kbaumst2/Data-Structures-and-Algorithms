#ifndef STAR_H
#define STAR_H

#include "Planet.h"

class Star{
	private:
        int current_planets;
        int next_id;
	public:
        Planet ** planets;
        Star();
        int addPlanet();
		bool removePlanet(int);
		Planet * getPlanet(int);
        Planet getFurthest();
        void orbit();
        void printStarInfo();
        int getCurrentNumPlanets(){return this->current_planets; }
		~Star();
        //you may add any additional methodas you may need.
};

#endif
