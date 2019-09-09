#include "Probe.h"
#include "Planet.h"
#include "Star.h"
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>

std::vector<Planet> Probe::getHabitable(Star s){
	std::vector<Planet> habitable;
	std::vector<Planet> allPlanets=s.getPlanets();
	for(std::vector<Planet>::iterator i=allPlanets.begin(); i<allPlanets.end(); i++){
		if(i->getType() == 'h' && i->getDistance()>60 && i->getDistance()<140){
			habitable.push_back(*i);
			}
	}
	return habitable;
}

void Probe::addToQueue(Planet p){
	this->queue.push(p);
}

Planet Probe::getNext(){
	if(!this->queue.empty()){
		Planet retVal=this->queue.front();
		this->queue.pop();
		return retVal;
	}
}

std::queue<Planet>& Probe::getQueue(){
	return this->queue;
}

void Probe::shuffle(){
	std::vector<Planet> temp;
	std::vector<int> indexes;

	int size=queue.size();
	for(int i=0; i<size; i++){
		temp.push_back(getNext());    
		indexes.push_back(i);
	}
	for(int i=0; i< temp.size(); i++){
		int ranIndex=rand()% indexes.size();
		int toRem=indexes.at(ranIndex);
		this->queue.push(temp.at(ranIndex));
		for(std::vector<int>::iterator it=indexes.begin(); it<indexes.end(); it++){
			if(*it==toRem){
				indexes.erase(it);
				break;
			}
		}
	}
}
