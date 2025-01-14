```cpp
// LeetCode problem 3876: Construct Uniform Parity Array Ii
// https://leetcode.com/problems/construct-uniform-parity-array-ii/
// Given an integer n, return an array of length n where each element is either 0 or 1.
// The array should satisfy the following conditions:
// - The sum of all elements in the array is n / 2.
// - The prefix sum of the array is never negative.
// - The array is a uniform parity array, meaning that for any 0 <= i < n, 
//   the sum of all elements in the array from index 0 to i is either even or odd.

#include <iostream>
#include <vector>

// Brute force approach with O(2^n) complexity
// std::vector<int> constructArray(int n) {
//     std::vector<int> result;
//     std::function<void(int, int, int)> backtrack = 
//         [&result, &backtrack](int n, int sum, int index) {
//             if (index == n) {
//                 if (sum == n / 2) {
//                     result = std::vector<int>(n, 0);
//                     for (int i = 0; i < n; ++i) {
//                         if (i % 2 == 0) {
//                             result[i] = 1;
//                         }
//                     }
//                 }
//                 return;
//             }
//             backtrack(n, sum, index + 1);
//             backtrack(n, sum + 1, index + 1);
//         };
//     backtrack(n, 0, 0);
//     return result;
// }

// Optimal solution with O(n) complexity
std::vector<int> constructArray(int n) {
    std::vector<int> result(n, 0);
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            result[i] = 1;
        }
    }
    return result;
}

int main() {
    std::vector<int> test1 = constructArray(4);
    for (int num : test1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> test2 = constructArray(6);
    for (int num : test2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> test3 = constructArray(8);
    for (int num : test3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```