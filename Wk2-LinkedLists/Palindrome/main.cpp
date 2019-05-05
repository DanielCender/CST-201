#include <iostream>
#include "src/Node.h"
#include "src/SLList.h"
using namespace std;
/**
 *  Name: Palindrome Functions
 *  Author: Daniel Cender
 *  Date: 04/30/2019
 *  Description:
 */


int main() {
    SLList<char> *list = new SLList<char>();

    // A palindrome
    list->push('R');
    list->push('A');
    list->push('C');
    list->push('E');
    list->push('C');
    list->push('A');
    list->push('R');

    (*list).print(); // Should print out list on a line

    Node<char> *first = new Node<char>(); // Create pointer to Node

    first->data = 'A';

    Node<char> *second = new Node<char>('R');

    first->next = second; // Assign next to address of second node

    second->next = new Node<char>('A'); // Second node's next points to 'A' address



//    Node<char>::print(first); // Should print out node

    cout << "First item's next's data: " << first->next->data << endl;
    cout << "Last Item: " << first->next->next->data << endl;


    int length;
    length = (*first).length();
    // Print list
    cout << "Printed linked lists size: " << length << endl;

    return 0;
}