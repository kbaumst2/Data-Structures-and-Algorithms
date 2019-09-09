#ifndef PLANET_H
#define PLANET_H
#include <string>
#include <cstdlib>
#include <iostream>
#include <cstdio> 

class Planet{
private:
	std::string id;
	double probability;
public:
	Planet(std::string i, double p);
	std::string getName();
	double getProbability();
	double refine(double r);
	bool operator>(const Planet & p2);
	bool operator<(const Planet & p2);
	bool operator>=(const Planet & p2);
	bool operator<=(const Planet & p2);
	bool operator==(const Planet & p2);
	bool operator!=(const Planet & p2);
};

#endif
