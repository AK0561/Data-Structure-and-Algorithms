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

// Delete the head of a doubly linked list
Node* deleteHead(Node* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    free(prev);
    return head;
}

// Delete the tail of a doubly linked list
Node* deleteTail(Node* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    Node* prevNode = tail->back;
    prevNode->next = nullptr;
    tail->back = nullptr;
    free(tail);
    return head;
}

//Delete the Kth node of a doubly linked list
Node* deleteK(Node* head, int k){
    if(head==NULL){
        return NULL;
    }
    int count = 0;
    Node* kNode = head;
    while(kNode!=NULL){
        count++;
        if(count==k){
            break;
        }
        kNode = kNode->next;
    }
    Node* prev = kNode->back;
    Node* front = kNode->next;
    if(prev==NULL && front == NULL){
        delete kNode;
        return NULL;
    }
    else if (prev==NULL){
        return deleteHead(head);
    }
    else if(front == NULL){
        return deleteTail(head);
    }
    prev->next = front;
    front->back = prev;
    kNode->next = NULL;
    kNode->back = NULL;
    delete kNode;
    return head;
}

//Delete a given node of a doubly linked list.
//(It never deletes the head node of a linked list always the nodes next to it are deleted.)
void deleteNode(Node* node) {
    Node* prevNode=node->back;
    Node* front=node->next;
    if(front == NULL){
        prevNode->next=nullptr;
        node->back=nullptr;
        free(node);
        return ;
    }
    prevNode->next=front;
    front->back=prevNode;
    node->next=nullptr;
    node->back=nullptr;
    free(node);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* head=Array2DLL(arr);
    head=deleteK(head,1);
    print(head);
    return 0;
}