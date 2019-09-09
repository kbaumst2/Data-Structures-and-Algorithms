#include "Trie.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <utility>
#include <vector>

Trie::Trie(){
	leaves=0;
	nodes=0;
}

bool Trie::add(std::pair<std::string, double> p){
	Node * temp=&root;
	std::string copy=p.first;
	bool last=false;
	for(int i=0; i<copy.size(); i++){
			if(!isChild(temp, copy[i])){
				(*temp).children.push_back(Node(copy.at(i), -1));
				nodes++;
						if(i==copy.size()-1){
							int index=findChildIndex(temp, copy[i]);
							temp=&((*temp).children[index]);
							(*temp).children.push_back(Node('\0', p.second));
							nodes++;
							leaves++;
							return true;
						}
					}
		if(!last) {
			int index=findChildIndex(temp, copy[i]);
			temp=&((*temp).children[index]);
			}
	}
	return false;
}

int Trie::findChildIndex(Node * p, char c){
	for(int i=0; i<(*p).children.size(); i++){
		if((*p).children[i].key==c) return i;
	}
}

bool Trie::isChild(Node * r, char key){
	for(int i=0; i<(*r).children.size(); i++){
		if((*r).children[i].key==key) return true;
	}
	return false;
}


unsigned int Trie::numLeaves(){
	return leaves;
}

unsigned int Trie::numNodes(){
	return nodes;
}


void Trie::printTrie(){
	 Node * temp=&root;
	 printHelper(temp);
	 std::cout<<"Trie Complete"<<std::endl;
}

void Trie::printHelper(Node * p){
  std::cout<<"Parent: (key)"<<p->key<< ":(value) " << p->data <<std::endl;
	if(p->children.size()>0){
		for(int i=0; i<p->children.size(); i++){
			std::cout<<"	-----> Child: (key) "<<p->children[i].key<< " : (value) "<<p->children[i].data<<std::endl;
			if(i==p->children.size()-1) std::cout<< " " <<std::endl;
			}
		for(int i=0; i<p->children.size(); i++){
			printHelper(&(p->children[i]));
		}
	}
}


double Trie::search(std::string str){
	Node * temp=&root;
	for(int i=0; i<str.length(); i++){
		if(isChild(temp, str[i])){
			int index=findChildIndex(temp, str[i]);
			temp=&(temp->children[index]);
			if(i==str.length()-1){
				if(temp->children[0].key=='\0'){
					return temp->children[0].data;
				}
			}
		}
	}
	return -1;
}
