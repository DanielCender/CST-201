/**
 *  Name: CLC2
 *  Author: Daniel Cender
 *  Date: 5/02/2019
 *  Description: This program implements singly, doubly, and circular doubly linked lists and performs an operation
 *  on them to insert a node after the nth list item.
 */
#include <iostream>
using namespace std;


/* *********** Singly Linked List ********** */

template <typename T>
class Node {
 public:
  T data;
  Node *next;
  Node() {
    next = 0;
  }
  Node(T d, Node<T> *n = 0) {
    this->data = d;
    this->next = n;
  }
};

template <typename T>
class SLinkedList {
 private:
  Node<T> *head, *tail;
 public:
  SLinkedList() {
    head = 0;
    tail = 0;
  }
  // Pushes a node onto the HEAD of a list
  void push(T d) {
    Node<T> *new_node = new Node<T>(d);
    new_node->next = head;
    head = new_node;
  }
  T getNth(int index) {
    Node<T> *current = head;
    int counter = 0;
    while(current->next != 0) {
      if(counter == index) {
//        delete &counter; // stop leaks
        return (current->data);
      }
        counter++;
        current = current->next;
    }
  }
  void insert(Node<T>* node, int index) {
    int counter = 0;
    Node<T> *current = head;
    while(counter != index) {
      current = current->next; // Get to index of list
    }
    node->next = current->next; // get node that is to be linked after
    current->next = node;

//    delete &counter;
//    delete current; // no leaks
  }
};

/* ********** Doubly Linked List ********* */

template <typename T>
class DNode {
 public:
  T data;
  DNode *next, *prev;
  DNode() {
    next = 0;
    prev = 0;
  }
  DNode(T d, DNode<T> *n = 0, DNode<T> *p = 0) {
    this->data = d;
    this->next = n;
    this->prev = p;
  }

};

template <typename T>
class DLinkedList {
 private:
  DNode<T> *head, *tail;
 public:
  DLinkedList() {
    head = tail = 0;
  }
  // Pushes a node onto the HEAD of a list
  void push(T d) {
    DNode<T> *new_node = new DNode<T>(d);
    new_node->next = head;
    new_node->prev = 0;
    head = new_node;
  }
  T getNth(int index) {
    DNode<T> *current = head;
    int counter = 0;
    while(current->next != 0) {
      if(counter == index) {
//        delete &counter; // stop leaks
        return (current->data);
      }
      counter++;
      current = current->next;
    }
  }
  void insert(DNode<T>* node, int index) {
    int counter = 0;
    DNode<T> *current = head;
    while(counter != index) {
      current = current->next; // Get to index of list
    }
    node->next = current->next; // get node that is to be linked after
    node->prev = current;
    current->next->prev = node; // Change prev of next node to new node
    current->next = node; // Insert node after current
    delete current; // no leaks
  }
};



/* ******** Circular Doubly Linked List ********* */

template <typename T>
class CircularLL {
 private:
  DNode<T> *head, *tail;
 public:
  CircularLL() {
    head = tail = 0;
  }
  // Pushes a node onto the HEAD of a list
  void push(T d) {
    DNode<T> *new_node = new DNode<T>(d);
    if(head == 0) { // List is empty
      head = new_node;
      tail = new_node;
      head->next = head->prev = tail;
      tail->next = tail->prev = head;
    } else {
      new_node->next = head;
      new_node->next->prev = new_node;
      new_node->prev = tail;
      head = new_node;
    }

  }
  T getNth(int index) {
    DNode<T> *current = head;
    int counter = 0;
    while(current->next != 0) {
      if(counter == index) {
//        delete &counter; // stop leaks
        return (current->data);
      }
      counter++;
      current = current->next;
    }
  }
  void insert(DNode<T>* node, int index) {
    int counter = 0;
    DNode<T> *current = head;
    while(counter != index) {
      current = current->next; // Get to index of list
    }
    node->next = current->next; // get node that is to be linked after
    current->prev = node;
    current->next = node;

//    delete &counter;
    delete current; // no leaks
  }
};

int main() {

    SLinkedList<int> *list = new SLinkedList<int>();
    DLinkedList<int> *d_linked_list = new DLinkedList<int>();
    CircularLL<int> *c_linked_list = new CircularLL<int>();

    list->push(1);
    list->push(2);
    list->push(3);
    list->push(4);
    d_linked_list->push(1);
    d_linked_list->push(2);
  d_linked_list->push(3);
  d_linked_list->push(4);
  c_linked_list->push(1);
  c_linked_list->push(2);
  c_linked_list->push(3);
  c_linked_list->push(4);

    int firstNodeSLL = list->getNth(0);
    int firstNodeDLL = d_linked_list->getNth(0);
    int firstNodeCLL = c_linked_list->getNth(0);

    cout << "Singly linked list, first: " << firstNodeSLL << endl;
    cout << "Doubly linked list, first: " << firstNodeDLL << endl;
    cout << "Doubly linked Circular list, first: " << firstNodeCLL << endl;

    Node<int> *toInsertIntoSLL = new Node<int>(42);
    DNode<int> *toInsertIntoDLL = new DNode<int>(42);
    list->insert(toInsertIntoSLL, 0); // i(1) should not contain data: 42
    d_linked_list->insert(toInsertIntoDLL, 0);
    c_linked_list->insert(toInsertIntoDLL, 0);


    cout << "Singly Linked: What is the meaning of life??? -> " << list->getNth(1) << "." << endl;
    cout << "Doubly Linked: What is the meaning of life??? -> " << d_linked_list->getNth(1) << "." << endl;
    cout << "Doubly Linked Circular: What is the meaning of life??? -> " << c_linked_list->getNth(1) << "." << endl;
    return 0;
}