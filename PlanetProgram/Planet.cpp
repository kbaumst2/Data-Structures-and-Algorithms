#include "Star.h"
#include "Planet.h"
#include <stdlib.h>
#include <iostream>
#include <cstdlib>


Planet::Planet(int id){
	this->id = id;
    this->pos = rand() % 359;
	char types[]={'h', 'r', 'g'};
	this->type=types[rand()%3];
	this-> distance=rand() % 3000 ;
	
}

int Planet::orbit(){
	if(this->pos==359){
		this->pos=0;
		}
	else{
		this->pos+=1;
		}
	return this->pos;
	}

