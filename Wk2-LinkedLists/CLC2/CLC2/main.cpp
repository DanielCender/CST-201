#include <iostream>
#include "src/Node.hpp"
using namespace std;

//template <typename T>
//class Node {
//public:
//    T data;
//    Node *next, *prev;
//    Node() {
//        next = 0;
//    }
//    Node(T d, Node<T> *n = 0) {
//        this->data = d;
//        this->next = n;
//    }
//};

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
        }
        return -1;
    }
};


int main() {
    
    SLinkedList<int> *list = new SLinkedList<int>();
    
    list->push(1);
    list->push(2);
    list->push(3);
    list->push(4);
    
    int firstNodeData = list->getNth(0);
    
    cout << "first: " << firstNodeData << endl;
    
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
