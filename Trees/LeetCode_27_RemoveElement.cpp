```cpp
// Remove Element, https://leetcode.com/problems/remove-element/, Given an array nums and a value val, remove all instances of that value in-place and return the new length.

#include <vector>

class Solution {
public:
    // Brute force approach: O(n^2) due to shifting elements in the vector
    int removeElementBruteForce(std::vector<int>& nums, int val) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == val) {
                nums.erase(nums.begin() + i);
            } else {
                i++;
            }
        }
        return nums.size();
    }

    // Optimal solution: O(n) by using two pointers
    int removeElementOptimal(std::vector<int>& nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {3, 2, 2, 3};
    std::cout << solution.removeElementOptimal(nums1, 3) << std::endl;  // Output: 2
    for (int num : nums1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    std::cout << solution.removeElementOptimal(nums2, 2) << std::endl;  // Output: 5
    for (int num : nums2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> nums3 = {2, 2, 2, 2};
    std::cout << solution.removeElementOptimal(nums3, 2) << std::endl;  // Output: 0
    for (int num : nums3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```