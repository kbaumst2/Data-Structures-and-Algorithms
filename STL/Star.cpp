#include "Star.h"
#include "Planet.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <memory>


unsigned long Star::addPlanet(){
	this->vect.push_back(Planet());
	return (unsigned long)vect[vect.size()-1].getID();
}

bool Star::removePlanet(unsigned long id){
	for(std::vector<Planet>::iterator i=vect.begin(); i<vect.end(); i++){
		if(i->getID()==id) {
			vect.erase(i);
			return true;
			break;
		}
	}
	return false;
}

Planet * Star::getPlanet(unsigned long id){
	int index=0;
	for(auto i=vect.begin(); i!=vect.end(); i++){
		if((*i).getID()==id){
				return &(vect.at(index));
		}
		index++;
	}

	return nullptr;
}

std::vector<Planet>& Star::getPlanets(){
	return vect;
}
