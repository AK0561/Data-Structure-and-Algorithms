// // Optimal approach which can used for the first type of problem which checks whether the elements present in the array yield the given target.
#include<iostream>
using namespace std;
string TwoSum(int n, int arr[], int target)
{
    // Write your code here.
    int left=0,right=n-1;
    sort(arr,arr+n);
    while(left<right){
        int sum=arr[left]+arr[right];
        if(sum==target){
            return "YES";
        }
        else if(sum<target) left++;
        else right--;
    }
    return "NO";
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
         cin>>arr[i];
    }
    int targetSum;
    cin>>targetSum;
    cout<<TwoSum(n,arr,targetSum);
}

// Optimal approach which can used for the second type of problem which return the index of the elements present in the array yield the given target.
// #include<iostream>
// #include<map>
// using namespace std;
// vector <int>twoSum(vector<int>&nums, int target) {
//         map<int,int>mpp;
//         for(int i=0;i<nums.size();i++){
//             int num = nums[i];
//             int moreNeeded = target-num;
//             if(mpp.find(moreNeeded)!=mpp.end()){
//                 return{i,mpp[moreNeeded]};
//             }
//             mpp[num]=i;
//         }
//     return {-1,-1};
//     }
