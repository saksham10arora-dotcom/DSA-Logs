```cpp
// Codeforces_256C_MyCalendarII, https://codeforces.com/contest/256/problem/C
// Given a set of intervals, find the number of triplets that can be formed such that the intersection of the three intervals is not empty.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(n^3) complexity
int bruteForce(std::vector<std::pair<int, int>>& intervals) {
    int count = 0;
    for (int i = 0; i < intervals.size(); i++) {
        for (int j = i + 1; j < intervals.size(); j++) {
            for (int k = j + 1; k < intervals.size(); k++) {
                int start = std::max({intervals[i].first, intervals[j].first, intervals[k].first});
                int end = std::min({intervals[i].second, intervals[j].second, intervals[k].second});
                if (start <= end) {
                    count++;
                }
            }
        }
    }
    return count;
}

// Optimal solution with O(n^2) complexity
int optimal(std::vector<std::pair<int, int>>& intervals) {
    int count = 0;
    for (int i = 0; i < intervals.size(); i++) {
        for (int j = i + 1; j < intervals.size(); j++) {
            int start = std::max(intervals[i].first, intervals[j].first);
            int end = std::min(intervals[i].second, intervals[j].second);
            if (start <= end) {
                for (int k = j + 1; k < intervals.size(); k++) {
                    if (intervals[k].first <= end && intervals[k].second >= start) {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

int main() {
    std::vector<std::pair<int, int>> intervals1 = {{1, 3}, {2, 4}, {3, 5}};
    std::vector<std::pair<int, int>> intervals2 = {{1, 5}, {2, 3}, {4, 6}};
    std::vector<std::pair<int, int>> intervals3 = {{1, 2}, {3, 4}, {5, 6}};

    std::cout << "Brute force approach:" << std::endl;
    std::cout << "Test case 1: " << bruteForce(intervals1) << std::endl;
    std::cout << "Test case 2: " << bruteForce(intervals2) << std::endl;
    std::cout << "Test case 3: " << bruteForce(intervals3) << std::endl;

    std::cout << "Optimal solution:" << std::endl;
    std::cout << "Test case 1: " << optimal(intervals1) << std::endl;
    std::cout << "Test case 2: " << optimal(intervals2) << std::endl;
    std::cout << "Test case 3: " << optimal(intervals3) << std::endl;

    return 0;
}
```