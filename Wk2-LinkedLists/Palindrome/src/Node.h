//
// Created by Daniel Cender on 2019-05-02.
//
#include <iostream>
using namespace std;

#ifndef DQ2_NODE_H
#define DQ2_NODE_H


// Basic Node class for use in a linked list
template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node() {
        next = 0; // Null pointer
    };
    Node(T d, Node* n = 0)  {
        data = d;
        next = n;
    };
    int length()  {
        Node* n = this;
        int size;
        size = 0;
        while(n != NULL) {
            size++;
            n = n->next;
        }
        return (size);
    };
    static void print(Node* n) {
        while(n != NULL) { // While node isn't a null pointer
            cout << n->data << " ";
            n = n->next; // Iterate to next link
        }
        cout << endl;
    };
};

#endif //DQ2_NODE_H
