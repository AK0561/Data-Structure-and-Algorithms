//Count the number of digits
//1.
#include<iostream>
using namespace std;
int main(){
    int N,count=0;
    cin>>N;
    while(N>0){
      count+=1;
      N=N/10;
    }
    cout<<count;
}

//2.
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int N;
    cin>>N;
    int count=(int)(log10(N)+1);
    cout<<count;
}


//The given C++ code defines a function countDigits that takes an integer n as input and returns the 
//count of digits in n that divide n evenly (i.e., those digits for which n is divisible by the digit).
int countDigits(int n) {
    int count = 0;
    int num = n;

    while (num > 0) {
        // Extract the last digit from num
        int digit = num % 10;

        // Check if the digit is not zero
        if (digit != 0) {
            // Check if n is divisible by the digit
            if (n % digit == 0) {
                // If divisible, increment the count
                count++;
            }
        }

        // Move to the next digit by dividing num by 10
        num = num / 10;
    }

    // Return the final count
    return count;
}
