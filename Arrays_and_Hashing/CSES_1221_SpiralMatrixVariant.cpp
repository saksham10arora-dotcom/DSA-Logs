```cpp
// Problem: Spiral Matrix Variant, https://cses.fi/problemset/task/1221
// Brief description: Given a matrix of size n x m, fill it with numbers from 1 to n*m in a spiral order.

#include <iostream>
#include <vector>

// Brute force approach with O(n*m) complexity
void bruteForceSpiral(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = m - 1;
    int count = 1;

    while (top <= bottom && left <= right) {
        // Fill from left to right
        for (int i = left; i <= right; i++) {
            matrix[top][i] = count++;
        }
        top++;

        // Fill from top to bottom
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = count++;
        }
        right--;

        // Fill from right to left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = count++;
            }
            bottom--;
        }

        // Fill from bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = count++;
            }
            left++;
        }
    }
}

// Optimal solution with O(n*m) complexity
void optimalSpiral(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = m - 1;
    int count = 1;

    while (top <= bottom && left <= right) {
        // Fill from left to right
        for (int i = left; i <= right; i++) {
            matrix[top][i] = count++;
        }
        top++;

        // Fill from top to bottom
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = count++;
        }
        right--;

        // Fill from right to left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = count++;
            }
            bottom--;
        }

        // Fill from bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = count++;
            }
            left++;
        }
    }
}

int main() {
    // Test case 1
    std::vector<std::vector<int>> matrix1 = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    optimalSpiral(matrix1);
    for (const auto& row : matrix1) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    // Test case 2
    std::vector<std::vector<int>> matrix2 = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    optimalSpiral(matrix2);
    for (const auto& row : matrix2) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    // Test case 3
    std::vector<std::vector<int>> matrix3 = {{0, 0}, {0, 0}};
    optimalSpiral(matrix3);
    for (const auto& row : matrix3) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```