#include<iostream>
#include<queue>
using namespace std;

class Stack {
   queue< int > q1,q2;
   public:

    int getSize() {
        // Implement the getSize() function.
        return q1.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        if( q1.empty()) { return 1;}
        else return 0;
    }

    void push(int element) {
        // Implement the push() function.
        q2.push(element);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }

    int pop() {
        // Implement the pop() function.
        if( q1.empty() ) { return -1; }
        int ele = q1.front();
        q1.pop();
        return ele;
    }

    int top() {
        // Implement the top() function.
        if( q1.empty()) { return -1; }
        return q1.front();
    }
};

int main()
{
  Stack s;
  s.push(6);
  s.push(3);
  s.push(7);
  cout << "Top of stack is before deleting any element " << s.top() << endl;
  cout << "Size of stack before deleting any element " << s.getSize() << endl;
  cout << "The element deleted is " << s.pop() << endl;
  cout << "Size of stack after deleting an element " << s.getSize() << endl;
  cout << "Top of stack after deleting an element " << s.top() << endl;
  return 0;
}