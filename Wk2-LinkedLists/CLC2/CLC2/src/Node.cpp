//
//  Node.cpp
//  CLC2
//
//  Created by Daniel Cender on 5/4/19.
//  Copyright © 2019 Daniel Cender. All rights reserved.
//

#include "Node.hpp"

Node<typename <#qualifier#>::<#name#>::Node() {
        next = 0;
    }

Node::Node(Type d, Node<Type> *n = 0) {
    this->data = d;
    this->next = n;
}
