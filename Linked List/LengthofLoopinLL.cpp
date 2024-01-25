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
int findLength(Node* slow,Node* fast){
    int count=1;
    fast = fast->next;
    while( slow != NULL){
        count++;
        fast = fast->next;
    }
    return count;
}

int LengthofCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while( fast != NULL && fast->next != NULL ){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return findLength(slow,fast);
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* head=Array2DLL(arr);
    cout<<LengthofCycle(head);
    return 0;
}