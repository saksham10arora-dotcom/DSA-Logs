```cpp
// LeetCode problem 2192: Find Peak II I, https://leetcode.com/problems/find-peak-grid-ii/
// Given an integer matrix mat of size m x n, where every row is sorted in strictly increasing order and every column is sorted in strictly increasing order.
// Find the leftmost column that has at least one peak element.

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> findPeakGrid(std::vector<std::vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int low = 0;
        int high = n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = 0;
            for (int i = 1; i < m; i++) {
                if (mat[i][mid] > mat[row][mid]) {
                    row = i;
                }
            }
            if ((mid == 0 || mat[row][mid] > mat[row][mid - 1]) && (mid == n - 1 || mat[row][mid] > mat[row][mid + 1])) {
                return {row, mid};
            } else if (mid > 0 && mat[row][mid - 1] > mat[row][mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return {};
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> mat1 = {{1, 2}, {3, 4}};
    std::vector<int> result1 = solution.findPeakGrid(mat1);
    // Expected output: [1, 1]
    
    std::vector<std::vector<int>> mat2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    std::vector<int> result2 = solution.findPeakGrid(mat2);
    // Expected output: [2, 2]
    
    std::vector<std::vector<int>> mat3 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<int> result3 = solution.findPeakGrid(mat3);
    // Expected output: [2, 2]
    
    return 0;
}
```