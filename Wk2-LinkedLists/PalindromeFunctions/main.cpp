#include <iostream>
using namespace std;
/**
 *  Name: Palindrome Functions
 *  Author: Daniel Cender
 *  Date: 04/30/2019
 *  Description:
 */

// Basic Node class for use in a linked list
class Node {
public:
    char data;
    Node* next;
    Node() {
        next = 0; // Null pointer
    }

    Node(char d, Node* n = 0) {
        data = d;
        next = n;
    }
    int length() {
        Node* n = this;
        int size;
        size = 0;
        while(n != NULL) {
            size++;
            n = n->next;
        }
        return (size);
    }
    static void print(Node* n) {
        while(n != NULL) { // While node isn't a null pointer
            cout << n->data << endl;
            n = n->next; // Iterate to next link
        }
    }

};

class SLinkedList {

};


int main() {

    Node *first = new Node(); // Create pointer to Node

    first->data = 'A';

    Node *second = new Node('R');

    first->next = second; // Assign next to address of second node

    second->next = new Node('A'); // Second node's next points to 'A' address


    Node::print(first); // Should print out list

    cout << "First item's next's data: " << first->next->data << endl;
    cout << "Last Item: " << first->next->next->data << endl;


    int length;
    length = first->length();

    cout << "Printed linked lists size: " << length << endl;

    return 0;
}