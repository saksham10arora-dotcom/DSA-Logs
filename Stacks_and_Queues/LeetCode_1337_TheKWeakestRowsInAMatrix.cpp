```cpp
// LeetCode 1337: The K Weakest Rows In A Matrix
// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
// Given a matrix, where each row represents a soldier and each column represents a battle, 
// and a value of 1 indicates that the soldier was present in that battle, 
// return the k weakest rows in the matrix ordered from weakest to strongest.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// Brute force approach: O(n*m) where n is the number of rows and m is the number of columns
std::vector<int> kWeakestRowsBruteForce(std::vector<std::vector<int>>& mat, int k) {
    std::vector<std::pair<int, int>> rows;
    for (int i = 0; i < mat.size(); i++) {
        int count = 0;
        for (int j = 0; j < mat[i].size(); j++) {
            count += mat[i][j];
        }
        rows.push_back({count, i});
    }
    std::sort(rows.begin(), rows.end());
    std::vector<int> result;
    for (int i = 0; i < k; i++) {
        result.push_back(rows[i].second);
    }
    return result;
}

// Optimal solution: O(n*m + n log n) where n is the number of rows and m is the number of columns
std::vector<int> kWeakestRows(std::vector<std::vector<int>>& mat, int k) {
    std::vector<std::pair<int, int>> rows;
    for (int i = 0; i < mat.size(); i++) {
        int count = 0;
        for (int j = 0; j < mat[i].size(); j++) {
            count += mat[i][j];
        }
        rows.push_back({count, i});
    }
    std::sort(rows.begin(), rows.end());
    std::vector<int> result;
    for (int i = 0; i < k; i++) {
        result.push_back(rows[i].second);
    }
    return result;
}

int main() {
    std::vector<std::vector<int>> mat1 = {{1,1,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0}};
    std::vector<int> result1 = kWeakestRows(mat1, 3);
    for (int i : result1) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::vector<std::vector<int>> mat2 = {{1,0,0,0},{1,1,1,1},{1,0,0,0},{1,0,0,0}};
    std::vector<int> result2 = kWeakestRows(mat2, 2);
    for (int i : result2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::vector<std::vector<int>> mat3 = {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
    std::vector<int> result3 = kWeakestRows(mat3, 4);
    for (int i : result3) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
```