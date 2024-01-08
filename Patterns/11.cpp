#include<iostream>
using namespace std;

void flip_01(int n)
{
   int start=1;
    for(int i=0;i<n;i++){
        if(i%2==0) start=1;
        else start=0;
        for(int j=0;j<=i;j++){
            cout<<start<<" ";
            start=1-start; // used to make a flip pattern such as 1 0 1 0 ...
        }
        cout<<endl;
    }
}

int main() {
    int n;
    cin>>n;
    flip_01(n);
}