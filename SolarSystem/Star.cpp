
#include "Planet.h"
#include "List.h"
#include "Vector.h"
#include "Star.h"
#include <cstdlib>
#include <iostream>

Starvector::Starvector(){
	planets = new Vector();
}

Starvector::~Starvector(){
	delete planets;
}

long Starvector::addPlanet(){
	Planet * new_planet = new Planet(rand() % 3001);
	planets->insert(planets->size(), new_planet);
	return planets->read(planets->size() - 1)->getID();
}

//Takes a Planet’s ID as a parameter, and removes the Planet from the Star.
//You must return `true` upon successful deletion and `false` on failure if the ID isn't found.
bool Starvector::removePlanet(long id){
	for(unsigned int i = 0; i < this->getCurrentNumPlanets(); i++)
	{
		if(planets->read(i)->getID()==id){
      			return planets->remove(i);
    		}
	}
	return false;
}

//Takes a Planet’s ID and returns a pointer to the Planet. If the Planet is not found, it returns NULL.
Planet * Starvector::getPlanet(long id){
	for(unsigned int i = 0; i < this->getCurrentNumPlanets(); i++)
	{
		if(planets->read(i)->getID()==id){
      			return planets->read(i);
    		}
	}
	return NULL;
}

void Starvector::orbit(){
	for(unsigned int i = 0; i < this->getCurrentNumPlanets(); i++){
		planets->read(i)->orbit();
	}
}

void Starvector::printStarInfo(){
	std::cout << "The star has " << this->getCurrentNumPlanets() << " planets." << std::endl;
	std::cout << "Planets:" << std::endl;
	for(unsigned int i = 0; i < this->getCurrentNumPlanets(); i++){
		std::cout << "Planet " << this->planets->read(i)->getType() << this->planets->read(i)->getID() << " is " <<this->planets->read(i)->getDistance() << " million miles away at position " << this->planets->read(i)->getPos() << " around the star." << std::endl;
      	}
}


// ====================STARLIST============================

Starlist::Starlist(){
  this->stars=new List();
}

Starlist::~Starlist(){
	delete stars;
}

long Starlist::addPlanet(){
	Planet * toAdd = new Planet(rand() % 3001);
	long id=toAdd->getID();
	stars->insert(stars->size(), toAdd);
	return id;
}

bool Starlist::removePlanet(long id){
	stars->reset();
	int index=stars->getIndex(id);
	if(index==-1) return NULL;
	return stars->remove(index);
}



Planet * Starlist::getPlanet(long id){
	stars->reset();
	int index=stars->getIndex(id);
	if(index==-1) return NULL;
	return stars->read(index);
}

void Starlist::orbit(){
	stars->reset();
  int index=0;
  while(stars->read(index)!=NULL){
    stars->read(index)->orbit();
    index++;
  }

}

void Starlist:: printStarInfo(){
	stars->reset();
	std::cout << "The star has " << stars->size() << " planets." << std::endl;
  std::cout << "Planets:" << std::endl;
  for(unsigned i = 0; i <getCurrentNumPlanets(); i++){
		std::cout << "Planet " << stars->read(i)->getType() << stars->read(i)->getID() << " is " << stars->read(i)->getDistance()<< " million miles away at position " << stars->read(i)->getPos() << " around the star." << std::endl;
      }
}
unsigned int Starlist:: getCurrentNumPlanets(){
	return stars->size();
}
