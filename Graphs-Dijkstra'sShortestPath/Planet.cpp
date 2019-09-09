#include "Planet.h"
#include "Galaxy.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include <vector>
#include <cmath>
#include <cfloat>

using namespace std;

Planet::Planet(std::string planetName, long x, long y, long z){
	name=planetName;
	xCoor=x;
	yCoor=y;
	zCoor=z;
	explored = false;
	dist = 1.8 * std::pow(10, 308);
	optPrev = nullptr;
}

string Planet::getName(){
	return name;
}

long Planet::getXCoor(){
	return xCoor;
}

long Planet::getYCoor(){
	return yCoor;
}

long Planet::getZCoor(){
	return zCoor;
}

double Planet::distanceBetween(Planet * p2){
	return sqrt(std::pow(this->getXCoor() - p2->getXCoor(), 2) + std::pow(this->getYCoor() - p2->getYCoor(), 2) + std::pow(this->getZCoor() - p2->getZCoor(), 2));
}

list<Planet*> Planet::getAdjacent(){
	list<Planet*> adjs;
	for(int i=0; i<adjacents.size();i++){
		adjs.push_back(adjacents[i]);
	}
	return adjs;
}

vector<Planet*> Planet::getAdjacentV(){
	return adjacents;
}
