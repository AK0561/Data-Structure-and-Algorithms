#include<iostream>
using namespace std;

void n_forest(int n)
{
    for(int i=1;i<=n;i++){
         for(int j=0;j<n-i+1;j++){
            cout<<"* ";
         }
         cout<<endl;
    }
}

int main() {
    int n;
    cin>>n;
    n_forest(n);
}