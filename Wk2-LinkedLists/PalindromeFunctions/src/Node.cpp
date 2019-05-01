//
// Created by Daniel Cender on 2019-04-30.
//
#include <iostream>
#include "Node.h"
using namespace std;

    // Tilde operator is a deconstructor signifier, note to self
    template <typename T>
    Node<T>::Node() {
        next = 0; // Null pointer
    }

    template <typename T>
    Node<T>::Node(T d, Node* n) {
        data = d;
        next = n;
}

    template <typename T>
    int Node<T>::length() {
        Node* n = this;
        int size;
        size = 0;
        while(n != NULL) {
            size++;
            n = n->next;
        }
        return (size);
}

    template <typename T>
    void Node<T>::print(Node* n) {
        while(n != NULL) { // While node isn't a null pointer
            cout << n->data << endl;
            n = n->next; // Iterate to next link
        }
}





