```cpp
// LeetCode problem 1391: Check If There Is A Valid Path In A Grid
// https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/
// Given a grid with m x n cells, find if there is a path from the top-left cell to the bottom-right cell.

#include <vector>
#include <queue>
#include <unordered_set>

class Solution {
public:
    bool hasValidPath(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
        std::vector<std::pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        std::unordered_set<int> validConnections[4] = {
            {1, 4, 6},  // right
            {1, 3, 5},  // left
            {2, 5, 6},  // down
            {2, 3, 4}   // up
        };

        std::function<bool(int, int)> dfs = [&](int x, int y) {
            if (x == m - 1 && y == n - 1) return true;
            visited[x][y] = true;
            for (const auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) continue;
                if (validConnections[grid[x][y] - 1].count(grid[nx][ny])) {
                    if (dfs(nx, ny)) return true;
                }
            }
            return false;
        };

        return dfs(0, 0);
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> grid1 = {{2,4,3},{6,5,2},{1,1,2}};
    std::vector<std::vector<int>> grid2 = {{1,1,1},{1,0,1},{1,0,1}};
    std::vector<std::vector<int>> grid3 = {{1,1,1},{1,2,1},{1,2,1}};

    std::cout << std::boolalpha << solution.hasValidPath(grid1) << std::endl;  // true
    std::cout << std::boolalpha << solution.hasValidPath(grid2) << std::endl;  // false
    std::cout << std::boolalpha << solution.hasValidPath(grid3) << std::endl;  // false

    return 0;
}
```