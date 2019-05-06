#include <iostream>
#include "src/Node.h"
#include "src/SLList.h"
#include "src/DLList.h"
using namespace std;
/**
 *  Name: Palindrome Functions
 *  Author: Daniel Cender
 *  Date: 04/30/2019
 *  Description: This program implements a singly and doubly linked list and tests each if their contents are a palindrome.
 */


template <typename T>
bool compareSList(Node<T> *head1, Node<T> *head2) {
  Node<T> *tmp1 = head1;
  Node<T> *tmp2 = head2;

  while(tmp1 && tmp2) {
    if(tmp1->data == tmp2->data) {
      tmp1 = tmp1->next;
      tmp2 = tmp2->next;
    } else return 0;
  }
}

template <typename T>
void reverse(Node<T> **head) {
  Node<T> *prev_in_reverse = NULL;
  Node<T> *current_in_reverse = *head;
  Node<T> *next_node;
  while(current_in_reverse != NULL) { // While second half is being chewed through
    next_node = current_in_reverse->next; // Preserve link to next
    current_in_reverse->next = prev_in_reverse;
    prev_in_reverse = current_in_reverse;
    current_in_reverse = next_node;
  }
  *head = prev_in_reverse; // second_half acts as head of new reversed list
}

template <typename T>
bool isPalindromeSLL(Node<T> *head) {
  // Fast ptr will increment +2, slow by +1
  Node<T> *slow_ptr = head;
  Node<T> *fast_ptr = head;
  Node<T> *prev_slow_ptr = head;
  Node<T> *mid_node, *second_half = NULL;
  bool res = true;

  if((head != NULL) && (head->next != NULL)) {

    // Get to the mid of the list
    while (fast_ptr != NULL && fast_ptr->next != NULL) {
      fast_ptr = fast_ptr->next->next; // Increment +2


      prev_slow_ptr = slow_ptr; // Keep previous state
      slow_ptr = slow_ptr->next;
    }

    if (fast_ptr != NULL) { // Then the list is even
      mid_node = slow_ptr;
      slow_ptr = slow_ptr->next;
    }

    second_half = slow_ptr;
    prev_slow_ptr->next = NULL; // Delete ref to first half for comparison

    reverse(&second_half); // Reverse second half

    res = compareSList(head, second_half);

    reverse(&second_half); // Reverse again for piecing list back together

    if (mid_node != NULL) {
      prev_slow_ptr->next = mid_node;
      mid_node->next = second_half;
    } else prev_slow_ptr->next = second_half;
  }
  return res;
}



template <typename T>
bool isPalindromeDLL(DNode<T> *head) {
  if(head == NULL) {
    return true; // 1 character palindrome
  }

  // Get to the end of the list
  DNode<T> *end = head;
  while(end->next != NULL) {
    end = end->next;
  }
  while(head != end) {
    if(head->data != end->data) {
      return false;
    }
    head = head->next;
    end = end->prev;
  }
  return true; // No unmatched values
}


int main() {
    SLList<char> *list = new SLList<char>();
DLList<char> *d_list = new DLList<char>();
    // A palindrome
    list->push('A');
    list->push('D');
    list->push('A');


    // THESE FUNCTIONS ARE NOT WORKING PROPERLY YET - Minor bugs to fix it seems
    // Should return as true
//  cout << "Is *list a palindrome??? -> " << isPalindromeSLL(list->head) << "." << endl;

  // Should now return as false
  list->push('Z');
//  cout << "Is *list a palindrome??? -> " << isPalindromeSLL(list->head) << "." << endl;

    d_list->push('A');
    d_list->push('D');
    d_list->push('A');


    // Should return as true
    cout << "Doubly Linked: Is a palindrome? - " << isPalindromeDLL(d_list->head) << "." << endl;

    // Now function should not return 1 - TRUE
    d_list->push('Z');
  cout << "Doubly Linked: Is a palindrome? - " << isPalindromeDLL(d_list->head) << "." << endl;



    return 0;
}