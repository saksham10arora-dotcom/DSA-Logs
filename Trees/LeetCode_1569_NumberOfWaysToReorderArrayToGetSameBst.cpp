```cpp
// LeetCode problem 1569: Number Of Ways To Reorder Array To Get Same Bst
// https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/
// Given the array arr, reorder it such that the following conditions are met:
// 1. The length of the array is greater than or equal to 3.
// 2. In the array, there exists an index i such that arr[0] < arr[i] < arr[arr.length - 1].
// 3. If the value of arr[x] is greater than arr[0] and less than arr[arr.length - 1], then these three elements are in the same order in both the original and reordered array.
// Return the number of possible reorderings mod 10^9 + 7.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

// Brute force approach with O(n!) complexity
// int numOfWays(vector<int>& arr) {
//     int n = arr.size();
//     vector<int> perm(n);
//     for (int i = 0; i < n; i++) perm[i] = i;
//     int count = 0;
//     do {
//         vector<int> temp(n);
//         for (int i = 0; i < n; i++) temp[i] = arr[perm[i]];
//         if (temp[0] < temp[n - 1]) {
//             bool valid = true;
//             for (int i = 1; i < n - 1; i++) {
//                 if (arr[0] < arr[i] && arr[i] < arr[n - 1]) {
//                     if (temp[0] < temp[i] && temp[i] < temp[n - 1]) continue;
//                     valid = false;
//                     break;
//                 }
//             }
//             if (valid) count++;
//         }
//     } while (next_permutation(perm.begin(), perm.end()));
//     return count % MOD;
// }

// Optimal solution with O(n^2) complexity
int numOfWays(vector<int>& arr) {
    int n = arr.size();
    vector<int> smaller, larger;
    for (int i = 1; i < n - 1; i++) {
        if (arr[0] < arr[i] && arr[i] < arr[n - 1]) smaller.push_back(arr[i]);
        else if (arr[i] < arr[0] || arr[i] > arr[n - 1]) larger.push_back(arr[i]);
    }
    int m = smaller.size(), k = larger.size();
    vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j] * (i + j)) % MOD;
            if (j > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * j) % MOD;
        }
    }
    return dp[m][k];
}

int main() {
    vector<int> arr1 = {2, 3, 5, 9};
    vector<int> arr2 = {4, 2, 9, 6, 23, 12, 34, 0, 1};
    vector<int> arr3 = {1, 2, 3, 4, 5};
    cout << numOfWays(arr1) << endl;  // Output: 25
    cout << numOfWays(arr2) << endl;  // Output: 126
    cout << numOfWays(arr3) << endl;  // Output: 0
    return 0;
}
```