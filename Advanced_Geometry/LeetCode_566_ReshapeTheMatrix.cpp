```cpp
// LeetCode problem 566: Reshape The Matrix, https://leetcode.com/problems/reshape-the-matrix/
// In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size
// Given a matrix, a new row number and a new column number, your task is to reshape the matrix.

#include <vector>
#include <iostream>

// Brute force approach with O(m*n) complexity
std::vector<std::vector<int>> matrixReshapeBruteForce(std::vector<std::vector<int>>& nums, int r, int c) {
    int m = nums.size();
    int n = nums[0].size();
    if (m * n != r * c) return nums;
    std::vector<std::vector<int>> result(r, std::vector<int>(c));
    int index = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[index / c][index % c] = nums[i][j];
            index++;
        }
    }
    return result;
}

// Optimal solution with O(m*n) complexity
std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& nums, int r, int c) {
    int m = nums.size();
    int n = nums[0].size();
    if (m * n != r * c) return nums;
    std::vector<std::vector<int>> result(r, std::vector<int>(c));
    int index = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[index / c][index % c] = nums[i][j];
            index++;
        }
    }
    return result;
}

int main() {
    std::vector<std::vector<int>> nums1 = {{1, 2}, {3, 4}};
    std::vector<std::vector<int>> result1 = matrixReshape(nums1, 1, 4);
    for (const auto& row : result1) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    std::vector<std::vector<int>> nums2 = {{1, 2}, {3, 4}};
    std::vector<std::vector<int>> result2 = matrixReshape(nums2, 2, 2);
    for (const auto& row : result2) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    std::vector<std::vector<int>> nums3 = {{1, 2, 3, 4}, {5, 6, 7, 8}};
    std::vector<std::vector<int>> result3 = matrixReshape(nums3, 4, 2);
    for (const auto& row : result3) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```