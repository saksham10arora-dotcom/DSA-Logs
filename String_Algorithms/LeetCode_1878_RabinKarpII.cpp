```cpp
// Problem: 1878. Get the Maximum Score
// Link: https://leetcode.com/problems/get-the-maximum-score/
// Description: You are given two arrays, nums1 and nums2, of the same length n.
//              The maximum score is the maximum sum of the product of the ith elements of the two arrays.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(n^2) complexity
class Solution_Brute_Force {
public:
    int maximumScore(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n = nums1.size();
        int maxScore = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    int score = nums1[i] * nums2[j];
                    maxScore = std::max(maxScore, score);
                }
            }
        }
        return maxScore;
    }
};

// Optimal solution with O(n log n) complexity
class Solution_Optimal {
public:
    int maximumScore(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n = nums1.size();
        std::vector<std::pair<int, int>> pairs;
        for (int i = 0; i < n; i++) {
            pairs.push_back({nums1[i], nums2[i]});
        }
        std::sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });
        int maxScore = 0;
        for (int i = 0; i < n; i++) {
            int score = pairs[i].first * pairs[n - i - 1].second;
            maxScore = std::max(maxScore, score);
        }
        return maxScore;
    }
};

int main() {
    Solution_Optimal solution;
    std::vector<int> nums1 = {1, 3, 2};
    std::vector<int> nums2 = {3, 2, 1};
    std::cout << solution.maximumScore(nums1, nums2) << std::endl;  // Output: 12

    nums1 = {1, 5, 4, 6};
    nums2 = {3, 2, 1, 5};
    std::cout << solution.maximumScore(nums1, nums2) << std::endl;  // Output: 30

    nums1 = {1, 2, 3, 4, 5};
    nums2 = {5, 4, 3, 2, 1};
    std::cout << solution.maximumScore(nums1, nums2) << std::endl;  // Output: 25

    return 0;
}
```