#include <iostream>
using namespace std;

struct Node {
 public:
  Node *left, *right;
  int key;

  Node(int data = 0) {
    key = data;
  }
};


bool isBST(const Node *root) {

  // empty tree is balanced search tree
  if(root == NULL) {
    return true;
  }

  // Right node should be greater than parent
  if(root->right && root->right->key < root->key) {
    return false;
  }
  // Left node should be less than parent
  if(root->left && root->left->key > root->key) {
    return false;
  }

  return isBST(root->right) && isBST(root->left);
}




int main() {
  // ***** Real BST *****
  Node *root = new Node(40);
  Node *current = root;
  // Left branches
  current->left = new Node(30);
  current->right = new Node(35);
  current = current->left;
  current->right = new Node(32);
  current->left = new Node(24);

  // Right branches
  current = root;
  current->right = new Node(50);
  current = current->right;
  current->left = new Node(42);
  current->right = new Node(56);




      // ***** Not real BST *****

  Node *root2 = new Node(40);
  current = root2;
  // Left branches
  current->left = new Node(30);
  current->right = new Node(60);
  current = current->left;
  current->right = new Node(32);
  current->left = new Node(24);

  // Right branches
  current = root2;
  current->right = new Node(29);
  current = current->right;
  current->left = new Node(4);
  current->right = new Node(194);

  cout << "Is the 1st tree a BST? (yes): " << isBST(root) << endl;
  cout << "Is the 2nd tree a BST? (no): " << isBST(root2) << endl;

  return 0;
}