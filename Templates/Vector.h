#ifndef VECTOR_H
#define VECTOR_H

#include <cstdlib>
#include <iostream>

template <class T>
class Vector{
	unsigned int sizeV;
public:
	T * vector;
	Vector(int size);
	Vector(const Vector<T> & v);
	T & operator[](std::size_t index);
	~Vector();
	void insert(int index, T p);
	T remove(int index);
	T read(int index);
	unsigned int size(){ return sizeV; }
	void clear();
};

template<class T>
Vector<T>::Vector(int size){
	this->vector=new T[size];
	this->sizeV=size;
}

template<class T>
Vector<T>::Vector(const Vector<T> & v){
	sizeV=v.sizeV;
	this->vector=new T[sizeV];
	for(int i=0; i<sizeV; i++){
		this->vector[i]=v.vector[i];
		}
	}

template<class T>
T & Vector<T>:: operator[](std::size_t index){
	if(index<sizeV) {
	return vector[index];
	}
}

template<class T>
void Vector<T>:: clear(){
	for(unsigned int i=0; i<sizeV; i++){
		vector[i]=NULL;
	}
	this->sizeV=0;
}

template<class T>
Vector<T>::~Vector(){
	this->clear();
	delete[] vector;
	vector=NULL;
}

template<class T>
void Vector<T>::insert(int index, T p){
	if(vector == NULL){
		vector = new T[index+1];
		vector[index] = p;
		sizeV = index+1;
		return;
	}
	if(index >= sizeV){
		T * temp = new T[index+1];
		for (unsigned int i = 0; i < sizeV; i++){
			temp[i] = vector[i];
		}
		delete[] vector;
		vector = temp;
		vector[index] = p;
		for (int i = sizeV; i < index; i++){
			vector[i] = NULL;
		}
		sizeV = index+1;
		return;
	}
	T * temp = new T[sizeV+1];
	for (int i = 0; i < index; i++){
		temp[i] = vector[i];
	}
	for (unsigned int j = index; j < sizeV; j++){
		temp[j+1] = vector[j];
	}
	delete[] vector;
	vector = temp;
	vector[index] = p;
	sizeV++;
	return;
}

template<class T>
T Vector<T>::remove(int index){
	if(sizeV==0){
		return -1;
	}
	if(this->read(index) == NULL){
		if(index >= sizeV) return -1;
	}
	T toDelete=vector[index];
	T * temp = new T[sizeV-1];
	for (int i = 0; i < index; i++){
		temp[i] = vector[i];
	}
	for (unsigned int j = index + 1; j < sizeV; j++){
		temp[j-1] = vector[j];
	}
	delete[] vector;
	vector = temp;
	sizeV--;
  return toDelete;
}

template<class T>
T Vector<T>::read(int index){
	if(vector == NULL){
		return NULL;
	}
	if(index >= sizeV) return NULL;
	return vector[index];
}

#endif
