```cpp
// LeetCode problem 3394: Check If Grid Can Be Cut Into Sections
// https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/
// Given a grid of size m x n, determine if it can be cut into sections such that each section has exactly one 1.

#include <iostream>
#include <vector>

// Brute force approach: O(2^(m*n)) complexity
// This approach involves trying all possible ways to cut the grid into sections
// However, this approach is inefficient and will exceed the time limit for large inputs

// Optimal solution: O(m*n) complexity
class Solution {
public:
    bool isPossibleToCutPath(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    count++;
                }
            }
        }
        return count == m * n;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> grid1 = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    std::vector<std::vector<int>> grid2 = {{1, 1, 0}, {1, 1, 0}, {1, 1, 0}};
    std::vector<std::vector<int>> grid3 = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};

    std::cout << std::boolalpha << solution.isPossibleToCutPath(grid1) << std::endl;  // Expected output: true
    std::cout << std::boolalpha << solution.isPossibleToCutPath(grid2) << std::endl;  // Expected output: false
    std::cout << std::boolalpha << solution.isPossibleToCutPath(grid3) << std::endl;  // Expected output: false

    return 0;
}
```