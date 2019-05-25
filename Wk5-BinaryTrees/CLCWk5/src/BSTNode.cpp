//
// Created by Daniel Cender on 2019-05-24.
//
#include <iostream>
#include "BSTNode.h"
using namespace std;

BSTNode::BSTNode() {
  data = -1;
  left = right = parent = NULL;
}

BSTNode::BSTNode(int d) {
  data = d;
  right = left = parent = NULL;
}

BSTNode* BSTNode::insert(int key) {
  if(this == NULL) return new BSTNode(key);

  if(key < this->data) {
    BSTNode *leftNode = this->left->insert(key);
    this->left = leftNode;
    leftNode->parent = this;
  } else if(key > this->data) {
    BSTNode *rightNode = this->right->insert(key);
    this->right = rightNode;
    rightNode->parent = this;
  }
  return this;
}
