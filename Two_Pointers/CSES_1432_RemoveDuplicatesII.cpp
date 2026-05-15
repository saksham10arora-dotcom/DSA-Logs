```cpp
// Problem: Remove Duplicates II, https://cses.fi/problemset/task/1432
// Brief description: Given a sorted array, remove duplicates such that each element appears at most twice.

// Brute force approach: Create a new array and copy elements from the original array, skipping duplicates (O(n^2) complexity)
// However, we can solve this problem more efficiently using a two-pointer approach.

#include <iostream>
#include <vector>

// Optimal solution: Use two pointers to track the position of the next non-duplicate element (O(n) complexity)
std::vector<int> removeDuplicates(std::vector<int>& nums) {
    if (nums.size() <= 2) {
        return nums;
    }

    int writeIndex = 2;
    for (int readIndex = 2; readIndex < nums.size(); ++readIndex) {
        if (nums[readIndex] != nums[writeIndex - 2]) {
            nums[writeIndex++] = nums[readIndex];
        }
    }

    nums.resize(writeIndex);
    return nums;
}

int main() {
    // Test case 1:
    std::vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    nums1 = removeDuplicates(nums1);
    for (int num : nums1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Test case 2:
    std::vector<int> nums2 = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    nums2 = removeDuplicates(nums2);
    for (int num : nums2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Test case 3:
    std::vector<int> nums3 = {1, 1, 1, 1, 1};
    nums3 = removeDuplicates(nums3);
    for (int num : nums3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```