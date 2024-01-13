#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int MaxElem(vector<int> &a){
    int n=a.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        maxi=max(maxi,a[i]);
    }
    return maxi;
}
int SumElem(vector<int> &a){
    int n=a.size();
    int sum1=0;
    for(int i=0;i<n;i++){
        sum1+=a[i];
    }
    return sum1;
}
int countPartitions(vector<int> &a, int maxSum){
    int n=a.size();
    int partitions=1,subArraySum=0;
    for (int i=0;i<n;i++){
        if(subArraySum+a[i]<=maxSum){
            subArraySum+=a[i];
        }
        else {
            partitions++;
            subArraySum=a[i];
        }
    }
    return partitions;
}
int largestSubarraySumMinimized(vector<int> a, int k) {
    int low=MaxElem(a),high=SumElem(a);
    while(low<=high){
        int mid=(low+high)/2;
        int NoOfPartitions=countPartitions(a,mid);
        if(NoOfPartitions>k){
            low=mid+1;
        }
        else high=mid-1;
    }
    return low;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<largestSubarraySumMinimized(arr,k);
    return 0;
}