//
// Created by Daniel Cender on 2019-04-30.
//
#include "Node.h"

#ifndef PALINDROMEFUNCTIONS_SLLIST_H
#define PALINDROMEFUNCTIONS_SLLIST_H

template <typename T>
class SLList {
public:
    SLList();
    ~SLList();
    bool isEmpty();
    bool isInList(T d);
    void insertAfterNode(Node<T>* prev, T data);
    void insert(int index, T data);
    void push(T data); // basic array-style adder
    void addToHead(T d);
    void addToTail(T d);
    void print();
private:
    Node<T> *head, *tail;
};


#endif //PALINDROMEFUNCTIONS_SLLIST_H
