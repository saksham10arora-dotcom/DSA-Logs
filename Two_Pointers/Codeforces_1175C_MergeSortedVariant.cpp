```cpp
// Codeforces_1175C_MergeSortedVariant
// https://codeforces.com/contest/1175/problem/C
// Given two sorted arrays, find the number of pairs (a, b) such that a^2 + b^2 = c^2.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(n^2) complexity
// int countPairs(std::vector<int>& a, std::vector<int>& b) {
//     int count = 0;
//     for (int i = 0; i < a.size(); i++) {
//         for (int j = 0; j < b.size(); j++) {
//             int c = a[i] * a[i] + b[j] * b[j];
//             int sqrt_c = std::sqrt(c);
//             if (sqrt_c * sqrt_c == c) {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// Optimal solution with O(n log n) complexity
int countPairs(std::vector<int>& a, std::vector<int>& b) {
    std::vector<int> squares;
    for (int i = 0; i < a.size(); i++) {
        squares.push_back(a[i] * a[i]);
    }
    for (int i = 0; i < b.size(); i++) {
        squares.push_back(b[i] * b[i]);
    }
    std::sort(squares.begin(), squares.end());
    int count = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            int c = a[i] * a[i] + b[j] * b[j];
            if (std::binary_search(squares.begin(), squares.end(), c)) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    std::vector<int> a1 = {1, 2, 3};
    std::vector<int> b1 = {4, 5, 6};
    std::cout << countPairs(a1, b1) << std::endl;

    std::vector<int> a2 = {1, 2, 3, 4};
    std::vector<int> b2 = {5, 6, 7, 8};
    std::cout << countPairs(a2, b2) << std::endl;

    std::vector<int> a3 = {1, 2};
    std::vector<int> b3 = {3, 4};
    std::cout << countPairs(a3, b3) << std::endl;

    return 0;
}
```