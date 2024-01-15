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

//Array to a Linked List
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

//Length of a Linked List
int LengthLL(Node* head){
    int count=0;
    Node* temp=head;
    while(temp){
        temp=temp->next;
        count++;
    }
    return count;
}

//Search an Element in a Linked List
int searchElement(Node* head,int val){
    Node* temp=head;
    while(temp){
        if(temp->data==val)  return 1;
        temp=temp->next;
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* head = constructLL(arr);

    // Traversal in a Linked List
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" "<<endl;
        temp=temp->next;
    }
    cout<<LengthLL(head)<<endl;
    cout<<searchElement(head,5)<<endl;
    return 0;
}