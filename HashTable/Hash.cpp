#include "Hash.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cassert>

Node::Node(){
	key="";
	value=-1.0;
}

Hash::Hash(unsigned int size){
	hashBrown=new Node[size];
	//Node list[size];
	hSize=size;
	for(int i=0; i<hSize; i++){
		Node toAdd=Node();
		hashBrown[i]=toAdd;
		//assert(list[i]->key.empty());
	}
	//hashBrown=list;
}

unsigned int Hash::hasher(std::string key){
	int sum=0;
	for(int i=0; i<key.size();i++){
		sum+=(int)key[i];
	}
	unsigned int index=sum % hSize;
	return index;
}

bool Hash::insert(std::string key, double value){
//	for(int i=0; i<hSize; i++){
//		if(hashBrown[i].key==key) return false; //change
//	}
	bool full=true;
	for(int i=0; i<hSize; i++){
		if(hashBrown[i].key=="") full=false;
	}

	if(full==true) return false;
	unsigned int index=hasher(key);
	if(hashBrown[index].key.empty()){
		hashBrown[index].key=key;
		hashBrown[index].value=value;
		return true;
	}
	//bool full=false;
	bool once=true;
	for(int i=index+1; i<hSize; i++){
		if(hashBrown[i].key.empty()){
			hashBrown[i].key=key;
			hashBrown[i].value=value;
			return true;
		}
		if(i==hSize-1 && once){
			i=-1;
			once=false;
		}
	}

	return false;
}

bool Hash::empty(){
	bool empty=true;
	for(int i=0;i<hSize; i++){
		if(hashBrown[i].key.empty()==false) return false;
	}
	return true;
}

int Hash::size(){
	return hSize;
}

Node * Hash::getTable(){
	return hashBrown;
}

bool Hash::remove(std::string key){
	for(int i=0; i<hSize; i++){
		if(hashBrown[i].key==key){
			hashBrown[i]=Node();
			return true;
		}
	}
	return false;
}

double Hash::find(std::string key){
	for(int i=0; i<hSize; i++){
		if(hashBrown[i].key==key){
			return hashBrown[i].value;
		}
	}
	return -1.0;
}


 Hash::~Hash(){
 	delete[] hashBrown;
 	hashBrown=nullptr;
 }
