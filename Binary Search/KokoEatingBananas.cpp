#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int maxElem(vector<int>& piles){
        int n=piles.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }
    return maxi;
    }

int func(vector<int>& piles,int hourly){
        int n=piles.size();
        int totalHrs=0;
        for(int i=0;i<n;i++){
            totalHrs+=ceil((double)piles[i]/(double)hourly);
        }
        return totalHrs;
    }

int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=maxElem(piles);
        while(low<=high){
            int mid= (low+high)/2;
            int totalHrs=func(piles,mid);
            if(totalHrs<=h){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
int main(){
    int n,h;
    cin>>n>>h;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<minEatingSpeed(arr,h);
    return 0;
}