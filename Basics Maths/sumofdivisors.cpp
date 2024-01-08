// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int sum=0;
//     for(int i=1;i<=n;i++){
//        sum+=(n/i)*i;
//     }
//     cout<<sum;
// }


// #include<iostream>
// using namespace std;

// int divisor(int n) {
//     int sum = 0;
//     for (int i = 1; i <= n; i++) {
//         if (n % i == 0) {
//             sum += i;
//         }
//     }
//     return sum;
// }

// int Sum_Div(int n) {
//     int finalsum = 0;
//     while (n > 0) {
//         finalsum += divisor(n);
//         n -= 1;
//     }
//     return finalsum;
// }

// int main() {
//     int n;
//     cin >> n;
//     int result = Sum_Div(n);
//     cout << "Sum of divisors: " << result << endl;
//     return 0;
// }


#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            cout<<i<<endl;
            if((n/i)!=i){
                cout<<(n/i)<<endl;
            }
        }
    }
}