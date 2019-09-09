#ifndef HASH_H
#define HASH_H
#include <iostream>
#include<cstdlib>
#include <string>

class Node{
public:
	std::string key;
	double value;
	Node();
};

class Hash{
private:
	Node * hashBrown;
	int hSize;
public:
	Hash(unsigned int size);
	unsigned int hasher(std::string key);
	bool insert(std::string key, double value);
	bool empty();
	int size();
	Node * getTable();
	bool remove(std::string key);
	double find(std::string key);
	~Hash();
};
#endif
