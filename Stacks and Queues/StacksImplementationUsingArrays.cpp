#include<iostream>
using namespace std;

class Stack {
    int stackCapacity;
    int *arr;
    int topIndex;
    public:
    Stack(int size){
        topIndex=-1;
        stackCapacity=size;
        arr = new int[stackCapacity];
    }
    void push(int num)
    {
        if(!isEmpty()){
            topIndex++;
            arr[topIndex]=num;
        }
    }

    int pop(){
        if(topIndex==-1){
            return -1;
        }
        int num=arr[topIndex];
        topIndex--;
        return num;
    }

    int Top(){
        if(topIndex==-1){
            return -1;
        }
        return arr[topIndex];
    }

    int sizeStack(){
        return topIndex+1;
    }

    int isEmpty(){
        return((topIndex+1)==stackCapacity);
    }

};

int main()
{
  Stack s(5);
  s.push(6);
  s.push(3);
  s.push(7);
  cout << "Top of stack is before deleting any element " << s.Top() << endl;
  cout << "Size of stack before deleting any element " << s.sizeStack() << endl;
  cout << "The element deleted is " << s.pop() << endl;
  cout << "Size of stack after deleting an element " << s.sizeStack() << endl;
  cout << "Top of stack after deleting an element " << s.Top() << endl;
  return 0;
}