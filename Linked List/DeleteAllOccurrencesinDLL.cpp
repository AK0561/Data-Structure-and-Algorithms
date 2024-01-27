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

Node* deleteAllOccurrences(Node* head,int key){
    Node* temp = head;
    while( temp != NULL ){
        if( temp->data == key ){
        if( temp == head ){
            head = temp->next;
        }
        Node* nextNode = temp->next;
        Node* prevNode = temp->back;
        if( nextNode != NULL ) nextNode->back = prevNode;
        if( prevNode != NULL) prevNode->next = nextNode; 
        delete temp;
        temp=nextNode;
    }
    else{
        temp=temp->next;
    }
}
    return head;
}


int main(){
    int n;
    cin>>n;
    int key;
    cin>>key;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* head=Array2DLL(arr);
    head=deleteAllOccurrences(head,key);
    print(head);
    return 0;
}