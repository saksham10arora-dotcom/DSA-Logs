```cpp
// LeetCode problem 2406: Divide Intervals Into Minimum Number Of Groups
// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/
// Given a list of intervals, divide them into the minimum number of groups such that no two intervals in the same group overlap.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach: Try all possible groupings and check for overlap (O(2^n * n^2))
class Solution_BruteForce {
public:
    int minGroups(std::vector<std::vector<int>>& intervals) {
        int n = intervals.size();
        int ans = n;
        for (int mask = 0; mask < (1 << n); mask++) {
            std::vector<std::vector<int>> groups;
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i))!= 0) {
                    bool found = false;
                    for (auto& group : groups) {
                        bool overlap = false;
                        for (auto& interval : group) {
                            if (intervals[i][0] < interval[1] && intervals[i][1] > interval[0]) {
                                overlap = true;
                                break;
                            }
                        }
                        if (!overlap) {
                            group.push_back(intervals[i]);
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        groups.push_back({intervals[i]});
                    }
                }
            }
            ans = std::min(ans, (int)groups.size());
        }
        return ans;
    }
};

// Optimal solution: Sort intervals by end time and use a priority queue to keep track of the end times of the groups (O(n log n))
class Solution {
public:
    int minGroups(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });
        std::vector<int> endTimes;
        for (const auto& interval : intervals) {
            auto it = std::lower_bound(endTimes.begin(), endTimes.end(), interval[0]);
            if (it == endTimes.end()) {
                endTimes.push_back(interval[1]);
            } else {
                *it = interval[1];
            }
        }
        return endTimes.size();
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> intervals1 = {{5, 10}, {6, 8}, {1, 5}, {2, 3}, {1, 10}};
    std::cout << solution.minGroups(intervals1) << std::endl;  // Output: 3

    std::vector<std::vector<int>> intervals2 = {{1, 3}, {2, 4}, {5, 6}, {7, 8}};
    std::cout << solution.minGroups(intervals2) << std::endl;  // Output: 2

    std::vector<std::vector<int>> intervals3 = {{1, 10}, {2, 3}, {3, 4}, {4, 5}};
    std::cout << solution.minGroups(intervals3) << std::endl;  // Output: 1

    return 0;
}
```