#include "Planet.h"
#include "Vector.h"
#include <cstdlib>
#include <iostream>

//Set sizeV to 0 and array to NULL initially
Vector::Vector(){
	sizeV = 0;
	vector = NULL;
}

//Iterate through array deleting Planets at each index
Vector::~Vector(){
	for(unsigned int i = 0; i < sizeV; i++) delete vector[i];
	delete [] vector;
}

//Take in an index to insert at and a planet* to insert
void Vector::insert(int index, Planet * p){
	if(vector == NULL){
		vector = new Planet*[index+1];
		vector[index] = p;
		sizeV = index+1;
		return;
	}
	if(index >= sizeV){
		Planet ** temp = new Planet*[index+1];
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
	Planet ** temp = new Planet*[sizeV+1];
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


bool Vector::remove(int index){
	if(sizeV == 0){ 
		return false;
	}
	if(this->read(index) == NULL){
		if(index >= sizeV) return false;
	}
	Planet ** temp = new Planet*[sizeV-1];
	for (int i = 0; i < index; i++){
		temp[i] = vector[i];
	}
	for (unsigned int j = index + 1; j < sizeV; j++){
		temp[j-1] = vector[j];
	}
	delete vector[index];
	delete[] vector;
	vector = temp;
	sizeV--;
      	return true;
}

Planet * Vector::read(int index){
	if(vector == NULL){
		return NULL;
	}
	if(index >= sizeV) return NULL;
	return vector[index];
}
