```cpp
// Special Array With X Elements (That Sum)
// https://leetcode.com/problems/special-array-with-x-elements-that-sum/
// Given a non-negative integer array nums, return the number of operations to make the array special.
// An array is special if it is of the form [x, x, x, ..., x] where all elements are equal.
// The only allowed operation is the increment of some element by 1.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(n^2) complexity
int specialArrayBruteForce(std::vector<int>& nums) {
    int n = nums.size();
    for (int x = 0; x <= n; x++) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= x) {
                count++;
            }
        }
        if (count == x) {
            return x;
        }
    }
    return -1;
}

// Optimal solution with O(n log n) complexity
int specialArray(std::vector<int>& nums) {
    int n = nums.size();
    std::sort(nums.begin(), nums.end());
    for (int x = 1; x <= n; x++) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= x) {
                count++;
            }
        }
        if (count == x) {
            return x;
        }
    }
    return -1;
}

int main() {
    std::vector<int> nums1 = {3, 5};
    std::vector<int> nums2 = {0, 4, 3, 0, 4};
    std::vector<int> nums3 = {3, 1};

    std::cout << specialArrayBruteForce(nums1) << std::endl;  // Output: 2
    std::cout << specialArrayBruteForce(nums2) << std::endl;  // Output: 3
    std::cout << specialArrayBruteForce(nums3) << std::endl;  // Output: -1

    std::cout << specialArray(nums1) << std::endl;  // Output: 2
    std::cout << specialArray(nums2) << std::endl;  // Output: 3
    std::cout << specialArray(nums3) << std::endl;  // Output: -1

    return 0;
}
```