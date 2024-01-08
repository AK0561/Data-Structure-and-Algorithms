#include<iostream>
using namespace std;
void RightRotate(int arr[],int n,int d){
    reverse(arr,arr+n);
    reverse(arr,arr+d);
    reverse(arr+d,arr+n);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)  cin>>arr[i];
    int d;
    cin>>d;
    RightRotate(arr,n,d);
    for(int i=0;i<n;i++)  cout<<arr[i]<<" ";
    return 0;
}