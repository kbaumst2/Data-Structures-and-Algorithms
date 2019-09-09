#ifndef HEAP_H
#define HEAP_H
#include <string>
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <vector>
#include "Planet.h"
#include "Parser.h"

template<class T>
class Heap{
private:
  std::vector<T> heap;
public:
  Heap();
  Heap(std::vector<T>);
  void addElement(T element);
  T getPriority();
  bool empty();
  unsigned long size();
  std::vector<T> getArray();
  void heapify(std::vector<T> &list);
  void siftdown(int i, std::vector<T> &list);
  bool isLeaf(int i, std::vector<T> &list);
  void swap(T & s1, T & s2);
  unsigned int left(unsigned int parent, std::vector<T> &list);
  unsigned int right(unsigned int parent, std::vector<T> &list);
  unsigned int parent(unsigned int child);
};


template <class T>
Heap<T>::Heap(){
  //??
}

template <class T>
Heap<T>::Heap(std::vector<T> list){
  heapify(list);
  heap=list;
}

template<class T>
void Heap<T>::heapify(std::vector<T> &list){
  for(int i=(list.size()-2)/2; i>=0; i--){
    siftdown(i, list);
  }
}

template<class T>
void Heap<T>::siftdown(int i, std::vector<T> &list){
  while(!isLeaf(i, list)){
    int n=left(i, list);
    if(n+1<list.size() && list[n]<list[n+1]){
      n=right(i, list);
    }
    if(list[i]>list[n]) return;
    else{
      swap(list[i],list[n]);
    }
    i=n;
  }
}

template<class T>
bool Heap<T>::isLeaf(int i, std::vector<T> &list){
  if(left(i, list)>list.size()) return true;
  return false;
}

template<class T>
void Heap<T>::swap(T & s1, T & s2 ){
  T temp=s1;
  s1=s2;
  s2=temp;
}

template<class T>
unsigned int Heap<T>::left(unsigned int parent, std::vector<T> &list){
  return (2*parent+1<list.size()? 2*parent+1:-1);
}

template<class T>
unsigned int Heap<T>::right(unsigned int parent, std::vector<T> &list){
  return (2*parent+2<list.size()? 2*parent+2:-1);
}

template<class T>
unsigned int Heap<T>::parent(unsigned int child){
  return (child>0? (child-1)/2:-1);
}

template <class T>
void Heap<T>::addElement(T element){
  heap.push_back(element);
  heapify(heap);
}

template<class T>
T Heap<T>::getPriority(){
  if(heap.size()>0){
    T copy=heap[heap.size()-1];
    T priority=heap[0];
    heap[0]=copy;
    heap.pop_back();
    siftdown(0, heap);
    return priority;
  }
}

template <class T>
bool Heap<T>::empty(){
  if(heap.size()==0) return true;
  return false;
}

template <class T>
unsigned long Heap<T>::size(){
  return heap.size();
}

template <class T>
std::vector<T> Heap<T>::getArray(){
  return heap;
}

#endif
