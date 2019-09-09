#ifndef SCANNER_TG
#define SCANNER_TG
#include <string>
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <vector>
#include "Planet.h"
#include "Parser.h"
#include "Heap.h"

class Scanner{
private:
  Heap<Planet> h;
public:
  Scanner(std::vector<Planet>);
  std::vector<Planet> scan(unsigned int num_planets);
  void addPlanet(Planet p);
  Heap<Planet> getHeap();
};
#endif
