#include<iostream>
using namespace std;
int BinarySearch(int arr[],int n,int low,int high,int target){
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(arr[mid]==target){
        return mid;
    }
    else if(target>arr[mid]){
        return BinarySearch(arr,n,mid+1,high,target);
    }
    return BinarySearch(arr,n,low,mid-1,target);
}
int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<BinarySearch(arr,n,0,n-1,target);
    return 0;
}