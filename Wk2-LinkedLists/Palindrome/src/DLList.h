/*
 *  Palindrome Functions/ Name: DLList.h
 *  Author: Daniel Cender
 *  Date: 05/04/2019
 *  Description: This is an implementation of a Doubly Linked List
 */

#include "DNode.h"

#ifndef DQ2_SRC_DLLIST_H_
#define DQ2_SRC_DLLIST_H_

template <typename T>
class DLList {
 public:
  DNode<T> *head, *tail;
  DLList() {
    head = tail = 0;
  }
  ~DLList()  {
    for(DNode<T>* p = head; !isEmpty();) {
      p = head->next; // Moves pointer forward in list
      delete head;
      head = p; // Sets new head, so next ->next moves to next pointer
    }
  };
  bool isEmpty()  {
    return head == 0;
  };
  // Pushes a node onto the HEAD of a list
  void push(T d) {
    DNode<T> *new_node = new DNode<T>(d);
    new_node->next = head;
    new_node->prev = 0;
    if(head != NULL) {
      head->prev = new_node;
    }
    head = new_node;
  }
  T getNth(int index) {
    DNode<T> *current = head;
    int counter = 0;
    while(current->next != 0) {
      if(counter == index) {
//        delete &counter; // stop leaks
        return (current->data);
      }
      counter++;
      current = current->next;
    }
  }
  void insert(DNode<T>* node, int index) {
    int counter = 0;
    DNode<T> *current = head;
    while(counter != index) {
      current = current->next; // Get to index of list
    }
    node->next = current->next; // get node that is to be linked after
    node->prev = current;
    current->next->prev = node; // Change prev of next node to new node
    current->next = node; // Insert node after current
    delete current; // no leaks
  }
};

#endif //DQ2_SRC_DLLIST_H_
