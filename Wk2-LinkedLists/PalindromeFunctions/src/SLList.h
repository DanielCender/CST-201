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
    void insertBefore(Node<T>* prev, T data);
    void insertAfter(Node<T>* prev, T data);
    void addToHead(T d);
    void addToTail(T d);
private:
    SLList *head, *tail;
};


#endif //PALINDROMEFUNCTIONS_SLLIST_H
