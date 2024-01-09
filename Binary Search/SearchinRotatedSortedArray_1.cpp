//If the array contains unique values.
#include<iostream>
using namespace std;
int search(int arr[], int n, int k)
{
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==k){
            return mid;
        }
        if(arr[low]<=arr[mid]){
            if(arr[low]<=k && k<=arr[mid]){
                high=mid-1;
            }
            else low=mid+1;
        }
        else{
            if(arr[mid]<=k && k<=arr[high]){
                low=mid+1;
            }
            else high=mid-1;
        }
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
    cout<<search(arr,n,target);
    return 0;
}