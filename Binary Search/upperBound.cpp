#include<iostream>
using namespace std;
int upperBound(int arr[], int n, int x){
	int low=0,high=n-1;
	int ans=n;
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]>x){
			ans=mid;
			high=mid-1;
		}
		else low=mid+1;
	}
	return ans;	
}
int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<upperBound(arr,n,target);
    return 0;
}