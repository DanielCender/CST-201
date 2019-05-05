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
void SLList<T>::insertAfterNode(Node<T> *prev, T data) {
    // Node shouldn't be null
    if(prev == NULL) {
        cout << "Node specified is null" << endl;
        return;
    }
    Node<T> new_node(data);

    // The list should not be empty
    if(this->isEmpty()) {
        cout << "List is empty" << endl;
        return;
    }

    // connect new node to *prev's 'next'
    new_node = prev->next;
    // Make prev's next go to new node
    prev->next = new_node;
    return;
}

template <typename T>
void SLList<T>::insert(int index, T data) {
    if(this->isEmpty()) {
        cout << "List is empty. Insertion not possible" << endl;
        return;
    }
    for(int i = 0; (head->next) != NULL && (i < index); head = head->next, i++) {
        cout << "This iteration, " << i << ": " << head->data << endl;
    }
}

template <typename T>
void SLList<T>::push(T d) {
    if(this->isEmpty()) {
        cout << "List is empty. Push not possible" << endl;
        return;
    }
    Node<T> tmp = new Node<T>(d);
    tmp->next = NULL;
    for(; head->next != NULL; head = head->next);
    head->next = tmp;
}

template <typename T>
void SLList<T>::print() {
    if(this->isEmpty()) {
        cout << "List is empty. Nothing to print here." << endl;
        return;
    }
    for(; head->next != NULL; head = head->next) {
        cout << head->data << " ";
    }
    cout << endl;
    return;
}