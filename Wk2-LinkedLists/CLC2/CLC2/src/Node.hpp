//
//  Node.hpp
//  CLC2
//
//  Created by Daniel Cender on 5/4/19.
//  Copyright © 2019 Daniel Cender. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>

template <typename T>
class Node {
public:
    T data;
    Node *next, *prev;
    Node();
    Node(T d, Node<T> *n = 0);
};

#endif /* Node_hpp */
