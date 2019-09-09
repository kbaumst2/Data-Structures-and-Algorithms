#include "Planet.h"
#include <cstdlib>

Planet::Planet(int distance){
	this->id = (long int) this;
	this->distance = distance;
	this->pos = rand() % 360;
	int planet_type = rand() % 3;
	switch(planet_type){
	case 0 : this->type = 'h'; break;
	case 1 : this->type = 'r'; break;
	case 2 : this->type = 'g'; break;
	}
}	

int Planet::orbit(){
	this->pos++;
	if(this->pos == 360) this->pos = 0;
	return this->pos;
}

