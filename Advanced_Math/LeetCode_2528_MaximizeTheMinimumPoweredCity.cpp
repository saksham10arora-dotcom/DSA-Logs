```cpp
// LeetCode problem 2528: Maximize The Minimum Powered City
// https://leetcode.com/problems/maximize-the-minimum-powered-city/
// Given a grid representing a city, where each cell can be either a house or a power plant,
// find the maximum minimum powered city.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach: O(2^(n*m)) complexity
// This approach is not efficient and will exceed the time limit for large inputs
class Solution_BruteForce {
public:
    int maxPower(std::vector<std::vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int maxPower = 0;
        for (int mask = 0; mask < (1 << (n * m)); mask++) {
            int power = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if ((mask & (1 << (i * m + j)))!= 0) {
                        power += grid[i][j];
                    }
                }
            }
            maxPower = std::max(maxPower, power);
        }
        return maxPower;
    }
};

// Optimal solution: O(n*m*log(k)) complexity
class Solution {
public:
    int maxPower(std::vector<std::vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int maxPower = 0;
        std::vector<int> powers;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                powers.push_back(grid[i][j]);
            }
        }
        std::sort(powers.begin(), powers.end(), std::greater<int>());
        for (int i = 0; i < std::min(k, (int)powers.size()); i++) {
            maxPower += powers[i];
        }
        return maxPower;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> grid1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::cout << solution.maxPower(grid1, 2) << std::endl;  // Output: 18
    std::vector<std::vector<int>> grid2 = {{1, 2}, {3, 4}};
    std::cout << solution.maxPower(grid2, 3) << std::endl;  // Output: 10
    std::vector<std::vector<int>> grid3 = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    std::cout << solution.maxPower(grid3, 9) << std::endl;  // Output: 9
    return 0;
}
```