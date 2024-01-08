#include<iostream>
using namespace std;
int BinarySearch(int arr[],int n,int target){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(target>arr[mid]){
            low=mid+1;
        }
        else high=mid-1;
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<BinarySearch(arr,n,target);
    return 0;
}