#include <iostream>
#include "src/BSTNode.h"
#include "src/BSTTree.h"
using namespace std;


// Pass in root node
int countNodes(BSTNode *node) {
  int count = 1;
  // Check for 0 size tree
  if(!node) {
    return count;
  }

  if(node->left != NULL) {
    count += countNodes(node->left);
  }
  if(node->right != NULL) {
    count += countNodes(node->right);
  }
  return count;
};

// This begins recursive cycle for counting
int countTotalNodes(BSTNode *root) {
  int count = 0;
  if(root != NULL) {
    count += countNodes(root);
  }
  return count;
}

int main() {
  BSTNode *root = new BSTNode(34);

  root->insert(1);
  root->insert(67);
  root->insert(3);
  root->insert(5);

  int totalNodes = countTotalNodes(root);

  cout << "Total Nodes: " << totalNodes << endl;
  return 0;
}