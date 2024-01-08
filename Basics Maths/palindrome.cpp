#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int dup=n;
    int RevNum=0;
    while(n>0){
        int ld=n%10;
        RevNum=RevNum*10+ld;
        n=n/10;
    }
     cout << (dup == RevNum) << endl;  
    return 0;  
}