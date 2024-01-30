#include<iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  int size;
  Node(int d) {
    data = d;
    next = NULL;
  }
};

struct stack {
  Node* top;
  int size;
  stack() {
    top = NULL;
    size = 0;
  }

  void stackPush(int x) {
    Node* element = new Node(x);
    element -> next = top;
    top = element;
    cout << "Element pushed" << "\n";
    size++;
  }

  int stackPop() {
    if (top == NULL) {
      return -1;
    }
    int topData = top -> data;
    Node* temp = top;
    top = top -> next;
    delete temp;
    size--;
    return topData;
  }

  int stackSize() {
    return size;
  }

  bool stackIsEmpty() {
    return top == NULL;
  }

  int stackPeek() {
    if (top == NULL) return -1;
    return top -> data;
  }

  void printStack() {
    Node* current = top;
    while (current != NULL) {
      cout << current -> data << " ";
      current = current -> next;
    }
  }
};

int main() {
  stack s;
  s.stackPush(10);
  cout << "Element popped: " << s.stackPop() << "\n";
  cout << "Stack size: " << s.stackSize() << "\n";
  cout <<"Stack empty or not? "<<s.stackIsEmpty()<<"\n";
  cout << "stack's top element: " << s.stackPeek() << "\n";
  return 0;
}