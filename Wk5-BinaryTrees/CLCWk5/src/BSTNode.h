//
// Created by Daniel Cender on 2019-05-24.
//

#ifndef CLCWK5_SRC_BSTNODE_H_
#define CLCWK5_SRC_BSTNODE_H_

class BSTNode {
 public:
  int data;
  BSTNode *right, *left, *parent;
  BSTNode();
  BSTNode(int d);
  BSTNode* insert(int key);
};

#endif //CLCWK5_SRC_BSTNODE_H_
