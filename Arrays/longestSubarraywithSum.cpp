#include <iostream>
#include <vector>
using namespace std;
int longestSubarrayWithSumK(vector<int> &a, long long k) {
    int n = a.size();
    int left = 0, right = 0;
    long long sum = a[0];
    int maxLen = 0;

    while (right < n) {
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;

        if (right < n) {
            sum += a[right];
        }
    }

    return maxLen;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    long long targetSum;
    cin >> targetSum;
    int result = longestSubarrayWithSumK(arr, targetSum);
    cout << "Length of the longest subarray with sum " << targetSum << ": " << result << endl;

    return 0;
}
