#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <vector>
#include <cmath>
#include <cfloat>
#include "Galaxy.h"
#include "Planet.h"
#include <stack>

Galaxy::Galaxy(std::string filename){
	std::ifstream ourfile(filename);
	if(!ourfile.fail())	{
		std::string pName;
		long x;
		long y;
		long z;
		while(ourfile>>pName>>x>>y>>z){
			p.push_back(Planet(pName,x,y,z));
			//updateAdj(&p.back());
			}
		for(int i=0; i<p.size(); i++){
			findAdjacents(&p[i]);
		}
	}
}

unsigned int Galaxy::size(){
	return p.size();
}

Planet * Galaxy::findByName(std::string planetName){
	for(int i=0; i<p.size(); i++){
		if(p[i].getName() == planetName){
			return &p[i];
		}
	}
	return nullptr;
}

void Galaxy::findAdjacents(Planet * kate){
	long min[4] = {0};
	int count=0;
	Planet * switchWith=nullptr;
	for(int i=0; i<p.size(); i++){
		bool smaller=false;
		if(p[i].getName() == kate->getName()){
			continue;
		}
		if(count<4){
			min[count]=kate->distanceBetween(&p[i]);
			kate->adjacents.push_back(&p[i]);
			count++;
			continue;
		}
		for(int j=0; j < 4; j++){
			if(kate->distanceBetween(&p[i]) < min[j]){
				smaller=true;
				switchWith=&p[i];
			}
		}
		if(smaller==true){
			switchMax(min, switchWith, kate);
		}
	}
}

void Galaxy::switchMax(long * mins, Planet * p, Planet * kate){
	long max=0;
	int index=0;
	for(int i=0; i < 4; i++){
		if(mins[i]>max) {
			max=mins[i];
			index=i;
		}
	}
	mins[index]=kate->distanceBetween(p);
	kate->adjacents[index]=p;
}

std::vector<Planet*> Galaxy::shortestPath(Planet * start, Planet * dest){
	std::vector<Planet *> path;
	Planet * temp = start;
	start->dist=0;
	while(!temp->explored){
		std::vector<Planet *> v = temp->getAdjacentV();
		for(int i = 0; i < v.size(); i++){
			if(v[i]->explored) continue;
			std::cout << temp->getName() << " vs " << v[i]->getName() << std::endl;
			//std::cout << "DIST "<< v[i]->dist << " vs " << v[i]->optPrev->dist + temp->distanceBetween(v[i]->optPrev) << std::endl;
			if(v[i]->dist == 1.8 * std::pow(10, 308)){
				v[i]->optPrev = temp;
				if(temp == start){
					 v[i]->dist = temp->distanceBetween(v[i]);
				}
				else{
					v[i]->dist = v[i]->optPrev->dist + temp->distanceBetween(v[i]);
				}
			}																  //CHANGED TO V[I] FROM TEMP
			else if(v[i]->dist > v[i]->optPrev->dist + temp->distanceBetween(v[i])){
//				std::cout << v[i]->dist << " vs " << v[i]->optPrev->dist + temp->distanceBetween(v[i]) << std::endl;
				v[i]->dist = v[i]->optPrev->dist + temp->distanceBetween(v[i]);
				v[i]->optPrev = temp;
			}

			std::cout << "DIST "<< v[i]->dist << " vs " << v[i]->optPrev->dist + temp->distanceBetween(v[i]) << std::endl;
	//		std::cout << "new distance is " << v[i]->dist << " for " << v[i]->getName() << std::endl;
		}

		temp->explored = true;
		Planet * min = v[0];
		bool stubbornK8 = false;
		for(int i = 0; i < v.size(); i++){
			if((!v[i]->explored) && v[i]->dist <= min->dist){
				min = v[i];
				stubbornK8 = true;
			}
		}

		if(!stubbornK8){
			for(int i = 0; i < p.size(); i++){
				if(!p[i].explored) {
					min = &p[i];
				}
			}
		}
		std::cout<<"min is "<< min->getName()<<std::endl;
		temp = min;
	}
	temp = dest;
	while(temp != start){
		path.insert(path.begin(), temp);
		temp = temp->optPrev;
	}
	path.insert(path.begin(), start);
	return path;
}

double Galaxy::pathDistance(Planet * start, Planet * dest){

}
