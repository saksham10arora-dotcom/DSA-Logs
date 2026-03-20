```cpp
// Search In Rotated Sorted Array, https://leetcode.com/problems/search-in-rotated-sorted-array/
// Given the sorted rotated array nums of unique elements, return the index of the target element if it is present in the array, otherwise return -1.

#include <vector>
#include <iostream>

// Brute force approach with O(n) complexity
class SolutionBrute {
public:
    int search(std::vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
};

// Optimal solution with O(log n) complexity
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    std::cout << solution.search(nums1, 0) << std::endl;  // Output: 4
    std::vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    std::cout << solution.search(nums2, 3) << std::endl;  // Output: -1
    std::vector<int> nums3 = {1};
    std::cout << solution.search(nums3, 0) << std::endl;  // Output: -1
    return 0;
}
```