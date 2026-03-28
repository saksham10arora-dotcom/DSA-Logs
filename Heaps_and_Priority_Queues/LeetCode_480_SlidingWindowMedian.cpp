```cpp
// LeetCode problem 480: Sliding Window Median
// https://leetcode.com/problems/sliding-window-median/
// Find the median of each window of size k in the given array.

#include <queue>
#include <vector>
#include <algorithm>

class Solution {
public:
    // Brute force approach: O(n*k*log(k)) complexity
    std::vector<double> medianSlidingWindowBruteForce(std::vector<int>& nums, int k) {
        std::vector<double> medians;
        for (int i = 0; i <= nums.size() - k; i++) {
            std::vector<int> window(nums.begin() + i, nums.begin() + i + k);
            std::sort(window.begin(), window.end());
            if (k % 2 == 0) {
                medians.push_back((window[k / 2 - 1] + window[k / 2]) / 2.0);
            } else {
                medians.push_back(window[k / 2]);
            }
        }
        return medians;
    }

    // Optimal solution: O(n*log(k)) complexity
    std::vector<double> medianSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<double> medians;
        std::multiset<int> window;
        for (int i = 0; i < nums.size(); i++) {
            window.insert(nums[i]);
            if (i >= k) {
                window.erase(window.find(nums[i - k]));
            }
            if (i >= k - 1) {
                if (k % 2 == 0) {
                    auto it1 = window.begin();
                    std::advance(it1, k / 2 - 1);
                    auto it2 = window.begin();
                    std::advance(it2, k / 2);
                    medians.push_back((*it1 + *it2) / 2.0);
                } else {
                    auto it = window.begin();
                    std::advance(it, k / 2);
                    medians.push_back(*it);
                }
            }
        }
        return medians;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    std::vector<double> result1 = solution.medianSlidingWindow(nums1, 3);
    for (double num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> nums2 = {1, 2};
    std::vector<double> result2 = solution.medianSlidingWindow(nums2, 1);
    for (double num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> nums3 = {1, 3, -1, -3, 5, 3, 6, 7};
    std::vector<double> result3 = solution.medianSlidingWindow(nums3, 4);
    for (double num : result3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```