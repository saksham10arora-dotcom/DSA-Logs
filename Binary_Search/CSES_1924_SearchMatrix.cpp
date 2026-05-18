```cpp
// Problem: Search Matrix
// Link: https://cses.fi/problemset/task/1924
// Description: Search for an element in a sorted matrix.

#include <iostream>
#include <vector>

// Brute force approach with O(n*m) complexity
bool searchMatrixBruteForce(const std::vector<std::vector<int>>& matrix, int target) {
    for (const auto& row : matrix) {
        for (int num : row) {
            if (num == target) {
                return true;
            }
        }
    }
    return false;
}

// Optimal solution with O(m + n) complexity
bool searchMatrixOptimal(const std::vector<std::vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
        return false;
    }

    int row = 0;
    int col = matrix[0].size() - 1;

    while (row < matrix.size() && col >= 0) {
        if (matrix[row][col] == target) {
            return true;
        } else if (matrix[row][col] < target) {
            row++;
        } else {
            col--;
        }
    }

    return false;
}

int main() {
    // Test case 1
    std::vector<std::vector<int>> matrix1 = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    std::cout << std::boolalpha << searchMatrixOptimal(matrix1, 5) << std::endl;  // Expected output: true
    std::cout << std::boolalpha << searchMatrixOptimal(matrix1, 20) << std::endl; // Expected output: false

    // Test case 2
    std::vector<std::vector<int>> matrix2 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    std::cout << std::boolalpha << searchMatrixOptimal(matrix2, 3) << std::endl;  // Expected output: true
    std::cout << std::boolalpha << searchMatrixOptimal(matrix2, 13) << std::endl; // Expected output: false

    // Test case 3
    std::vector<std::vector<int>> matrix3 = {{1}, {3}, {5}, {7}, {9}, {11}};
    std::cout << std::boolalpha << searchMatrixOptimal(matrix3, 9) << std::endl;  // Expected output: true
    std::cout << std::boolalpha << searchMatrixOptimal(matrix3, 10) << std::endl; // Expected output: false

    return 0;
}
```