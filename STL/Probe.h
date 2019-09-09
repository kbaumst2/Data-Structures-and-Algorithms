#ifndef PROBE_H
#define PROBE_H
#include "Planet.h"
#include "Star.h"
#include <queue>

class Probe{
	std::queue<Planet> queue;

public:
	std::vector<Planet> getHabitable(Star s);
	void addToQueue(Planet p);
	Planet getNext();
	std::queue<Planet>& getQueue();
	void shuffle();

};
#endif
