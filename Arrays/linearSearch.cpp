#include<iostream>
using namespace std;
int linearSearch(int n, int num, int arr[])
{
    for(int i=0;i<num;i++){
        if(arr[i]==num){
            return i;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)  cin>>arr[i];
    int num;
    cin>>num;
    cout<<linearSearch(n,num,arr);
}
