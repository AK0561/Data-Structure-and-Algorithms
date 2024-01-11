#include<iostream>
using namespace std;
int floorSqrt(int n)
{
    int low=1,high=n;
    while(low<=high){
        long long mid=(low+high)/2;
        long long val=mid*mid;
        if(val<=(long long )(n)){
            low=mid+1;
        }
        else high=mid-1;
    }
    return high;
}
int main(){
    int num;
    cin>>num;
    cout<<floorSqrt(num);
    return 0;
}
