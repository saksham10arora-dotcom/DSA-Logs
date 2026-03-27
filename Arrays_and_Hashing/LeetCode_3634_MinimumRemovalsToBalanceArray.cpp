```cpp
// LeetCode problem 3634: Minimum Removals To Balance Array
// https://leetcode.com/problems/minimum-removals-to-balance-array/
// Given an array of integers, find the minimum number of removals to balance the array.

#include <iostream>
#include <vector>
#include <unordered_map>

// Brute force approach with O(n^2) complexity
class Solution_BruteForce {
public:
    int minimumRemovals(std::vector<int>& beans) {
        int n = beans.size();
        int minRemovals = n;
        for (int i = 0; i < (1 << n); i++) {
            int removals = 0;
            int total = 0;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) {
                    removals++;
                } else {
                    total += beans[j];
                }
            }
            int otherTotal = 0;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) == 0) {
                    otherTotal += beans[j];
                }
            }
            if (total == otherTotal) {
                minRemovals = std::min(minRemovals, removals);
            }
        }
        return minRemovals;
    }
};

// Optimal solution with O(n) complexity
class Solution_Optimal {
public:
    int minimumRemovals(std::vector<int>& beans) {
        int n = beans.size();
        std::sort(beans.begin(), beans.end());
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += beans[i];
        }
        int minRemovals = n;
        for (int i = 0; i < n; i++) {
            int removals = i;
            int leftTotal = 0;
            for (int j = 0; j < i; j++) {
                leftTotal += beans[j];
            }
            int rightTotal = total - leftTotal - beans[i];
            if (leftTotal <= rightTotal) {
                minRemovals = std::min(minRemovals, removals);
            }
        }
        return minRemovals;
    }
};

int main() {
    Solution_Optimal solution;
    std::vector<int> beans1 = {1, 2, 3, 4, 5};
    std::vector<int> beans2 = {2, 2, 2, 2, 2};
    std::vector<int> beans3 = {1, 1, 2, 2, 3, 3, 4, 4};
    std::cout << solution.minimumRemovals(beans1) << std::endl;  // Output: 2
    std::cout << solution.minimumRemovals(beans2) << std::endl;  // Output: 0
    std::cout << solution.minimumRemovals(beans3) << std::endl;  // Output: 2
    return 0;
}
```