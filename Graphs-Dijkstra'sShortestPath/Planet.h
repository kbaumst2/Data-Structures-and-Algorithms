#ifndef PLANET_H
#define PLANET_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include <vector>


class Planet{
private:
	std::string name;
	long xCoor;
	long yCoor;
	long zCoor;
public:
	bool explored;
	double dist;
	Planet * optPrev;
//	char flag = 'w';
	std::vector<Planet*> adjacents;
	double distanceBetween(Planet * p2);
	Planet(std::string planetName, long xCoor, long yCoor, long zCoor);
	std::string getName();
	long getXCoor();
	long getYCoor();
	long getZCoor();
	std::list<Planet*> getAdjacent();
	std::vector<Planet*> getAdjacentV();
};

#endif
