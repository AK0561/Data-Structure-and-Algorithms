#include<iostream>
#include<stack>
using namespace std;
class Queue {
public:
    stack<int> input,output;
    Queue() {
    }

    void enQueue(int val) {
        input.push(val);
    }

    int deQueue() {

        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        if(output.empty()) {
            return -1; 
        }
        int x = output.top();
        output.pop();
        return x;
    }

    int peek() {
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        if(output.empty()) {
            return -1; 
        }
        return output.top();
    }

    bool isEmpty() {
        return (input.empty() && output.empty());
    }

    int size(){
        return(input.size()+output.size());
    }
};

int main() {
  Queue q ;
  q.enQueue(4);
  q.enQueue(14);
  q.enQueue(24);
  q.enQueue(34);
  cout << "The peek of the queue before deleting any element " << q.peek() << endl;
  cout << "The size of the queue before deletion " << q.size() << endl;
  cout << "The first element to be deleted " << q.deQueue() << endl;
  cout << "The peek of the queue after deleting an element " << q.peek() << endl;
  cout << "The size of the queue after deleting an element " << q.size() << endl;
  return 0;
}