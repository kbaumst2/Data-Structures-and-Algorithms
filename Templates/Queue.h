#ifndef QUEUE_H
#define QUEUE_H

#include "Vector.h"

template<class T>
class Queue{
	Vector<T> * queue;
	int maxSize;
public:
	int top;
	int bottom;
	Queue(unsigned int size);
	bool enqueue(T data);
	T dequeue();
	T peek();
	bool empty();
	void clear();
	~Queue();

};

template<class T>
Queue<T>::Queue(unsigned int size){
	this->maxSize=size;
	this->queue=new Vector<T>(size);
	this->top=0;
	this->bottom=-1;
}

template<class T>
bool Queue<T>::enqueue(T data){
	if(top==bottom){
		top++;
		return false;

	}
	queue->insert(top, data);
	top++;
	if(top==maxSize){
		 top=0;
	 }
	if(bottom==-1) bottom=top-1;
	return true;
}

template<class T>
T Queue<T>::dequeue(){
	T retVal=queue->remove(bottom);
	top--;
	if(top==bottom){
		top=maxSize-1;
	}
	if(bottom==maxSize) bottom=0;
	return retVal;
}


template<class T>
T Queue<T>::peek(){
	T retVal=queue->read(bottom);
	return retVal;
}


template<class T>
bool Queue<T>::empty(){
	if(bottom==-1) return true;
	return false;
}

template<class T>
void Queue<T>::clear(){
	queue->clear();
	top=0;
	bottom=-1;
}

template<class T>
Queue<T>::~Queue(){
		delete queue;
	}





#endif
