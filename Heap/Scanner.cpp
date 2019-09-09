#include <string>
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <vector>
#include "Planet.h"
#include "Parser.h"
#include "Heap.h"
#include "Scanner.h"

Scanner::Scanner(std::vector<Planet> v){
  h = Heap<Planet>(v);
}

std::vector<Planet> Scanner::scan(unsigned int num_planets){
  if(num_planets > h.size()){
    num_planets = h.size();
  }
  std::vector<Planet> toScan;
  for(int i = 0; i < num_planets; i++){
    toScan.push_back(h.getPriority());
  }
  for(int i = 0; i < toScan.size(); i++){
    if(toScan[i].getProbability() == 0 || toScan[i].getProbability() == 100) continue;
    int refineNum = rand() % 2;
    if(refineNum == 0){
      toScan[i].refine(1.0);
    }
    else{
      toScan[i].refine(-1.0);
    }
  }
  return toScan;
}

void Scanner::addPlanet(Planet p){
  h.addElement(p);
}

Heap<Planet> Scanner::getHeap(){
  return h;
}
