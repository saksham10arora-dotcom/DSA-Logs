```cpp
// Maximum Product Of First And Last Elements Of A Subsequence, https://leetcode.com/problems/maximum-product-of-first-and-last-elements-of-a-subsequence/
// Given an array of integers, find the maximum product of the first and last elements of a subsequence.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach: generate all possible subsequences and calculate the product of the first and last elements
// O(2^n * n) complexity
int maxProductBruteForce(std::vector<int>& nums) {
    int maxProduct = 0;
    int n = nums.size();
    for (int mask = 1; mask < (1 << n); mask++) {
        std::vector<int> subsequence;
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) != 0) {
                subsequence.push_back(nums[i]);
            }
        }
        if (!subsequence.empty()) {
            maxProduct = std::max(maxProduct, subsequence[0] * subsequence.back());
        }
    }
    return maxProduct;
}

// Optimal solution: use dynamic programming to store the maximum product of the first and last elements of a subsequence
// O(n^2) complexity
int maxProduct(std::vector<int>& nums) {
    int n = nums.size();
    int maxProduct = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            maxProduct = std::max(maxProduct, nums[i] * nums[j]);
        }
    }
    return maxProduct;
}

int main() {
    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    std::vector<int> nums2 = {-1, -2, -3, -4, -5};
    std::vector<int> nums3 = {1, -2, 3, -4, 5};

    std::cout << "Maximum product of first and last elements of a subsequence for nums1: " << maxProduct(nums1) << std::endl;
    std::cout << "Maximum product of first and last elements of a subsequence for nums2: " << maxProduct(nums2) << std::endl;
    std::cout << "Maximum product of first and last elements of a subsequence for nums3: " << maxProduct(nums3) << std::endl;

    return 0;
}
```