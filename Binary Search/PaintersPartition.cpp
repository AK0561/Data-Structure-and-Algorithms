#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int MaxiElem(vector<int> &boards){
    int n=boards.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        maxi=max(maxi,boards[i]);
    }
    return maxi;
}
int SumElem(vector<int> &boards){
    int n=boards.size();
    int sum1=0;
    for(int i=0;i<n;i++){
        sum1+=boards[i];
    }
    return sum1;
}
int countPainters(vector<int> &boards,int maxSum){
    int n=boards.size();
    int painters=1,subArraySum=0;
    for(int i=0;i<n;i++){
        if(subArraySum+boards[i]<=maxSum){
            subArraySum+=boards[i];
        }
        else {
            painters++;
            subArraySum=boards[i];
        }
    }
    return painters;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int low=MaxiElem(boards),high=SumElem(boards);
    while(low<=high){
        int mid=(low+high)/2;
        int NoOfPainters=countPainters(boards,mid);
        if(NoOfPainters>k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}
int main(){
    int n,painters;
    cin>>n>>painters;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<findLargestMinDistance(arr,painters);
    return 0;
}