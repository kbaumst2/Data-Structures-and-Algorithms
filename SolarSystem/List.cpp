#include <iostream>
#include <stdlib.h>
#include "Planet.h"
#include "List.h"
#include "Star.h"

List::List(){
	this->head = NULL;
	this->tail = NULL;
	this->current = NULL;
}


//Node now hold planet*, delete the pointer in Node then delete Node
List::~List(){
	this->reset();
	while(this->current != NULL){
		Node * temp = this->current->next;
		delete this->current->data;
		delete this->current;
		this->current = temp;
	}
	delete this->current;
	head = tail = current = NULL;
}

void List::reset(){
	this->current=this->head;
}

void List::next(){
	if(this->current!=NULL){
		this->current=this->current->next;
	}
}

int List::getIndex(long id){
	this->reset();
	int index=0;
	bool found=false;
	while(this->current!=NULL){
		if(this->current->data->getID()==id){
			return index;
			found=true;
		}
		index++;
		this->current=this->current->next;
	}
	if(found==false) return -1;
}

//New node creation removed, Made to accept Node *
void List::addAtHead(Node * p){
	this->reset();
	Node * temp = this->head;
	this->head = p;
	this->head->next = temp;
	temp->prev = this->head;
}

void List::addAtTail(Node * p){
	Node * temp = this->tail;
	this->tail = p;
	this->tail->prev = temp;
	temp->next = this->tail;
}

void List::insert(int index, Planet * p){
	Node * toAdd = new Node(p);
	int position = 0;
	this->reset();

	//Empty list
	if(this->head == NULL){
		this->head = toAdd;
		this->tail = toAdd;
	}

	else if(position==index && index==0){
		//Pass node instead of planet
		this->addAtHead(toAdd);
	}

	else{
		while(this->current!=NULL && position<=index){
			if(this->current->next==NULL){
				//Pass node instead of planet
				this->addAtTail(toAdd);
				break;
			}
			else if(position==index){
				Node * temp=this->current;
				Node * temp2=this->current->prev;
				this->current=toAdd;
				this->current->next=temp;
				this->current->prev=temp2;
				temp->prev=this->current;
				temp2->next=this->current;
				break;
			}
			position++;
			this->current=this->current->next;
		}
	}
}


Planet* List::read(int index){
	this->reset();
	int position=0;
	while(this->current!=NULL && position<=index){
		if(position==index){
			return this->current->data;
			break;
		}
		else if(this->current->next==NULL){
			return NULL;
			break;
		}
		this->current=this->current->next;
		position++;
	}
	return NULL;
}

bool List::remove(int index){
	this->reset();
	int position=0;
	while(this->current!=NULL && position<=index){
		Node * curr=this->current;
		if(position==index){
				if(this->current==this->head){
					this->head=this->current->next;
					this->head->prev=NULL;
					delete this->current->data;
					delete this->current;
				}
				else if(this->current==this->tail){
					this->tail=this->current->prev;
					this->tail->next=NULL;
					delete this->current->data;
					delete this->current;
				}
				else{
				this->current->prev->next=this->current->next;
				this->current->next->prev=this->current->prev;
				delete this->current->data;
				delete this->current;
				this->current=NULL;
			}
			return true;
			}
			position++;
			this->current=curr->next;
		}

		return false;
	}


unsigned List::size(){
	int size=0;
	this->reset();
	while(this->current!=NULL){
		size++;
		this->current=this->current->next;
		}
	return size;
}
