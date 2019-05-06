/**
 *  Maze2/src Maze.h
 *  Author: Daniel Cender
 *  Date: 05/05/2019
 *  Description: This header implements a doubly linked list to store the maze tiles.
 */
#include "Point.h"
#include <iostream>
using namespace std;

#ifndef MAZE2_SRC_MAZE_H_
#define MAZE2_SRC_MAZE_H_

template <typename T>
class Maze {
 public:
  Point<T> *head, *tail;
  Maze() {
    head = tail = 0;
  }
  ~Maze()  {
    for(Point<T>* p = head; !isEmpty();) {
      p = head->next; // Moves pointer forward in list
      delete head;
      head = p; // Sets new head, so next ->next moves to next pointer
    }
  };
  bool isEmpty()  {
    return head == 0;
  };
  // Pushes a node onto the HEAD of a list
  void push(T d) {
    Point<T> *new_node = new Point<T>(d);
    new_node->next = head;
    new_node->prev = 0;
    if(head != NULL) {
      head->prev = new_node;
    }
    head = new_node;
  }
  T getNth(int index) {
    Point<T> *current = head;
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
  void insert(Point<T>* node, int index) {
    int counter = 0;
    Point<T> *current = head;
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

#endif //MAZE2_SRC_MAZE_H_
