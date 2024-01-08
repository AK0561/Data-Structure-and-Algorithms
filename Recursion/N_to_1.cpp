#include<iostream>
using namespace std;
void num(int i,int n){
    if(i<1) return;
    cout<<i<<endl;
    num(i-1,n);
}
int main(){
    int n;
    cin>>n;
    num(n,1);
}