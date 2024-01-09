//To count the number of occurrences of a specific element in the given array of elements we use secondOccurrence-firstOccurrence+1.
#include<iostream>
using namespace std;
int firstPosition(int arr[], int n, int k){ 
    int low=0,high=n-1;
    int first=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==k){
            first=mid;
            high=mid-1;
        }
        else if(arr[mid]<k){
            low=mid+1;
        }
        else high=mid-1;
    }
    return first;
}
int lastPosition(int arr[], int n, int k){
    int low=0,high=n-1;
    int last=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==k){
            last=mid;
            low=mid+1;
        }
        else if(arr[mid]<k){
            low=mid+1;
        }
        else high=mid-1;
    }
    return last;
}
int firstAndLastPosition(int arr[], int n, int k,int &first, int &last)
{
    first=firstPosition(arr, n, k);
    last=lastPosition(arr, n, k);
}
int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int first,last;
    firstAndLastPosition(arr,n,target,first,last);
    if(first==-1) cout<<"{-1,-1}";
    else cout<<first<<" "<<last;
    return 0;
}
