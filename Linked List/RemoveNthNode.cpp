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

Node* findNthNode(Node* temp,int k){
     int count = 1;
     while( temp != NULL){
          if( count == k) return temp;
          count++;
          temp = temp->next;
     }
     return temp;
}

Node* RemoveNth(Node* head, int N) {
    Node* fast = head;
    for(int i=0;i<N;i++) fast=fast->next;
    if(fast == NULL) return head->next;
    Node* slow = head;
    while( fast->next != NULL ){
        slow=slow->next;
        fast= fast->next;
    }
    Node* delNode = slow->next;
    slow->next = slow->next->next;
    free(delNode);
    return head;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* head=Array2DLL(arr);
    Node* newHead=RemoveNth(head,2);
    print(newHead);
    return 0;
}