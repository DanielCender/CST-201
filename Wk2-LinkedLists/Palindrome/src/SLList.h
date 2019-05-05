//
// Created by Daniel Cender on 2019-05-02.
//
#include "Node.h"
#ifndef DQ2_SLLIST_H
#define DQ2_SLLIST_H



template <typename T>
class SLList {
public:
    SLList() {
        head = tail = 0;
    };
    ~SLList()  {
        for(Node<T>* p = head; !isEmpty();) {
            p = head->next; // Moves pointer forward in list
            delete head;
            head = p; // Sets new head, so next ->next moves to next pointer
        }
    };
    bool isEmpty()  {
        return head == 0;
    };
    bool isInList(T d)  {
        Node<T>* temp;
        for(temp = head; temp != 0 && (temp->data != d); temp = temp->next);
        return temp != 0;
    };
    void insertAfterNode(Node<T>* prev, T data)  {
        // Node shouldn't be null
        if(prev == NULL) {
            cout << "Node specified is null" << endl;
            return;
        }
        Node<T> new_node(data);

        // The list should not be empty
        if(this->isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }

        // connect new node to *prev's 'next'
        new_node = prev->next;
        // Make prev's next go to new node
        prev->next = new_node;
        return;
    };
    void insert(int index, T data)  {
        if(this->isEmpty()) {
            cout << "List is empty. Insertion not possible" << endl;
            return;
        }
        for(int i = 0; (head->next) != NULL && (i < index); head = head->next, i++) {
            cout << "This iteration, " << i << ": " << head->data << endl;
        }
    };

    void push(T data) {
        Node<T> *tmp = new Node<T>(data);

        tmp->next = tail;

        for(; head->next != NULL; head = head->next);
        head->next = tmp;
    };

    // basic array-style adder
    void addToHead(T d) ;
    void addToTail(T d);
    void print()  {
        if(this->isEmpty()) {
            cout << "List is empty. Nothing to print here." << endl;
            return;
        }
        for(; head->next != NULL; head = head->next) {
            cout << head->data << " ";
        }
        cout << endl;
        return;
    };
private:
    Node<T> *head, *tail;
};


#endif //DQ2_SLLIST_H
