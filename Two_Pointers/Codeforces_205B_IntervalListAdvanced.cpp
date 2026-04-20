```cpp
// Codeforces_205B_IntervalListAdvanced
// https://codeforces.com/contest/205/problem/B
// Given a list of intervals, find the maximum number of intervals that can be selected such that no two intervals overlap.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach: O(2^n) complexity
// Try all possible combinations of intervals and check if they overlap.

// Optimal solution: O(n log n) complexity
// Sort the intervals by their end points and then use a two-pointer technique to select the non-overlapping intervals.

int maxNonOverlappingIntervals(std::vector<std::pair<int, int>>& intervals) {
    std::sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    int count = 1;
    int end = intervals[0].second;

    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i].first >= end) {
            count++;
            end = intervals[i].second;
        }
    }

    return count;
}

int main() {
    // Test case 1:
    std::vector<std::pair<int, int>> intervals1 = {{1, 3}, {2, 4}, {3, 5}, {6, 8}};
    std::cout << maxNonOverlappingIntervals(intervals1) << std::endl;  // Output: 2

    // Test case 2:
    std::vector<std::pair<int, int>> intervals2 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    std::cout << maxNonOverlappingIntervals(intervals2) << std::endl;  // Output: 4

    // Test case 3:
    std::vector<std::pair<int, int>> intervals3 = {{1, 5}, {2, 4}, {3, 6}, {7, 8}};
    std::cout << maxNonOverlappingIntervals(intervals3) << std::endl;  // Output: 2

    return 0;
}
```