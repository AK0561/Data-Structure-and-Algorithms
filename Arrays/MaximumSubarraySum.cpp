// #include<iostream>
// using namespace std;
// int maxSubArray(int nums[],int n) {
//     int sum=0;
//     int maxi=INT_MIN;
//     for(int i=0;i<n;i++){
//         sum+=nums[i];
//         if(sum>maxi){
//             maxi=sum;
//         }
//         if(sum<0){
//             sum=0;
//         }
//     }
//     // If we need to return an empty sub-array if the sum comes to be negative 
//     //if(maxi<0) maxi=0;
//     // If all numbers are negative, return the maximum negative number
//     if (maxi == INT_MIN) {
//             return *max_element(nums, nums+n);
//         }
//     return maxi;
// }
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     cout<<maxSubArray(arr,n);
//     return 0;
// }



//If we need to return the entire sub-array which returns the maximum sum
#include<iostream>
using namespace std;
int maxSubArray(int nums[],int n) {
    int sum=0;
    int maxi=INT_MIN;
    int start=0;
    int ansStart=-1;
    int ansEnd=-1;
    for(int i=0;i<n;i++){
        if(sum==0)  start=i;
        sum+=nums[i];
        if(sum>maxi){
            maxi=sum;
            ansStart=start;
            ansEnd=i;
        }
        if(sum<0){
            sum=0;
        }
    }
    //printing the sub-array:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << nums[i] << " ";
    }
    cout << "]\n";
    return maxi;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<maxSubArray(arr,n);
    return 0;
}