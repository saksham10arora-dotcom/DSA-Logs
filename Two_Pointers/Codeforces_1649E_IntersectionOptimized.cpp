```cpp
// Codeforces_1649E_IntersectionOptimized
// https://codeforces.com/contest/1649/problem/E
// Given two arrays of integers, find the maximum number of pairs that can be formed such that the sum of the pair is within a given range.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(n^2) complexity
int bruteForce(std::vector<int>& a, std::vector<int>& b, int l, int r) {
    int count = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (l <= a[i] + b[j] && a[i] + b[j] <= r) {
                count++;
            }
        }
    }
    return count;
}

// Optimal solution with O(n log n) complexity
int optimalSolution(std::vector<int>& a, std::vector<int>& b, int l, int r) {
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    int count = 0;
    for (int i = 0; i < a.size(); i++) {
        int left = std::lower_bound(b.begin(), b.end(), l - a[i]) - b.begin();
        int right = std::upper_bound(b.begin(), b.end(), r - a[i]) - b.begin();
        count += right - left;
    }
    return count;
}

int main() {
    // Test case 1
    std::vector<int> a1 = {1, 2, 3};
    std::vector<int> b1 = {4, 5, 6};
    int l1 = 5;
    int r1 = 7;
    std::cout << "Brute force: " << bruteForce(a1, b1, l1, r1) << std::endl;
    std::cout << "Optimal solution: " << optimalSolution(a1, b1, l1, r1) << std::endl;

    // Test case 2
    std::vector<int> a2 = {1, 2, 3, 4, 5};
    std::vector<int> b2 = {6, 7, 8, 9, 10};
    int l2 = 7;
    int r2 = 12;
    std::cout << "Brute force: " << bruteForce(a2, b2, l2, r2) << std::endl;
    std::cout << "Optimal solution: " << optimalSolution(a2, b2, l2, r2) << std::endl;

    // Test case 3
    std::vector<int> a3 = {1, 1, 1, 1, 1};
    std::vector<int> b3 = {1, 1, 1, 1, 1};
    int l3 = 2;
    int r3 = 2;
    std::cout << "Brute force: " << bruteForce(a3, b3, l3, r3) << std::endl;
    std::cout << "Optimal solution: " << optimalSolution(a3, b3, l3, r3) << std::endl;

    return 0;
}
```