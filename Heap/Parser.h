#ifndef PARSER_H
#define PARSER_H

#include "Planet.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <cstdio> 
#include <vector>

class  Parser{
private:
	std::vector<Planet> vect;
public:
	Parser(std::string filename);
	std::vector<Planet> getPlanets();

};

#endif
