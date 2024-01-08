#include<iostream>
using namespace std;

void num(int i, int n) {
    if (i > n) return;  // Adjusted the base case
    num(i + 1, n);      // Adjusted the recursive call
    cout << i << endl;
}

int main() {
    int n;
    cin >> n;
    num(1, n);  // Start from 1 and go up to n
    return 0;
} 