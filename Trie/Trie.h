#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <utility>

class Trie{
private:
	int leaves;
	int nodes;
	class Node{
	public:
		std::vector<Node> children;
		char key;
		double data;
		bool leaf;
		Node(char k, double d){
			key=k;
			data=d;
			}
		};
	//Node root;
	Node root=Node('?', -1);
public:
	Trie();
	bool add(std::pair<std::string,double>);
	unsigned int numLeaves();
	unsigned int numNodes();
	void printTrie();
	int findChildIndex(Node *, char );
	void printHelper(Node * p);
	bool isChild(Node * p, char key);
	double search(std::string);
};

#endif
