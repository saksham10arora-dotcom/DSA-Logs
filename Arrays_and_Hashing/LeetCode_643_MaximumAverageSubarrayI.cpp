```cpp
// Maximum Average Subarray I
// https://leetcode.com/problems/maximum-average-subarray-i/
// Given an array of integers, find the maximum average subarray of a given size.

#include <iostream>
#include <vector>
#include <numeric>

// Brute force approach with O(n*k) complexity
double findMaxAverageBruteForce(std::vector<int>& nums, int k) {
    double maxAverage = -1e9;
    for (int i = 0; i <= nums.size() - k; i++) {
        double sum = 0.0;
        for (int j = i; j < i + k; j++) {
            sum += nums[j];
        }
        maxAverage = std::max(maxAverage, sum / k);
    }
    return maxAverage;
}

// Optimal solution with O(n) complexity
double findMaxAverage(std::vector<int>& nums, int k) {
    double sum = std::accumulate(nums.begin(), nums.begin() + k, 0.0);
    double maxAverage = sum / k;
    for (int i = k; i < nums.size(); i++) {
        sum = sum - nums[i - k] + nums[i];
        maxAverage = std::max(maxAverage, sum / k);
    }
    return maxAverage;
}

int main() {
    std::vector<int> nums1 = {1, 12, -5, -6, 50, 3};
    int k1 = 4;
    std::cout << "Test case 1: " << findMaxAverage(nums1, k1) << std::endl;

    std::vector<int> nums2 = {5};
    int k2 = 1;
    std::cout << "Test case 2: " << findMaxAverage(nums2, k2) << std::endl;

    std::vector<int> nums3 = {0, 4, -3, -2, 0};
    int k3 = 3;
    std::cout << "Test case 3: " << findMaxAverage(nums3, k3) << std::endl;

    return 0;
}
```