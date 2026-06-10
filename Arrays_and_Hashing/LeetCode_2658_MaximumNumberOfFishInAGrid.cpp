```cpp
// LeetCode problem 2658: Maximum Number Of Fish In A Grid
// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/
// Given a grid representing a fishing net, find the maximum number of fish that can be caught.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach: try all possible paths and count the number of fish in each path
// O(2^(m*n)) complexity, where m and n are the dimensions of the grid
class Solution_BruteForce {
public:
    int maxNumberofFish(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxFish = 0;
        for (int mask = 0; mask < (1 << (m * n)); mask++) {
            int fish = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if ((mask & (1 << (i * n + j))) && grid[i][j] == 1) {
                        fish++;
                    }
                }
            }
            maxFish = std::max(maxFish, fish);
        }
        return maxFish;
    }
};

// Optimal solution: use a depth-first search to find the maximum number of fish in a connected component
// O(m*n) complexity, where m and n are the dimensions of the grid
class Solution {
public:
    int maxNumberofFish(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxFish = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int fish = dfs(grid, i, j);
                    maxFish = std::max(maxFish, fish);
                }
            }
        }
        return maxFish;
    }

    int dfs(std::vector<std::vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) {
            return 0;
        }
        grid[i][j] = 0; // mark as visited
        int fish = 1;
        fish += dfs(grid, i - 1, j); // up
        fish += dfs(grid, i + 1, j); // down
        fish += dfs(grid, i, j - 1); // left
        fish += dfs(grid, i, j + 1); // right
        return fish;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> grid1 = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    std::cout << solution.maxNumberofFish(grid1) << std::endl; // output: 1

    std::vector<std::vector<int>> grid2 = {{1, 1, 0}, {0, 1, 0}, {0, 0, 1}};
    std::cout << solution.maxNumberofFish(grid2) << std::endl; // output: 2

    std::vector<std::vector<int>> grid3 = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    std::cout << solution.maxNumberofFish(grid3) << std::endl; // output: 9

    return 0;
}
```