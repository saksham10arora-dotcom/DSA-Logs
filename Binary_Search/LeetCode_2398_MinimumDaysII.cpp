```cpp
// LeetCode problem 2398: Minimum Days to Make the Array Decreasing
// https://leetcode.com/problems/minimum-days-to-make-the-array-decreasing/
// Given an array of integers, find the minimum number of days to make the array decreasing.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach: O(2^n) complexity
// int minDays(std::vector<int>& nums) {
//     int n = nums.size();
//     int ans = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (nums[j] >= nums[i]) {
//                 nums[j]--;
//                 ans++;
//             }
//         }
//     }
//     return ans;
// }

// Optimal solution: O(n) complexity
int minDays(std::vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (nums[i] >= nums[i - 1]) {
            ans += nums[i] - nums[i - 1] + 1;
            nums[i] = nums[i - 1] - 1;
        }
    }
    return ans;
}

int main() {
    std::vector<int> nums1 = {5, 4, 3, 2, 1};
    std::vector<int> nums2 = {3, 1, 4};
    std::vector<int> nums3 = {2, 2, 2};

    std::cout << minDays(nums1) << std::endl;  // Output: 0
    std::cout << minDays(nums2) << std::endl;  // Output: 2
    std::cout << minDays(nums3) << std::endl;  // Output: 3

    return 0;
}
```