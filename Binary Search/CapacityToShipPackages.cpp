#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int MaxiElem(vector<int> &weights){
    int n=weights.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        maxi=max(maxi,weights[i]);
        }
    return maxi;
    }
int SumElem(vector<int> &weights){
    int n=weights.size();
    int sum1=0;
    for(int i=0;i<n;i++){
        sum1+=weights[i];
        }
    return sum1;
    }
int NoOfDays(vector<int> &weights , int capacity){
    int n=weights.size();
    int days=1,load=0;
    for(int i=0;i<n;i++){
        if(load+weights[i]>capacity){
            days=days+1;
            load=weights[i];
            }
        else load+=weights[i];
        }
    return days;
    }
int shipWithinDays(vector<int>& weights, int days) {
    int low=MaxiElem(weights),high=SumElem(weights);
    while(low<=high){
        int mid=(low+high)/2;
        int DaysReq=NoOfDays(weights,mid);
        if(DaysReq<=days){
            high=mid-1;
            }
        else low=mid+1;
        }
    return low;
}
int main(){
    int n,days;
    cin>>n>>days;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<shipWithinDays(arr,days);
    return 0;
}