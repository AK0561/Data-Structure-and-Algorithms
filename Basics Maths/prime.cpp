#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    int count=0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            count++;
            if((n/i)!=i){
                count++;
            }
        }
    }
    if(count==2) cout<<"Prime No";
    else cout<<"Not a Prime No";
}