#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node<T> *next;
    Node() {
        next = 0;
    }
    Node(T d, Node<T> *n = 0) {
        data = d;
        next = n;
    }
};

template <typename T>
class LinkedList {
public:
    LinkedList() {
        Node<T> head;
    };

    // Not sure exactly how to implement without pointers in C++
    // Is it a sort of trick problem? C++ will use references I believe in this below function
    T getNth(int index) {
        int count = 0;
        Node<T> *curr = head;
        while(curr != NULL){
            if(count == index) {
                return curr->data;
            }
            count++;
            curr = curr->next;
        }
    }
    void push(T new_data) {
         Node<T> *new_node = new Node<T>(new_data);

        new_node->next = head;

        head = new_node;
    }
private:
    Node<T> *head; // No need for tail in this example
};

int main() {
    LinkedList<int> *list = new LinkedList<int>();

    list->push(1);
    list->push(2);
    list->push(3);
    list->push(4);

    std::cout << list->getNth(0) << std::endl;
    std::cout << list->getNth(1) << std::endl;
    std::cout << list->getNth(2) << std::endl;
    std::cout << list->getNth(3) << std::endl;

    return 0;
}