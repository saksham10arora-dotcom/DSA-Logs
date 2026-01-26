```cpp
// LeetCode problem 220: Contains Duplicate III, https://leetcode.com/problems/contains-duplicate-iii/
// Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most k and the absolute difference between i and j is at most t.

#include <iostream>
#include <vector>
#include <set>

// Brute force approach: O(n^2) complexity
bool containsNearbyAlmostDuplicateBruteForce(std::vector<int>& nums, int k, int t) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (j - i <= t && std::abs(nums[i] - nums[j]) <= k) {
                return true;
            }
        }
    }
    return false;
}

// Optimal solution: O(n) complexity
bool containsNearbyAlmostDuplicateOptimal(std::vector<int>& nums, int k, int t) {
    std::set<long long> window;
    for (int i = 0; i < nums.size(); i++) {
        if (i > t) {
            window.erase(nums[i - t - 1]);
        }
        for (auto it = window.lower_bound((long long)nums[i] - k); it != window.end() && *it <= (long long)nums[i] + k; it++) {
            if (std::abs(nums[i] - *it) <= k) {
                return true;
            }
        }
        window.insert(nums[i]);
    }
    return false;
}

int main() {
    std::vector<int> nums1 = {1, 2, 3, 1};
    int k1 = 3;
    int t1 = 2;
    std::cout << std::boolalpha << containsNearbyAlmostDuplicateOptimal(nums1, k1, t1) << std::endl;  // Output: true

    std::vector<int> nums2 = {1, 0, 1, 1};
    int k2 = 1;
    int t2 = 2;
    std::cout << std::boolalpha << containsNearbyAlmostDuplicateOptimal(nums2, k2, t2) << std::endl;  // Output: true

    std::vector<int> nums3 = {1, 5, 9, 1, 5, 9};
    int k3 = 2;
    int t3 = 3;
    std::cout << std::boolalpha << containsNearbyAlmostDuplicateOptimal(nums3, k3, t3) << std::endl;  // Output: false

    return 0;
}
```