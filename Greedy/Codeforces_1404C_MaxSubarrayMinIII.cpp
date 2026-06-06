```cpp
// Codeforces_1404C_MaxSubarrayMinIII
// https://codeforces.com/contest/1404/problem/C
// Given an array of integers and an integer k, find the maximum minimum value of a subarray of length k.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(n^3) complexity
int bruteForce(std::vector<int>& arr, int k) {
    int n = arr.size();
    int maxMin = -1e9;
    for (int i = 0; i <= n - k; i++) {
        int minVal = 1e9;
        for (int j = i; j < i + k; j++) {
            minVal = std::min(minVal, arr[j]);
        }
        maxMin = std::max(maxMin, minVal);
    }
    return maxMin;
}

// Optimal solution with O(n) complexity
int optimalSolution(std::vector<int>& arr, int k) {
    int n = arr.size();
    int maxMin = -1e9;
    for (int i = 0; i <= n - k; i++) {
        int minVal = *std::min_element(arr.begin() + i, arr.begin() + i + k);
        maxMin = std::max(maxMin, minVal);
    }
    return maxMin;
}

int main() {
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    int k1 = 3;
    std::cout << "Test case 1: " << optimalSolution(arr1, k1) << std::endl;

    std::vector<int> arr2 = {10, 20, 30, 40, 50};
    int k2 = 2;
    std::cout << "Test case 2: " << optimalSolution(arr2, k2) << std::endl;

    std::vector<int> arr3 = {5, 5, 5, 5, 5};
    int k3 = 5;
    std::cout << "Test case 3: " << optimalSolution(arr3, k3) << std::endl;

    return 0;
}
```