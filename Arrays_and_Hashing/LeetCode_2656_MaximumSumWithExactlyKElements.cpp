```cpp
// Maximum Sum With Exactly K Elements, https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/
// Given an array of integers and an integer k, find the maximum sum of exactly k elements.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach: generate all possible subsets of size k and calculate their sums (O(2^n * k))
int maxSumBF(std::vector<int>& nums, int k) {
    int n = nums.size();
    int maxSum = INT_MIN;
    for (int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i))!= 0) {
                sum += nums[i];
                count++;
            }
        }
        if (count == k) {
            maxSum = std::max(maxSum, sum);
        }
    }
    return maxSum;
}

// Optimal solution: sort the array and use a sliding window to find the maximum sum (O(n log n))
int maxSum(std::vector<int>& nums, int k) {
    std::sort(nums.rbegin(), nums.rend());
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }
    return sum;
}

int main() {
    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    int k1 = 2;
    std::cout << "Maximum sum with exactly " << k1 << " elements: " << maxSum(nums1, k1) << std::endl;

    std::vector<int> nums2 = {1, 2, 3, 4, 5};
    int k2 = 3;
    std::cout << "Maximum sum with exactly " << k2 << " elements: " << maxSum(nums2, k2) << std::endl;

    std::vector<int> nums3 = {1, 2, 3, 4, 5};
    int k3 = 1;
    std::cout << "Maximum sum with exactly " << k3 << " elements: " << maxSum(nums3, k3) << std::endl;

    return 0;
}
```