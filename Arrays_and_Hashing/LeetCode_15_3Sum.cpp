```cpp
// LeetCode problem 15: 3 Sum
// https://leetcode.com/problems/3sum/
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(n^3) complexity
std::vector<std::vector<int>> threeSumBruteForce(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    std::vector<int> triplet = {nums[i], nums[j], nums[k]};
                    std::sort(triplet.begin(), triplet.end());
                    bool found = false;
                    for (const auto& res : result) {
                        if (res == triplet) {
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        result.push_back(triplet);
                    }
                }
            }
        }
    }
    return result;
}

// Optimal solution with O(n^2) complexity
std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum < 0) {
                left++;
            } else if (sum > 0) {
                right--;
            } else {
                result.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                left++;
                right--;
            }
        }
    }
    return result;
}

int main() {
    std::vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> result1 = threeSum(nums1);
    std::cout << "Result 1: ";
    for (const auto& triplet : result1) {
        std::cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "] ";
    }
    std::cout << std::endl;

    std::vector<int> nums2 = {0, 1, 1};
    std::vector<std::vector<int>> result2 = threeSum(nums2);
    std::cout << "Result 2: ";
    for (const auto& triplet : result2) {
        std::cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "] ";
    }
    std::cout << std::endl;

    std::vector<int> nums3 = {0, 0, 0};
    std::vector<std::vector<int>> result3 = threeSum(nums3);
    std::cout << "Result 3: ";
    for (const auto& triplet : result3) {
        std::cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "] ";
    }
    std::cout << std::endl;

    return 0;
}
```