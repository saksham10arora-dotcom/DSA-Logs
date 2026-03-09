```cpp
// Codeforces_693D_FindRightIntervalIII
// https://codeforces.com/contest/693/problem/D
// Given a set of intervals, find the right interval for each interval.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(n^2) complexity
std::vector<int> findRightIntervalBruteForce(std::vector<std::vector<int>>& intervals) {
    std::vector<int> result;
    for (int i = 0; i < intervals.size(); i++) {
        int minDiff = INT_MAX;
        int minIndex = -1;
        for (int j = 0; j < intervals.size(); j++) {
            if (intervals[j][0] >= intervals[i][1] && intervals[j][0] - intervals[i][1] < minDiff) {
                minDiff = intervals[j][0] - intervals[i][1];
                minIndex = j;
            }
        }
        result.push_back(minIndex);
    }
    return result;
}

// Optimal solution with O(n log n) complexity
std::vector<int> findRightInterval(std::vector<std::vector<int>>& intervals) {
    std::vector<std::pair<int, int>> starts;
    for (int i = 0; i < intervals.size(); i++) {
        starts.push_back({intervals[i][0], i});
    }
    std::sort(starts.begin(), starts.end());
    std::vector<int> result(intervals.size(), -1);
    for (int i = 0; i < intervals.size(); i++) {
        auto it = std::lower_bound(starts.begin(), starts.end(), std::make_pair(intervals[i][1], 0));
        if (it != starts.end()) {
            result[i] = it->second;
        }
    }
    return result;
}

int main() {
    std::vector<std::vector<int>> intervals1 = {{3, 4}, {2, 3}, {1, 2}, {4, 5}};
    std::vector<int> result1 = findRightInterval(intervals1);
    for (int i : result1) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::vector<std::vector<int>> intervals2 = {{1, 4}, {2, 3}, {3, 4}, {4, 5}};
    std::vector<int> result2 = findRightInterval(intervals2);
    for (int i : result2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::vector<std::vector<int>> intervals3 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    std::vector<int> result3 = findRightInterval(intervals3);
    for (int i : result3) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
```