```cpp
// LeetCode problem 2643: Row With Maximum Ones, https://leetcode.com/problems/row-with-maximum-ones/
// Given a binary matrix mat of size m x n, find the row with the maximum number of ones and return the row index (0-indexed).

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach: O(m * n) complexity
int maxOnesRowBruteForce(std::vector<std::vector<int>>& mat) {
    int maxOnes = 0;
    int maxRowIndex = 0;
    for (int i = 0; i < mat.size(); i++) {
        int ones = 0;
        for (int j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] == 1) {
                ones++;
            }
        }
        if (ones > maxOnes) {
            maxOnes = ones;
            maxRowIndex = i;
        }
    }
    return maxRowIndex;
}

// Optimal solution: O(m * n) complexity
int maxOnesRowOptimal(std::vector<std::vector<int>>& mat) {
    int maxOnes = 0;
    int maxRowIndex = 0;
    for (int i = 0; i < mat.size(); i++) {
        int ones = std::count(mat[i].begin(), mat[i].end(), 1);
        if (ones > maxOnes) {
            maxOnes = ones;
            maxRowIndex = i;
        }
    }
    return maxRowIndex;
}

int main() {
    std::vector<std::vector<int>> mat1 = {{0,1,1,1},{0,0,1,0},{0,0,1,1},{0,0,0,1}};
    std::vector<std::vector<int>> mat2 = {{0,0,0},{0,0,0},{0,0,0}};
    std::vector<std::vector<int>> mat3 = {{1,1,1},{1,1,1},{1,1,1}};

    std::cout << maxOnesRowOptimal(mat1) << std::endl;  // Output: 0
    std::cout << maxOnesRowOptimal(mat2) << std::endl;  // Output: 0
    std::cout << maxOnesRowOptimal(mat3) << std::endl;  // Output: 0

    return 0;
}
```