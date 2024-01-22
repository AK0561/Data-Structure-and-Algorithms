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

//Insert a node before the head in a doubly linked list
Node* insertHead(Node* head,int val){
    Node* newHead = new Node(val,head,nullptr);
    if(head==NULL) return newHead;
    head->back= newHead;
    return newHead;
}

//Insert a node before the tail in a doubly linked list
Node* insertTail(Node* head, int val){
    if(head->next==NULL){
        return insertHead(head, val);
    }
    if(head==NULL) return new Node(val);
    Node* tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    Node* prev = tail->back;
    Node* newNode = new Node(val, tail, prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}

//Insert a node before the Kth element in a doubly linked list
Node* insertK(Node* head,int k,int val){
    if(k==1) return insertHead(head,val);
    Node* temp=head;
    int count=0;
    while(temp != NULL){
        count++;
        if(count==k) break;
        temp=temp->next;
    }
    Node* prevNode = temp->back;
    Node* newNode = new Node(val,temp,prevNode);
    prevNode -> next = newNode;
    temp -> back = newNode;
    newNode -> next = temp;
    newNode -> back = prevNode;
    return head;
}

//Insert a node before the given node in a doubly linked list.
Node* insertNode(Node* node,int val){
    Node* prevNode = node->back;
    Node* newNode = new Node(val,node,prevNode);
    prevNode->next = newNode;
    node->back = newNode;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* head=Array2DLL(arr);
    head=insertNode(head->next,10);
    print(head);
    return 0;
}