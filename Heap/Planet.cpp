#include "Planet.h"
#include <cstdlib>
#include <iostream>
#include <cstdio>

Planet::Planet(std::string i, double p){
	id = i;
	probability = p;
}

std::string Planet::getName(){
	return id;
}

double Planet::getProbability(){
	return probability;
}

double Planet::refine(double r){
//	if(probability == 100 || probability == 0) return probability;
	probability += r;
	if(probability > 100){
		probability = 100;
	}
	else if(probability < 0){
		probability = 0;
	}
	return probability;
}

bool Planet::operator>(const Planet & p2){
	return probability > p2.probability;
}
bool Planet::operator<(const Planet & p2){
	return probability < p2.probability;
}
bool Planet::operator>=(const Planet & p2){
	return probability >= p2.probability;
}
bool Planet::operator<=(const Planet & p2){
	return probability <= p2.probability;
}
bool Planet::operator==(const Planet & p2){
	return probability == p2.probability;
}
bool Planet::operator!=(const Planet & p2){
	return probability != p2.probability;
}
