//Moore's Voting Algorithm
#include<iostream>
using namespace std;
int majorityElement(int v[],int n) {
	int count=0;
	int ele;
	for(int i=0;i<n;i++){
		if(count == 0){
			count=1;
			ele=v[i];
		}
		else if(v[i]==ele) count++;
		else count--;
	}
	int count1=0;
	for(int i=0;i<n;i++){
		if(v[i]==ele) count1++;
		if(count1>(n/2)) {
			return ele;
		}
	}
	return -1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<majorityElement(arr,n);
    return 0;
}