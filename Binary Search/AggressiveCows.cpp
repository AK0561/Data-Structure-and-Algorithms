#include<iostream>
#include<vector>
using namespace std;
bool CanWePlace(vector<int> &stalls,int distance,int cows){
    int n=stalls.size();
    int count=1,last=stalls[0];
    for(int i=0;i<n;i++){
        if(stalls[i]-last>=distance){
            count++;
            last=stalls[i];
        }
        if(count>=cows) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());
    int low=0,high=stalls[n-1]-stalls[0];
    while(low<=high){
        int mid=(low+high)/2;
        if(CanWePlace(stalls,mid,k)==true){
            low=mid+1;
        }
        else high=mid-1;
    }
    return high;
}
int main(){
    int n,cows;
    cin>>n>>cows;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<aggressiveCows(arr,cows);
    return 0;
}