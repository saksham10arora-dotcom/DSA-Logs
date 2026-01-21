```cpp
// LeetCode problem 26: Remove Duplicates From Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Given a sorted array, remove the duplicates in-place such that each element appears only once and return the new length.

#include <iostream>
#include <vector>

// Brute force approach: sorting the array and then removing duplicates (O(n log n) time complexity)
// int removeDuplicates(std::vector<int>& nums) {
//     std::sort(nums.begin(), nums.end());
//     nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
//     return nums.size();
// }

// Optimal solution: two pointers (O(n) time complexity)
int removeDuplicates(std::vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}

int main() {
    std::vector<int> test1 = {1, 1, 2};
    std::cout << "Test case 1: " << removeDuplicates(test1) << std::endl;
    for (int i = 0; i < test1.size(); i++) {
        std::cout << test1[i] << " ";
    }
    std::cout << std::endl;

    std::vector<int> test2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    std::cout << "Test case 2: " << removeDuplicates(test2) << std::endl;
    for (int i = 0; i < test2.size(); i++) {
        std::cout << test2[i] << " ";
    }
    std::cout << std::endl;

    std::vector<int> test3 = {1, 1, 1, 1, 1};
    std::cout << "Test case 3: " << removeDuplicates(test3) << std::endl;
    for (int i = 0; i < test3.size(); i++) {
        std::cout << test3[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```