#include<iostream>
using namespace std;
int getSingleElement(int arr[],int n){
int xor1=0;
	for(int i=0;i<n;i++){
		xor1=xor1^arr[i];
	}	
	return xor1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)  cin>>arr[i];
    cout<<getSingleElement(arr,n);
}