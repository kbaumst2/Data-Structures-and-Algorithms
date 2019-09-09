#ifndef LIST_K
#define LIST_K

#include "Planet.h"
#include <iostream>

class Node{
public:
	Planet * data;
	Node * next, * prev;
	Node(Planet * p) {data=p; next=NULL; prev=NULL;}
	};

class List{
private:
	Node *head, *tail, *current;
public:
	List();
	~List();
	void insert(int index, Planet * p);
	Planet* read(int index);
	bool remove(int index);
	unsigned size();
	void reset();
	void next();
	void addAtHead(Node * p);
	void addAtTail(Node *p);
	int getIndex(long id);
};

#endif
