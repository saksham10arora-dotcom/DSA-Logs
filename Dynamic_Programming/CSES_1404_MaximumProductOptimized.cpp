```cpp
// Maximum Product Optimized
// https://cses.fi/problemset/task/1404
// Given an array of integers, find the maximum product of a subarray.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(2^n) complexity
int maxProductBruteForce(const std::vector<int>& arr) {
    int maxProduct = arr[0];
    for (int mask = 1; mask < (1 << arr.size()); ++mask) {
        int product = 1;
        for (int i = 0; i < arr.size(); ++i) {
            if ((mask & (1 << i))!= 0) {
                product *= arr[i];
            }
        }
        maxProduct = std::max(maxProduct, product);
    }
    return maxProduct;
}

// Optimal solution with O(n) complexity
int maxProductOptimized(const std::vector<int>& arr) {
    int maxProduct = arr[0];
    int minProduct = arr[0];
    int result = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] < 0) {
            std::swap(maxProduct, minProduct);
        }
        maxProduct = std::max(arr[i], maxProduct * arr[i]);
        minProduct = std::min(arr[i], minProduct * arr[i]);
        result = std::max(result, maxProduct);
    }
    return result;
}

int main() {
    std::vector<int> test1 = {1, 2, 3, 0, -3, -2, -1};
    std::vector<int> test2 = {-1, -2, -3, 0, 1, 2, 3};
    std::vector<int> test3 = {0, 0, 0, 0, 0, 0, 0};

    std::cout << "Test 1: " << maxProductOptimized(test1) << std::endl;
    std::cout << "Test 2: " << maxProductOptimized(test2) << std::endl;
    std::cout << "Test 3: " << maxProductOptimized(test3) << std::endl;

    return 0;
}
```