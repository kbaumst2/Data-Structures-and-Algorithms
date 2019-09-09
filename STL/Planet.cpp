#include "Planet.h"
#include <stdlib.h>
#include <iostream>

Planet::Planet(){
	this->id = this->planet_id++;
	char types[]={'h', 'r', 'g'};
	this->type=types[rand()%3];
	this->distance=(rand() % 3001) +1;

}
unsigned long Planet::planet_id=0;
