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

Node* deleteMiddle(Node* head){
    if( head == NULL || head->next ==NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    fast = fast->next->next;
    while( fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* middle = slow->next;
    slow->next=slow->next->next;
    free(middle);
    return head;
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* head=Array2DLL(arr);
    head=deleteMiddle(head);
    print(head);
    return 0;
}