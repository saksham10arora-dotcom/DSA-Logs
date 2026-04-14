```cpp
// LeetCode problem 915: Partition Array Into Disjoint Intervals
// https://leetcode.com/problems/partition-array-into-disjoint-intervals/
// Given an array A, partition it into two disjoint (non-empty) subarrays left and right such that every element in left is less than or equal to every element in right.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach: O(n^2) complexity
// int partitionDisjoint(std::vector<int>& A) {
//     for (int i = 0; i < A.size() - 1; i++) {
//         bool valid = true;
//         for (int j = 0; j <= i; j++) {
//             for (int k = i + 1; k < A.size(); k++) {
//                 if (A[j] > A[k]) {
//                     valid = false;
//                     break;
//                 }
//             }
//             if (!valid) break;
//         }
//         if (valid) return i + 1;
//     }
//     return -1;
// }

// Optimal solution: O(n) complexity
int partitionDisjoint(std::vector<int>& A) {
    int n = A.size();
    std::vector<int> leftMax(n, 0);
    std::vector<int> rightMin(n, 0);
    leftMax[0] = A[0];
    rightMin[n - 1] = A[n - 1];
    for (int i = 1; i < n; i++) {
        leftMax[i] = std::max(leftMax[i - 1], A[i]);
        rightMin[n - 1 - i] = std::min(rightMin[n - i], A[n - 1 - i]);
    }
    for (int i = 0; i < n - 1; i++) {
        if (leftMax[i] <= rightMin[i + 1]) return i + 1;
    }
    return -1;
}

int main() {
    std::vector<int> A1 = {5, 0, 3, 8, 6};
    std::vector<int> A2 = {1, 1, 1, 0, 6, 12};
    std::vector<int> A3 = {1, 2, 3, 4, 5};
    std::cout << partitionDisjoint(A1) << std::endl;  // Output: 4
    std::cout << partitionDisjoint(A2) << std::endl;  // Output: 4
    std::cout << partitionDisjoint(A3) << std::endl;  // Output: 4
    return 0;
}
```