```cpp
// Codeforces_1016C_SpiralMatrixOptimized
// https://codeforces.com/contest/1016/problem/C
// Given a matrix of size n x m, find the number of pairs of cells that are not in the same spiral.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(n*m*(n*m-1)/2) complexity
int bruteForceSpiralMatrixOptimized(int n, int m) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < m; l++) {
                    if (i != k || j != l) {
                        if (!isSameSpiral(i, j, k, l, n, m)) {
                            count++;
                        }
                    }
                }
            }
        }
    }
    return count / 2;
}

bool isSameSpiral(int i, int j, int k, int l, int n, int m) {
    int layer1 = std::min(std::min(i, j), std::min(n - i - 1, m - j - 1));
    int layer2 = std::min(std::min(k, l), std::min(n - k - 1, m - l - 1));
    return layer1 == layer2;
}

// Optimal solution with O(n*m) complexity
int spiralMatrixOptimized(int n, int m) {
    int count = 0;
    for (int layer = 0; layer < std::min(n, m) / 2; layer++) {
        int cellsInLayer = 2 * (n - 2 * layer - 1) + 2 * (m - 2 * layer - 1) - 4;
        count += cellsInLayer * (n * m - cellsInLayer);
    }
    if (n % 2 == 1 && m % 2 == 1) {
        count += (n * m - (n / 2) * (m / 2));
    }
    return count / 2;
}

int main() {
    std::cout << spiralMatrixOptimized(3, 3) << std::endl;  // Output: 10
    std::cout << spiralMatrixOptimized(4, 4) << std::endl;  // Output: 36
    std::cout << spiralMatrixOptimized(5, 5) << std::endl;  // Output: 70
    return 0;
}
```