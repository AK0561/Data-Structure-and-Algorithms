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


int main(){
    int n1,n2;
    cin>>n1>>n2;
    vector<int> arr1(n1);
    for(int i=0;i<n1;i++) cin>>arr1[i];
    vector<int> arr2(n2);
    for(int i=0;i<n2;i++) cin>>arr2[i];
    Node* head1=Array2DLL(arr1);
    Node* head2=Array2DLL(arr2);
    Node* newHead=Merge2SortedLL(head1,head2);
    print(newHead);
    return 0;
}