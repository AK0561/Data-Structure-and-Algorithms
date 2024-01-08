#include<iostream>
using namespace std;
int findMaxConsecutiveOnes(int nums[],int n) {
        int maxi=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
            count++;
            maxi=max(maxi,count);
        }
        else{
            count=0;
        }
    }
    return maxi;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)  cin>>arr[i];
    cout<<findMaxConsecutiveOnes(arr,n);
}