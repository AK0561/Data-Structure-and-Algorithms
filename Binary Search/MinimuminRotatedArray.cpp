#include<iostream>
using namespace std;
int findMin(int arr[],int n)
{
	int low=0,high=n-1;
	int ans=INT_MAX;
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[low]<=arr[mid]){
			ans=min(ans,arr[low]);
			low=mid+1;
		}
		else{
			ans=min(ans,arr[mid]);
			high=mid-1;
		}
	}
	return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<findMin(arr,n);
    return 0;
}