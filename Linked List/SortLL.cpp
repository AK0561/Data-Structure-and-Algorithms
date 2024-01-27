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

Node* findMiddle(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while( fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* Merge2SortedLL(Node* head1,Node* head2){
    Node* t1 = head1;
    Node* t2 = head2;
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while( t1 != NULL && t2 != NULL ){
        if( t1->data <= t2->data){
            temp->next = t1;
            temp = t1;
            t1=t1->next;
        }
        else{
            temp->next = t2;
            temp = t2;
            t2=t2->next;
        }
        if(t1) temp->next = t1;
        else temp->next = t2;
    }
    return dummyNode->next;
}

Node* sortLL(Node* head){
    if( head == NULL || head->next == NULL ) return head;
    Node* middle = findMiddle(head);
    Node* leftHead = head;
    Node* rightHead = middle->next;
    middle->next = nullptr;
    leftHead = sortLL(leftHead);
    rightHead = sortLL(rightHead);
    return  Merge2SortedLL(leftHead,rightHead);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* head=Array2DLL(arr);
    Node* newHead=sortLL(head);
    print(newHead);
    return 0;
}