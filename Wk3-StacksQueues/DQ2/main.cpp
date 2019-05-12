/**
 *  DQ2/ main.cpp
 *  Author: Daniel Cender
 *  Date: 05/10/2019
 *  Description: This program implements a stack class.
 */
#include <iostream>
using namespace std;


template <typename T, int size_of = 100>
class Stack {
 public:
  Stack(){
    for(int i = 0; i < sizeof(stack)/sizeof(stack[0]); i++) {
      stack[i] = {0}; // initialize to NULL
    }
    _top = 0; // set top array index to 0
  }
  void push(T data) {
    if(stack[_top] == 0 && _top == 0) {
      stack[_top] = data;
    } else {
      _top += 1;
      stack[_top] = data;
    }
  }
  T pop() {
    int res = stack[_top];
    stack[_top] = 0;
    _top = _top == 0 ? 0 : _top - 1; // don't decrement if already 0
    return res;
  }
  T top() {
    return (stack[_top]);
  }
  int size() {
    return _top + 1;
  }
  bool isEmpty() {
  return stack[0] == 0;
  }
 private:
  T stack[size_of];
  int _top;
};


int main() {
  Stack<int> *ex_stack = new Stack<int>();
  ex_stack->push(2);
  ex_stack->push(3);

  cout << "Size of stack: " << ex_stack->size() << " elements." << endl;

  int top_el = ex_stack->top();
  cout << "Top Element (should be 3): " << top_el << endl;

  bool isEmpty1 = ex_stack->isEmpty();
  cout << "Is Empty?: " << isEmpty1 << endl;

  int first = ex_stack->pop();
  int second = ex_stack->pop();

  cout << "First el: " << first << endl;
  cout << "Second el: " << second << endl;

  bool isEmpty2 = ex_stack->isEmpty();
  cout << "Is Empty Now?: " << isEmpty2 << endl;

  return 0;
}