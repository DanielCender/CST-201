//
// Created by Daniel Cender on 2019-04-30.
//

#ifndef PALINDROMEFUNCTIONS_NODE_H
#define PALINDROMEFUNCTIONS_NODE_H

// Basic Node class for use in a linked list
template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node();
    Node(T d, Node* n = 0);
    int length();
    static void print(Node* n);
};

#endif //PALINDROMEFUNCTIONS_NODE_H
