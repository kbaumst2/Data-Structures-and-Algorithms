#include "Planet.h"
#include "Star.h"
#include <stdlib.h>
#include <iostream>
#include <cstdlib>

Star::Star(){
	planets=NULL;
	this->next_id=0;
	this->current_planets=0;

	}

int Star::addPlanet(){
	Planet ** added_planet=new Planet *[1+current_planets];
	for(int i=0; i<current_planets; i++){
		added_planet[i]=this->planets[i];
		}
	Planet* toAdd=new Planet(next_id);
	added_planet[current_planets]=toAdd;
	this->current_planets++;
	int toReturn=next_id;
	this->next_id++;
	delete[] this->planets;
	planets=added_planet;
	return toReturn;
	}


bool Star::removePlanet(int id){
	if(getPlanet(id)==NULL){
		return false;
		}
	//bool isRemoved=false;
	int index=0;
	Planet ** removed_planet=new Planet*[current_planets-1];
	for(int i=0; i<current_planets; i++){
		if(planets[i]->getID()==id){
			delete this->planets[i];
			//index=index-1;
			}
		else{
			removed_planet[index]=planets[i];
			index++;
			}
		}
	this->current_planets--;
	delete[] this->planets;
	this->planets=removed_planet;
	return true;;
	}

Planet * Star::getPlanet(int id){
	for(int i=0; i<current_planets; i++){
		if((*planets[i]).getID()==id){
			return planets[i];
			}
		}
	return NULL;
	}


void Star::orbit(){
	for(int i=0;i<this->current_planets; i++){
		 planets[i]->orbit();
		}
}

void Star::printStarInfo(){
	std::cout<<"The star currently has " << this->current_planets <<" planets." <<std::endl;
	std::cout<<"Planets: "<<std::endl;
	for(int i=0; i<current_planets; i++){
		std::cout<<"Planet " <<planets[i]->getType()<< planets[i]->getID() <<" is "<< planets[i]->getDistance() << " million miles away at position " << planets[i]->getPos() <<" around the star."<< std::endl;
		}
	}

Star::~Star(){
	for(int i=0; i<current_planets; i++){
		delete planets[i];
		}
	delete[] planets;
	}
