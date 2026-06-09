```cpp
// LeetCode problem 873: Length Of Longest Fibonacci Subsequence
// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/
// A sequence X_1, X_2, ..., X_n is fibonacci-like if
// n >= 3 and X_i = X_{i-1} + X_{i-2} for all i >= 3.
// Find the length of the longest Fibonacci-like subsequence of arr.

#include <iostream>
#include <vector>
#include <unordered_set>

// Brute force approach: generate all possible subsequences and check if they are Fibonacci-like
// O(2^n * n) complexity
int findLenBF(std::vector<int>& arr) {
    int n = arr.size();
    int maxLen = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        std::vector<int> sub;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sub.push_back(arr[i]);
            }
        }
        if (sub.size() >= 3 && isFibonacci(sub)) {
            maxLen = std::max(maxLen, (int)sub.size());
        }
    }
    return maxLen;
}

bool isFibonacci(const std::vector<int>& sub) {
    for (int i = 2; i < sub.size(); ++i) {
        if (sub[i] != sub[i-1] + sub[i-2]) {
            return false;
        }
    }
    return true;
}

// Optimal solution: use a set to store the elements of arr and check for Fibonacci-like subsequences
// O(n^2) complexity
int lenLongestFibSubseq(std::vector<int>& arr) {
    int n = arr.size();
    std::unordered_set<int> s(arr.begin(), arr.end());
    int maxLen = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int a = arr[i], b = arr[j];
            int len = 2;
            while (s.count(a + b)) {
                int temp = a + b;
                a = b;
                b = temp;
                ++len;
            }
            maxLen = std::max(maxLen, len);
        }
    }
    return maxLen > 2 ? maxLen : 0;
}

int main() {
    std::vector<int> arr1 = {1, 2, 3, 5, 8, 13};
    std::vector<int> arr2 = {1, 3, 7, 11, 12, 14, 18};
    std::vector<int> arr3 = {1, 2, 3, 4, 5, 6, 7, 8};
    std::cout << lenLongestFibSubseq(arr1) << std::endl;  // Output: 6
    std::cout << lenLongestFibSubseq(arr2) << std::endl;  // Output: 3
    std::cout << lenLongestFibSubseq(arr3) << std::endl;  // Output: 0
    return 0;
}
```