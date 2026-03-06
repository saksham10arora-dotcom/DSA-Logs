```cpp
// LeetCode problem 2740: Max Area Island
// https://leetcode.com/problems/max-area-island/
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), 
// return the size of the largest island.

#include <vector>
#include <queue>

// Brute force approach: O(m * n * m * n) complexity
class SolutionBruteForce {
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int area = dfs(grid, i, j);
                    maxArea = std::max(maxArea, area);
                }
            }
        }
        return maxArea;
    }

    int dfs(std::vector<std::vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return 0;
        }
        grid[i][j] = 0;
        return 1 + dfs(grid, i - 1, j) + dfs(grid, i + 1, j) + dfs(grid, i, j - 1) + dfs(grid, i, j + 1);
    }
};

// Optimal solution: O(m * n) complexity
class Solution {
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    maxArea = std::max(maxArea, dfs(grid, i, j));
                }
            }
        }
        return maxArea;
    }

    int dfs(std::vector<std::vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return 0;
        }
        grid[i][j] = 0;
        return 1 + dfs(grid, i - 1, j) + dfs(grid, i + 1, j) + dfs(grid, i, j - 1) + dfs(grid, i, j + 1);
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> grid1 = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                        {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                        {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                        {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                        {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                        {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                        {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                        {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    std::cout << solution.maxAreaOfIsland(grid1) << std::endl;  // Output: 6

    std::vector<std::vector<int>> grid2 = {{0,0,0,0,0,0,0,0}};
    std::cout << solution.maxAreaOfIsland(grid2) << std::endl;  // Output: 0

    std::vector<std::vector<int>> grid3 = {{1,1},
                                        {1,1}};
    std::cout << solution.maxAreaOfIsland(grid3) << std::endl;  // Output: 4

    return 0;
}
```