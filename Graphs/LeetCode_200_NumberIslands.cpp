/**
 * Problem: Number of Islands (LeetCode 200)
 * Link: https://leetcode.com/problems/number-of-islands/
 */

#include <iostream>
#include <vector>

using namespace std;

// --- Optimal Solution (DFS / Flood Fill) ---
// Time Complexity: O(M * N)
// Space Complexity: O(M * N) - worst case stack depth
void dfs(vector<vector<char>>& grid, int r, int c) {
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0') {
        return;
    }
    grid[r][c] = '0'; // mark as visited
    dfs(grid, r + 1, c);
    dfs(grid, r - 1, c);
    dfs(grid, r, c + 1);
    dfs(grid, r, c - 1);
}

int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, i, j);
            }
        }
    }
    return count;
}

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    cout << "Islands: " << numIslands(grid) << endl;
    return 0;
}




















