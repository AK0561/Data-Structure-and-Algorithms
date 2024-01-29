#include<iostream>
#include<vector>
using namespace std;

class Queue {

	int front, rear;
	vector<int> arr;

public:
	Queue()
	{
		front = 0;
		rear = 0;
		arr.resize(100001);
	}

	// Enqueue (add) element 'e' at the end of the queue.
	void enqueue(int e)
	{
		// Write your code here.
		if(rear == arr.size()) return ;
        arr[rear% arr.size()]=e;
        rear++;
	}

	// Dequeue (retrieve) the element from the front of the queue.
	int dequeue()
	{
		// Write your code here.
		if(front == rear) return -1 ;
        int x = arr[front%arr.size()];
        front++;
        return x;
	}

    int top(){
        if(front == rear) return -1;
        return arr[front % arr.size()];
    }

    int size(){
        return rear-front;
    }
};

int main() {
  Queue q ;
  q.enqueue(4);
  q.enqueue(14);
  q.enqueue(24);
  q.enqueue(34);
  cout << "The peek of the queue before deleting any element " << q.top() << endl;
  cout << "The size of the queue before deletion " << q.size() << endl;
  cout << "The first element to be deleted " << q.dequeue() << endl;
  cout << "The peek of the queue after deleting an element " << q.top() << endl;
  cout << "The size of the queue after deleting an element " << q.size() << endl;
  return 0;
}