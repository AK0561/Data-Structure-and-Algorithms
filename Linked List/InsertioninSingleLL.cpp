#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data1, Node* next1) : data(data1), next(next1) {}
    Node(int data1) : data(data1), next(nullptr) {}
};

Node* constructLL(vector<int>& arr) {
    int n=arr.size();
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<n;i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

//Insert a new node at the head of a linked list
Node* insertHead(Node* head,int val){
    Node* temp = new Node(val,head);
    return temp;
}

//Insert a new node at the tail of a linked list
Node* insertEnd(Node* head, int val) {
    if(head==NULL){
        return new Node(val);
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newNode= new Node(val);
    temp->next=newNode;
    return head;
}

//Insert a new node at Kth position of a linked list
Node* insertK(Node* head,int val,int k){
    if(head==NULL) return new Node(val);
    if(k==1){
        Node* temp = new Node(val,head);
        return temp;
    }
    int count=0;
    Node* temp = head;
    while(temp!=NULL){
        count++;
        if(count==k-1){
            Node* newNode=new Node(val);
            newNode->next=temp->next;
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}

//Insert a new node before the given element of a linked list
Node* insertbeforevalue(Node* head,int el,int val){
    if(head==NULL) return NULL;
    if(head->data==val){
        Node* temp = new Node(el,head);
        return temp;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        if(temp->next->data==val){
            Node* newNode=new Node(el);
            newNode->next=temp->next;
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* head = constructLL(arr);
    // head=insertHead(head,10);
    // head=insertK(head,25,2);
    head=insertbeforevalue(head,20,4);
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}