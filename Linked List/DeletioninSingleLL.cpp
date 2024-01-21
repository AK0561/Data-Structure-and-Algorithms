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

//Deleting the head of a linked list
Node* deleteHead(Node* head){
    if(head==NULL) return head;
    Node* temp=head;
    head=head->next;
    free(temp);
    return head;
}

//Deleting the tail(last node) of a linked list
Node* deleteLast(Node *head){
    // Write your code here
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp=head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next=nullptr;
    return head;
}

//Deleting the kth node of a linked list
Node* deleteK(Node *head,int k){
    if (head == NULL)
        return head;
    if (k == 0) {
        Node* temp = head;
        head = head->next;
        delete (temp);
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    int cnt = 0;
    while (temp != NULL) {
        if (cnt == k) {
          prev->next = prev->next->next;
          delete temp;
          break;
        }
        prev = temp;
        temp = temp->next;
		cnt++;
    }
    return head;
}

//Deleting the given element of a linked list
Node* deleteELement(Node *head,int el){
    if (head == NULL)
        return head;
    if (head->data == 1) {
        Node* temp = head;
        head = head->next;
        delete (temp);
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while (temp != NULL) {
        if (temp->data == el) {
          prev->next = prev->next->next;
          delete temp;
          break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main(){
    int n;
    cin>>n;
    int ele;
    cin>>ele;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* head = constructLL(arr);
    head=deleteELement(head,ele);
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}