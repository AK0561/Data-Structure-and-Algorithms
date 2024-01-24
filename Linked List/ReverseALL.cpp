#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* back;
    Node(int data1, Node* next1, Node* back1) : data(data1), next(next1), back(back1) {}
    Node(int data1) : data(data1), next(nullptr), back(nullptr) {}
};

Node* Array2DLL(vector<int> arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

//Iterative Approach to reverse a linked list 
Node* IterativeReverseLL(Node* head){
    Node* temp = head;
    Node* prevNode = NULL;
    while( temp !=NULL ){
        Node* front = temp->next;
        temp->next = prevNode;
        prevNode = temp;
        temp = front;
    }
    return prevNode;
}

//Recursive Approach to reverse a linked list
Node* RecursiveReverseLL(Node* head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    Node* newHead = RecursiveReverseLL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* head=Array2DLL(arr);
    head=IterativeReverseLL(head);
    print(head);
    return 0;
}