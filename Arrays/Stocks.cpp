#include<iostream>
using namespace std;
int bestTimeToBuyAndSellStock(int prices[],int n) {
    int mini=prices[0];
    int profit=0;
    for(int i=1;i<n;i++){
        int cost=prices[i]-mini;
        profit=max(profit,cost);
        mini=min(mini,prices[i]);
    }
    return profit;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<bestTimeToBuyAndSellStock(arr,n);
    return 0;
}