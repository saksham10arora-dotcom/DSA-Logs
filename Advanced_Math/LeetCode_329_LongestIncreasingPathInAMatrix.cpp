```cpp
// LeetCode problem 329: Longest Increasing Path In A Matrix
// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
// Given an integer matrix, find the length of the longest increasing path.

#include <vector>
#include <algorithm>

class Solution {
public:
    int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        std::vector<std::vector<int>> memo(rows, std::vector<int>(cols, 0));
        int maxLen = 0;
        
        std::vector<std::pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                maxLen = std::max(maxLen, dfs(matrix, i, j, memo, directions));
            }
        }
        
        return maxLen;
    }
    
    int dfs(const std::vector<std::vector<int>>& matrix, int i, int j, std::vector<std::vector<int>>& memo, const std::vector<std::pair<int, int>>& directions) {
        if (memo[i][j] != 0) return memo[i][j];
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxLen = 1;
        
        for (const auto& dir : directions) {
            int x = i + dir.first;
            int y = j + dir.second;
            
            if (x >= 0 && x < rows && y >= 0 && y < cols && matrix[x][y] > matrix[i][j]) {
                maxLen = std::max(maxLen, 1 + dfs(matrix, x, y, memo, directions));
            }
        }
        
        memo[i][j] = maxLen;
        return maxLen;
    }
};

int main() {
    Solution solution;
    
    // Test case 1:
    std::vector<std::vector<int>> matrix1 = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };
    std::cout << solution.longestIncreasingPath(matrix1) << std::endl;  // Output: 4
    
    // Test case 2:
    std::vector<std::vector<int>> matrix2 = {
        {3, 4, 5},
        {3, 2, 6},
        {2, 2, 1}
    };
    std::cout << solution.longestIncreasingPath(matrix2) << std::endl;  // Output: 4
    
    // Test case 3:
    std::vector<std::vector<int>> matrix3 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::cout << solution.longestIncreasingPath(matrix3) << std::endl;  // Output: 5
    
    return 0;
}
```