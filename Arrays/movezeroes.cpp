#include<iostream>
#include<cmath>
using namespace std;
void moveZeros(int n, int a[]) {
    int j=-1;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            j=i;
            break;
        }
    }
    if(j==-1) return ;
    
    for(int i=j+1;i<n;i++){
        if(a[i]!=0){
            swap(a[i],a[j]);
            j++;
        }
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)  cin>>a[i];
    moveZeros(n,a);
    for(int i=0;i<n;i++)  cout<<a[i]<<" ";
    return 0;
}
