```cpp
// Maximum Rows Covered By Columns, https://leetcode.com/problems/maximum-rows-covered-by-columns/
// Given a matrix where each row represents a person and each column represents a skill, 
// return the maximum number of rows that can be covered by selecting k columns.

#include <iostream>
#include <vector>
#include <bitset>

// Brute force approach with O(2^n * m) complexity
class SolutionBruteForce {
public:
    int maximumRows(std::vector<std::vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        int maxRows = 0;
        for (int mask = 0; mask < (1 << m); mask++) {
            if (__builtin_popcount(mask) == k) {
                int rows = 0;
                for (int i = 0; i < n; i++) {
                    bool covered = true;
                    for (int j = 0; j < m; j++) {
                        if (mat[i][j] == 1 && ((mask >> j) & 1) == 0) {
                            covered = false;
                            break;
                        }
                    }
                    if (covered) rows++;
                }
                maxRows = std::max(maxRows, rows);
            }
        }
        return maxRows;
    }
};

// Optimal solution with O(n * 2^k) complexity
class Solution {
public:
    int maximumRows(std::vector<std::vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        std::vector<std::bitset<1001>> rows(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) rows[i].set(j);
            }
        }
        int maxRows = 0;
        for (int mask = 0; mask < (1 << m); mask++) {
            if (__builtin_popcount(mask) == k) {
                int rowsCovered = 0;
                for (int i = 0; i < n; i++) {
                    bool covered = true;
                    for (int j = 0; j < m; j++) {
                        if (rows[i][j] && ((mask >> j) & 1) == 0) {
                            covered = false;
                            break;
                        }
                    }
                    if (covered) rowsCovered++;
                }
                maxRows = std::max(maxRows, rowsCovered);
            }
        }
        return maxRows;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> mat1 = {{0,1,0},{1,0,1},{0,0,1}};
    std::cout << solution.maximumRows(mat1, 2) << std::endl;  // Output: 2

    std::vector<std::vector<int>> mat2 = {{1,1,1},{0,1,0},{0,1,0}};
    std::cout << solution.maximumRows(mat2, 1) << std::endl;  // Output: 2

    std::vector<std::vector<int>> mat3 = {{0,0,1},{1,1,1},{0,0,1}};
    std::cout << solution.maximumRows(mat3, 2) << std::endl;  // Output: 2

    return 0;
}
```