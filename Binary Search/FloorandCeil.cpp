#include<iostream>
using namespace std;
int getFloor(int a[], int n,int x){
    int ans=-1;
	int low=0,high=n-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(a[mid]<=x){
			ans=a[mid];
			low=mid+1;
		}
		else high=mid-1;
	}
	return ans;
}
int getCeil(int a[], int n, int x){
    int ans=-1;
	int low=0,high=n-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(a[mid]>=x){
			ans=a[mid];
			high=mid-1;
		}
		else low=mid+1;
	}
	return ans;
}
void getFloorAndCeil(int a[], int n, int x, int &floor, int &ceil) {
	floor=getFloor(a,n,x);
    ceil=getCeil(a,n,x);
}
int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int floor,ceil;
    getFloorAndCeil(arr,n,target,floor,ceil);
    cout<<floor<<" "<<ceil;
    return 0;
}