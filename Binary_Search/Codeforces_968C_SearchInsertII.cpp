```cpp
// Codeforces_968C_SearchInsertII
// https://codeforces.com/contest/968/problem/C
// Given a sorted array and a target value, return the index if the target is found.
// If not, return the index where it would be if it were inserted in order.

#include <iostream>
#include <vector>

// Brute force approach with O(n) complexity
int searchInsertBruteForce(std::vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] >= target) {
            return i;
        }
    }
    return nums.size();
}

// Optimal solution with O(log n) complexity
int searchInsertOptimal(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int main() {
    std::vector<int> nums1 = {1, 3, 5, 6};
    int target1 = 5;
    std::cout << "Test case 1: " << searchInsertOptimal(nums1, target1) << std::endl;

    std::vector<int> nums2 = {1, 3, 5, 6};
    int target2 = 2;
    std::cout << "Test case 2: " << searchInsertOptimal(nums2, target2) << std::endl;

    std::vector<int> nums3 = {1, 3, 5, 6};
    int target3 = 7;
    std::cout << "Test case 3: " << searchInsertOptimal(nums3, target3) << std::endl;

    return 0;
}
```