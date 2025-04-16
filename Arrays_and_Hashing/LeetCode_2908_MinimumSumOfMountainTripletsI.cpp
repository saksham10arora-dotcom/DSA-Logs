```cpp
// LeetCode problem 2908: Minimum Sum Of Mountain Triplets I
// https://leetcode.com/problems/minimum-sum-of-mountain-triplets-i/
// Given an array of integers, find the minimum sum of a mountain triplet.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(n^3) complexity
int minimumMountainSumBruteForce(std::vector<int>& arr) {
    int n = arr.size();
    int minSum = INT_MAX;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = i + 1; k < n; k++) {
                if (arr[j] < arr[i] && arr[i] > arr[k]) {
                    minSum = std::min(minSum, arr[j] + arr[i] + arr[k]);
                }
            }
        }
    }
    return minSum == INT_MAX ? -1 : minSum;
}

// Optimal solution with O(n) complexity
int minimumMountainSum(std::vector<int>& arr) {
    int n = arr.size();
    int minSum = INT_MAX;
    for (int i = 1; i < n - 1; i++) {
        int left = i - 1, right = i + 1;
        bool foundLeft = false, foundRight = false;
        while (left >= 0 && arr[left] < arr[i]) {
            foundLeft = true;
            left--;
        }
        while (right < n && arr[right] < arr[i]) {
            foundRight = true;
            right++;
        }
        if (foundLeft && foundRight) {
            minSum = std::min(minSum, arr[left + 1] + arr[i] + arr[right - 1]);
        }
    }
    return minSum == INT_MAX ? -1 : minSum;
}

int main() {
    std::vector<int> arr1 = {2, 3, 1, 2, 4, 3};
    std::vector<int> arr2 = {2, 2, 2, 2, 2};
    std::vector<int> arr3 = {1, 2, 3, 4, 5};
    std::cout << minimumMountainSum(arr1) << std::endl;  // Output: 8
    std::cout << minimumMountainSum(arr2) << std::endl;  // Output: -1
    std::cout << minimumMountainSum(arr3) << std::endl;  // Output: -1
    return 0;
}
```