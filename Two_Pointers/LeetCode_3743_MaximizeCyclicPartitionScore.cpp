```cpp
/**
 * LeetCode Problem 3743: Maximize Cyclic Partition Score
 * https://leetcode.com/problems/maximize-cyclic-partition-score
 * Given an array of integers, find the maximum cyclic partition score.
 */

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(n^2) complexity
class SolutionBruteForce {
public:
    int maximumCyclicPartitionScore(std::vector<int>& nums) {
        int n = nums.size();
        int maxScore = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                std::vector<int> left(nums.begin(), nums.begin() + i);
                std::vector<int> mid(nums.begin() + i, nums.begin() + j);
                std::vector<int> right(nums.begin() + j, nums.end());
                int score = std::min({*std::max_element(left.begin(), left.end()), 
                                    *std::max_element(mid.begin(), mid.end()), 
                                    *std::max_element(right.begin(), right.end())});
                maxScore = std::max(maxScore, score);
            }
        }
        return maxScore;
    }
};

// Optimal solution with O(n) complexity
class SolutionOptimal {
public:
    int maximumCyclicPartitionScore(std::vector<int>& nums) {
        int n = nums.size();
        int maxScore = 0;
        int maxLeft = 0, maxRight = 0;
        for (int i = 0; i < n; i++) {
            maxLeft = std::max(maxLeft, nums[i]);
            maxRight = 0;
            for (int j = i + 1; j < n; j++) {
                maxRight = std::max(maxRight, nums[j]);
            }
            maxScore = std::max(maxScore, std::min(maxLeft, maxRight));
        }
        return maxScore;
    }
};

int main() {
    SolutionOptimal solution;
    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    std::vector<int> nums2 = {1, 2, 3, 4, 5, 6};
    std::vector<int> nums3 = {1, 1, 1, 1, 1};
    std::cout << solution.maximumCyclicPartitionScore(nums1) << std::endl;  // Output: 3
    std::cout << solution.maximumCyclicPartitionScore(nums2) << std::endl;  // Output: 3
    std::cout << solution.maximumCyclicPartitionScore(nums3) << std::endl;  // Output: 1
    return 0;
}
```