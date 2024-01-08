// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int revNum=0;
//     while(n>0){
//         int ld=n%10;
//         revNum=(revNum*10)+ld;
//         n=n/10;
//     }
//     cout<<revNum;
// }

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int revNum=0;
    while(n!=0){
        int ld=n%10;

        // Check for integer overflow before updating revNum
            if (revNum > INT_MAX / 10 || (revNum == INT_MAX / 10 && ld > 7)) {
                return 0; // Return 0 in case of overflow
            }
            if (revNum < INT_MIN / 10 || (revNum == INT_MIN / 10 && ld < -8)) {
                return 0; // Return 0 in case of overflow
            }
        revNum=(revNum*10)+ld;
        n=n/10;
    }
    cout<<revNum;
}