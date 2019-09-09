#ifndef GALAXY_TG
#define GALAXY_TG
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "Planet.h"

class Galaxy{
private:
	std::vector<Planet> p;
public:
	Galaxy(std::string filename);
	unsigned int size();
	Planet* findByName(std::string planetName);
	void findAdjacents(Planet * kate);
	void switchMax(long * mins, Planet * p, Planet * k);
	std::vector<Planet*> shortestPath(Planet * start, Planet * dest);
	double pathDistance(Planet * start, Planet * dest);
};
#endif
