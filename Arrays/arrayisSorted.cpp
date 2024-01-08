#include<iostream>
using namespace std;
int isSorted(int n, int a[]) {
    // Write your code here.
    for(int i=1;i<n;i++){
        if(a[i]>=a[i-1]){

        }
        else{
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)  cin>>arr[i];
    cout<<isSorted(n,arr);
    return 0;
}