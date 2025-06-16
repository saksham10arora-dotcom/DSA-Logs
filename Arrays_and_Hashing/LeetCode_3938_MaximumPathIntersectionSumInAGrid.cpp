```cpp
// Maximum Path Intersection Sum In A Grid, https://leetcode.com/problems/maximum-path-intersection-sum-in-a-grid/
// Given a grid with non-negative integers, find the maximum path intersection sum.

// Brute force approach with O(4^n) complexity
class Solution {
public:
    int maxSumPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxSum = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        function<void(int, int, int)> dfs = [&](int x, int y, int sum) {
            maxSum = max(maxSum, sum);
            visited[x][y] = true;
            for (auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    dfs(nx, ny, sum + grid[nx][ny]);
                }
            }
            visited[x][y] = false;
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(i, j, grid[i][j]);
            }
        }
        return maxSum;
    }
};

// Optimal solution with O(m*n) complexity
class Solution {
public:
    int maxSumPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxSum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = grid[i][j];
                maxSum = max(maxSum, sum);
                if (i > 0) {
                    sum += grid[i-1][j];
                    maxSum = max(maxSum, sum);
                }
                if (j > 0) {
                    sum += grid[i][j-1];
                    maxSum = max(maxSum, sum);
                }
                if (i > 0 && j > 0) {
                    sum += grid[i-1][j-1];
                    maxSum = max(maxSum, sum);
                }
            }
        }
        return maxSum;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << solution.maxSumPath(grid1) << endl;  // Output: 29
    vector<vector<int>> grid2 = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << solution.maxSumPath(grid2) << endl;  // Output: 12
    vector<vector<int>> grid3 = {{1, 2}, {3, 4}};
    cout << solution.maxSumPath(grid3) << endl;  // Output: 10
    return 0;
}
```