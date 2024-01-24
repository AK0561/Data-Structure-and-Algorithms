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
Node* addTwoNumbers(Node *head1, Node *head2)
{
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* dummyNode = new Node(-1);
    Node* current = dummyNode;
    int carry=0;
    while(temp1 !=NULL || temp2 !=NULL ){
        int sum=carry;
        if(temp1) sum=sum+temp1->data;
        if(temp2) sum=sum+temp2->data;
        Node* newNode = new Node(sum%10);
        carry=sum/10;
        current->next=newNode;
        current=current->next;
        if(temp1) temp1=temp1->next;
        if(temp2) temp2=temp2->next;
    }
    if(carry){
        Node* newNode = new Node(carry);
        current->next=newNode;
    }
    return dummyNode->next;
}
int main() {
    int n1,n2;
    cin>>n1>>n2;
    vector<int> arr1(n1);
    for(int i=0;i<n1;i++) cin>>arr1[i];
    vector<int> arr2(n2);
    for(int i=0;i<n2;i++) cin>>arr2[i];
    Node* head1 = Array2DLL(arr1);
    Node* head2 = Array2DLL(arr2);
    cout << "Linked List 1: ";
    print(head1);
    cout << endl;
    cout << "Linked List 2: ";
    print(head2);
    cout << endl;
    Node* result = addTwoNumbers(head1, head2);
    cout << "Sum of the two numbers: ";
    print(result);
    cout << endl;
    return 0;
}
