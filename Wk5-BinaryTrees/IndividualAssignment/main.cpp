#include <iostream>
using namespace std;

template <typename T>
class Node {
 public:
  Node<T> *left, *right;
  T key;

  Node<T>(T data = NULL) {
    key = data;
    left = NULL;
    right = NULL;
  }
};

// Inorder display
template <typename T>
  void displayBST(const Node<T>* current) {
    if(current == NULL) {
      return;
    }

    // recur left branches
     displayBST(current->left);

    cout << current->key << " ";

    // traverse right branches then
    displayBST(current->right);
  }


// Function to determine if binary tree is a BST or not, inspiration from: https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
template <typename T>
bool isBST(const Node<T> *root) {

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


template <typename T>
Node<T>* mirrorNode(Node<T> *current) {
  if(current == NULL) {
    return NULL;
  } else {
    Node<T> *node = new Node<T>();
    node->key = current->key;
    node->left = mirrorNode(current->right);
    node->right = mirrorNode(current->left);

    return node;
  }
}


template <typename T> // 0 is left, right is 1
Node<T>* balanceBST(T *arr, Node<T> *root = NULL, bool childDir = 0) {


  int arrSize = strlen(arr);
  int sizeHalf = arrSize / 2;
    int mid = sizeHalf;

    T firstHalfSubArr[mid];
    T sndHalfSubArr[mid];

    // Make nodes of mid and left/right of mid array elements
    Node<T> *midNode = arr[mid] ? new Node<T>(arr[mid]) : NULL;
    midNode->left = arr[mid - 1] ? new Node<T>(arr[mid - 1]) : NULL;
    midNode->right = arr[mid + 1] ? new Node<T>(arr[mid + 1]) : NULL;

  Node<T> *rootNode = root == NULL ? midNode : root;
  if(arrSize == 0) {
    return rootNode;
  }

  // Create half sub array - excluding middle three nodes
  for(int i = 0; i < mid - 1; i++) {
    firstHalfSubArr[i] = arr[i];
    sndHalfSubArr[i] = arr[mid + i + 1];
  }

  rootNode->left = balanceBST(firstHalfSubArr, rootNode, 0);
  rootNode->right = balanceBST(sndHalfSubArr, rootNode, 1);
  }



int main() {

    char alphabet[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
  // ***** Real BST *****
  Node<int> *root = new Node<int>(40);
  Node<int> *current = root;
  // Left branches
  current->left = new Node<int>(30);
  current->right = new Node<int>(35);
  current = current->left;
  current->right = new Node<int>(32);
  current->left = new Node<int>(24);

  // Right branches
  current = root;
  current->right = new Node<int>(50);
  current = current->right;
  current->left = new Node<int>(42);
  current->right = new Node<int>(56);




      // ***** Not real BST *****

  Node<int> *root2 = new Node<int>(40);
  current = root2;
  // Left branches
  current->left = new Node<int>(30);
  current->right = new Node<int>(60);
  current = current->left;
  current->right = new Node<int>(32);
  current->left = new Node<int>(24);

  // Right branches
  current = root2;
  current->right = new Node<int>(29);
  current = current->right;
  current->left = new Node<int>(4);
  current->right = new Node<int>(194);

  cout << "First Tree (BST): ";
  displayBST(root);
  cout << endl;
  cout << "Second Tree (not BST): ";
  displayBST(root2);
  cout << endl;

  // 6.14.4 - Is Binary Search Tree Function
  cout << "Is the 1st tree a BST? (yes): " << isBST(root) << endl;
  cout << "Is the 2nd tree a BST? (no): " << isBST(root2) << endl;

  // 6.14.10 - Mirror a BST
  Node<int> *mirroredFirstBST = mirrorNode(root);
  cout << "Mirrored first BST: ";
  displayBST(mirroredFirstBST);
  cout << endl;

  // 6.14.16 - Apply balance() to the English Alphabet - Almost working, but not yet
  Node<char> *balancedAlphabet;
  balancedAlphabet = balanceBST(alphabet);

  cout << "Balanced Alphabet: ";
  displayBST(balancedAlphabet);
  cout << endl;

  return 0;
}