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

template <typename Type>
class Node {
public:
    Type data;
    Node *next, *prev;
    Node();
    Node(Type d, Node<Type> *n = 0);
};

#endif /* Node_hpp */
