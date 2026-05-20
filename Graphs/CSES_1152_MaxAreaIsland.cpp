```cpp
// Problem: Max Area Island
// Link: https://cses.fi/problemset/task/1152
// Description: Given a grid of 0s and 1s, find the maximum area of an island.

#include <iostream>
#include <vector>

// Brute force approach: O(n*m*4^n*m) - checking all possible paths
// int maxArea(std::vector<std::vector<int>>& grid) {
//     int maxArea = 0;
//     for (int i = 0; i < grid.size(); i++) {
//         for (int j = 0; j < grid[0].size(); j++) {
//             if (grid[i][j] == 1) {
//                 maxArea = std::max(maxArea, dfs(grid, i, j));
//             }
//         }
//     }
//     return maxArea;
// }

// Optimal solution: O(n*m) - using DFS to explore the grid
int maxArea(std::vector<std::vector<int>>& grid) {
    if (grid.empty()) return 0;
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
    grid[i][j] = 0; // mark as visited
    return 1 + dfs(grid, i - 1, j) + dfs(grid, i + 1, j) + dfs(grid, i, j - 1) + dfs(grid, i, j + 1);
}

int main() {
    // Test case 1:
    std::vector<std::vector<int>> grid1 = {
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}
    };
    std::cout << maxArea(grid1) << std::endl; // Output: 6

    // Test case 2:
    std::vector<std::vector<int>> grid2 = {
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1}
    };
    std::cout << maxArea(grid2) << std::endl; // Output: 25

    // Test case 3:
    std::vector<std::vector<int>> grid3 = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    std::cout << maxArea(grid3) << std::endl; // Output: 0

    return 0;
}
```