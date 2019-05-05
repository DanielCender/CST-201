//
//  Node.cpp
//  CLC2
//
//  Created by Daniel Cender on 5/4/19.
//  Copyright © 2019 Daniel Cender. All rights reserved.
//

#include "Node.hpp"

template <typename T>
Node<T>::Node() {
        next = 0;
    }

template <typename T>
Node<T>::Node(T d, Node<T> *n) {
    this->data = d;
    this->next = n;
}
