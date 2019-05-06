/*
 *  Palindrome Functions/ Name: DNode.h
 *  Author: Daniel Cender
 *  Date: 05/04/2019
 *  Description: This is an implementation of a List Node with a *prev pointer.
 */

#include <iostream>
using namespace std;


#ifndef DQ2_SRC_DNODE_H_
#define DQ2_SRC_DNODE_H_

template <typename T>
class DNode {
 public:
  T data;
  DNode *next, *prev;
  DNode() {
    next = 0;
    prev = 0;
  }
  DNode(T d, DNode<T> *n = 0, DNode<T> *p = 0) {
    this->data = d;
    this->next = n;
    this->prev = p;
  }
  int length()  {
    DNode* n = this;
    int size;
    size = 0;
    while(n != NULL) {
      size++;
      n = n->next;
    }
    return (size);
  };
  static void print(DNode* n) {
    while(n != NULL) { // While node isn't a null pointer
      cout << n->data << " ";
      n = n->next; // Iterate to next link
    }
    cout << endl;
  };
};

#endif //DQ2_SRC_DNODE_H_
