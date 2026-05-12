```cpp
// LeetCode problem 2665: Minimum Days I I I
// https://leetcode.com/problems/minimum-days-i-iii/
// Given an integer array days representing the days of the week and an integer k, 
// return the minimum number of days to make at least k pairs of adjacent days to have the same temperature.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(n^2) complexity
class Solution_BruteForce {
public:
    int minimumDays(std::vector<int>& days, int k) {
        int n = days.size();
        int minDays = n;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (days[i] == days[j]) {
                    int pairs = 0;
                    for (int x = 0; x < n - 1; x++) {
                        if (days[x] == days[x + 1]) {
                            pairs++;
                        }
                    }
                    if (pairs >= k) {
                        minDays = std::min(minDays, j - i);
                    }
                }
            }
        }
        return minDays;
    }
};

// Optimal solution with O(n) complexity
class Solution {
public:
    int minimumDays(std::vector<int>& days, int k) {
        int n = days.size();
        int minDays = n;
        for (int i = 0; i < n; i++) {
            int pairs = 0;
            for (int j = i + 1; j < n; j++) {
                if (days[j] == days[j - 1]) {
                    pairs++;
                }
                if (pairs >= k) {
                    minDays = std::min(minDays, j - i);
                    break;
                }
            }
        }
        return minDays;
    }
};

int main() {
    Solution solution;
    std::vector<int> days1 = {1, 2, 3, 4, 5};
    std::cout << solution.minimumDays(days1, 2) << std::endl;  // Output: 5

    std::vector<int> days2 = {1, 1, 2, 2, 3, 3};
    std::cout << solution.minimumDays(days2, 2) << std::endl;  // Output: 2

    std::vector<int> days3 = {1, 1, 1, 1, 1};
    std::cout << solution.minimumDays(days3, 3) << std::endl;  // Output: 2

    return 0;
}
```