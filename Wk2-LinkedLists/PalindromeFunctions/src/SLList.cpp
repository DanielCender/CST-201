//
// Created by Daniel Cender on 2019-04-30.
//

#include "SLList.h"
#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
SLList<T>::SLList() {
    head = tail = 0;
}

template <typename T>
SLList<T>::~SLList() {
    for(Node<T>* p = head; !isEmpty();) {
        p = head->next; // Moves pointer forward in list
        delete head;
        head = p; // Sets new head, so next ->next moves to next pointer
    }
}

template <typename T>
bool SLList<T>::isEmpty() {
    return head == 0;
}

template <typename T>
bool SLList<T>::isInList(T d) {
    Node<T>* temp;
    for(temp = head; temp != 0 && (temp->data != d); temp = temp->next);
    return temp != 0;
}

template <typename T>
void SLList<T>::insertBefore(Node<T> *prev, T data) {
    head = new Node<T>(data, head);

}