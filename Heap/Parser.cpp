#include "Parser.h"
#include "Planet.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <cstdio> 
#include <fstream>
#include <vector>


Parser::Parser(std::string filename){
	std::ifstream ourfile(filename);
	if(!ourfile.fail())	{
		std::string pName;
		double prob;
		while(ourfile>>pName>>prob){
			Planet p=Planet(pName,prob);
			vect.push_back(p);
			}	
	}	
}

std::vector<Planet> Parser::getPlanets(){
	return vect;
}

