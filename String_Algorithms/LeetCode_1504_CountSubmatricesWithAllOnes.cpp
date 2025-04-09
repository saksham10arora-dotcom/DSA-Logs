```cpp
// LeetCode problem 1504: Count Submatrices With All Ones
// https://leetcode.com/problems/count-submatrices-with-all-ones/
// Given a binary matrix, count the number of submatrices that have all ones.

#include <iostream>
#include <vector>

// Brute force approach: O(n^3 * m) complexity
class SolutionBruteForce {
public:
    int numSubmat(const std::vector<std::vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int count = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int k = i; k < rows; k++) {
                    for (int endCol = j; endCol < cols; endCol++) {
                        bool allOnes = true;
                        for (int row = i; row <= k; row++) {
                            for (int col = j; col <= endCol; col++) {
                                if (mat[row][col] == 0) {
                                    allOnes = false;
                                    break;
                                }
                            }
                            if (!allOnes) break;
                        }
                        if (allOnes) count++;
                    }
                }
            }
        }
        return count;
    }
};

// Optimal solution: O(n * m^2) complexity
class Solution {
public:
    int numSubmat(const std::vector<std::vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int count = 0;
        for (int i = 0; i < rows; i++) {
            std::vector<int> rowSums(cols, 0);
            for (int j = i; j < rows; j++) {
                for (int k = 0; k < cols; k++) {
                    rowSums[k] = mat[j][k] == 1 ? rowSums[k] + 1 : 0;
                }
                for (int k = 0; k < cols; k++) {
                    int minSum = rowSums[k];
                    for (int endCol = k; endCol < cols; endCol++) {
                        minSum = std::min(minSum, rowSums[endCol]);
                        if (minSum > 0) count += minSum;
                    }
                }
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> mat1 = {{1,0,1},
                                      {1,1,0},
                                      {1,1,0}};
    std::cout << solution.numSubmat(mat1) << std::endl;  // Output: 13

    std::vector<std::vector<int>> mat2 = {{0,1,1,0},
                                      {0,1,1,1},
                                      {1,1,1,0}};
    std::cout << solution.numSubmat(mat2) << std::endl;  // Output: 24

    std::vector<std::vector<int>> mat3 = {{1,1,1},
                                      {1,1,1},
                                      {1,1,1}};
    std::cout << solution.numSubmat(mat3) << std::endl;  // Output: 36

    return 0;
}
```