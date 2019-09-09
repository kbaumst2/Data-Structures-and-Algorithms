#ifndef BST_H
#define BST_H

#include <stdlib.h>
#include <iostream>
#include <cstdio>
#include <type_traits>
#include <vector>
#include <memory>

template<class T>
class BSTree{
    private:
      class Node{
        public:
          Node *left, *right, *parent;
          T data;
          Node(T data, Node * p);
        };
    Node * root;
    bool insertNode(Node * n, T data);
    bool findNode(Node * n, T data);
	  Node * searchNode(Node * n, T data);
    void inOrder(Node * n, std::vector<T> &list);
    void preOrder(Node * n, const BSTree &old_tree);
    void postOrder(Node * n);
    bool removeLeaf(Node * n);
    bool shortCircuit(Node * n);
    bool promotion(Node * n);
    Node * findRightMin(Node * n);
    int findHeight(Node* node);
    void balanceHelper(std::vector<T> arr, int begin, int final);
    void deleteAll(Node * n);
public:
  BSTree();
  BSTree(const BSTree &old_tree);
  ~BSTree();
  bool empty();
  bool insert(T val);
  bool find(T val);
  Node * search(T val);
  //Node dummy();
  void sortedArray(std::vector<T> &list);
  bool remove(T num);
  void balance();
  int height();

};


template<class T>
BSTree<T>::Node::Node(T data, Node * p){
  this->left=nullptr;
  this->right=nullptr;
  this->data=data;
  this->parent=p;
}

template<class T>
BSTree<T>::BSTree(){
  this->root=nullptr;
}

template<class T>
bool BSTree<T>::empty(){
  if(root==nullptr){
    return true;
    }
 return false;
}

template<class T>
bool BSTree<T>::insert(T val){
  if (root==nullptr) {
    root=new Node(val, nullptr);
    return true;
  }
  else{
    return insertNode(root, val);
  }

}

template<class T>
bool BSTree<T>::insertNode(Node * n, T data){
  if(data==n->data) return false;
  if(data < n->data){
    if(n->left==nullptr){
      n->left=new Node(data, n);
    }else{
      return insertNode(n->left, data);
    }
  }
  else if (data>n->data) {
    if(n->right==nullptr){
      n->right=new Node(data, n);
    }else{
      return insertNode(n->right, data);
    }
  }
}

template<class T>
bool BSTree<T>::find(T val){
  if (root==nullptr) {
    return false;
  }
  else{
    return findNode( root, val);
  }
}

template<class T>
bool BSTree<T>::findNode(Node * n, T data){
  if(data==n->data) return true;
  if(data < n->data){
    if(n->left==nullptr){
      return false;
    }else{
      return findNode(n->left, data);
    }
  }
  if (data>n->data) {
    if(n->right==nullptr){
      return false;
    }else{
      return findNode(n->right, data);
    }
  }
  return false;
}


template<class T>
typename BSTree<T>::Node * BSTree<T>::search(T val){
  if (root==nullptr) {
    return nullptr;
  }
  else{
    return searchNode( root, val);
  }
}


template<class T>
typename BSTree<T>::Node * BSTree<T>::searchNode(Node * n, T data){
  if(data==n->data) return n;
  if(data < n->data){
    if(n->left==nullptr){
      //return false;
    }else{
      return searchNode(n->left, data);
    }
  }
  if (data>n->data) {
    if(n->right==nullptr){
      //return false;
    }else{
      return searchNode(n->right, data);
    }
  }
}



template<class T>
void BSTree<T>::inOrder(Node * n, std::vector<T> &list){
  if(n!=nullptr){
    inOrder(n->left, list);
    list.push_back(n->data);
    inOrder(n->right, list);
  }
}

template <class T>
void BSTree<T>::sortedArray(std::vector<T> &list){
  inOrder(root, list);
}

template <class T>
bool BSTree<T>::remove(T data){
	if(find(data)==false) return false;
//  bool retVal=false;
  typename BSTree<T>::Node * r=search(data);
  if(r!=nullptr){
    if(r->left==nullptr && r->right==nullptr){
      return removeLeaf(r);
    }else if (r->left==nullptr || r->right==nullptr){
      return shortCircuit(r);
    }else{
      return promotion(r);
    }

  }
}

template <class T>
bool BSTree<T>::removeLeaf(Node * r){
  if(r==nullptr) return false;
  if(r==root){
    delete r;
    root=nullptr;
    return true;
  }
  if(r==r->parent->right){
    r->parent->right=nullptr;
  }
  else{
    r->parent->left=nullptr;
  }
  delete r;
  return true;

}

template <class T>
bool BSTree<T>::shortCircuit(Node * r){
  if(r==root){
    if(r->left==nullptr){
      root=r->right;
      delete r;
      root->parent=nullptr;
    }
    else{
      root=r->left;
      delete r;
      root->parent=nullptr;
    }
    return true;
    //if left null right becomes root
  }
  if(r==r->parent->left){
    if(r->right==nullptr){
      r->parent->left=r->left;
      r->left->parent=r->parent;
    }
    else{
      r->parent->left=r->right;
      r->right->parent=r->parent;
    }
  }else{

    if(r->right==nullptr){
      r->parent->left=r->left;
      r->left->parent=r->parent;
    }
    else{
      r->parent->right=r->right;
      r->right->parent=r->parent;
    }
  }
  delete r;
  r=nullptr;
  return true;
}


template <class T>
bool BSTree<T>::promotion(Node *r){
  typename BSTree<T>::Node * min=findRightMin(r->right);
  r->data=min->data;
  if(min->left==nullptr && min->right==nullptr){
    return removeLeaf(min);
  }else{
    return shortCircuit(min);
  }
  delete min;
}

template <class T>
typename BSTree<T>::Node * BSTree<T>::findRightMin(Node * n){
  if(n->left==nullptr) return n;
  return findRightMin(n->left);
}


template<class T>
BSTree<T>::BSTree(const BSTree &old_tree){
  root=nullptr;
  preOrder(old_tree.root, old_tree);
}

template<class T>
void BSTree<T>:: preOrder(Node * n, const BSTree &old_tree){
    if(n!=nullptr){
      insert(n->data);
      preOrder(n->left, old_tree);
      preOrder(n->right, old_tree);
    }
}


template<class T>
BSTree<T>::~BSTree(){
  postOrder(root);
}

template<class T>
void BSTree<T>::postOrder(Node * n){
  if(n!=nullptr){
    postOrder(n->left);
    postOrder(n->right);
    removeLeaf(n);
    }
}

template<class T>
int BSTree<T>::height(){
  return findHeight(this->root);
}

template<class T>
int BSTree<T>::findHeight(Node* node){
 // base case tree is empty
   if(node == NULL)
       return -1;
   // If tree is not empty then height = 1 + max of left height and right heights
    int lh = findHeight(node->left);
    int rh = findHeight(node->right);
    int max = (lh >= rh) ? lh : rh;
    return 1 + max;
}


template<class T>
void BSTree<T>::balance(){
  if(empty())return;
  std::vector<T> arr;
  sortedArray(arr);
  deleteAll(root);
  int start=0;
  int end=arr.size()-1;
  balanceHelper(arr, start, end);
}



template<class T>
void BSTree<T>::balanceHelper(std::vector<T> arr, int begin, int final){
  if(begin==final) return;
  if(final-begin==1){
    insert(begin);
    insert(final);
    return;
  }
  int start=begin;
  int end=final;
  int middle=(start+end)/2;
  insert(arr[middle]);
  balanceHelper(arr, start, middle-1);
  balanceHelper(arr, middle+1, end);


}

template<class T>
void BSTree<T>::deleteAll(Node * n){
  if(n!=nullptr){
    deleteAll(n->left);
    deleteAll(n->right);
    removeLeaf(n);
    }
}



 #endif
