#include<iostream>
using namespace std;
void bubble(int arr[],int n){
    int didSwap=0;
    for(int i=n-1;i>=1;i--)
    {
        for(int j=0;j<=i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                didSwap=1;

            }
        }
        if(didSwap==0) {  // if array is already sorted in ascending order it never moves down to loop it simply does 0 swap operations and breaks out of the loop therefore optimizing our code to time complexity of O(N).
            break;
        }
        cout<<"Array runs\n";
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    bubble(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}