```cpp
// Valid Mountain Array, https://leetcode.com/problems/valid-mountain-array/, 
// Given an array of integers arr, return true if and only if it is a valid mountain array.

#include <iostream>
#include <vector>

// Brute force approach: O(n^2) complexity
// bool validMountainArray(std::vector<int>& arr) {
//     int n = arr.size();
//     for (int i = 0; i < n; i++) {
//         bool increasing = true;
//         bool decreasing = true;
//         for (int j = 0; j < i; j++) {
//             if (arr[j] >= arr[j + 1]) {
//                 increasing = false;
//                 break;
//             }
//         }
//         for (int j = i; j < n - 1; j++) {
//             if (arr[j] <= arr[j + 1]) {
//                 decreasing = false;
//                 break;
//             }
//         }
//         if (increasing && decreasing) {
//             return true;
//         }
//     }
//     return false;
// }

// Optimal solution: O(n) complexity
bool validMountainArray(std::vector<int>& arr) {
    int n = arr.size();
    if (n < 3) {
        return false;
    }
    int i = 0;
    while (i < n - 1 && arr[i] < arr[i + 1]) {
        i++;
    }
    if (i == 0 || i == n - 1) {
        return false;
    }
    while (i < n - 1 && arr[i] > arr[i + 1]) {
        i++;
    }
    return i == n - 1;
}

int main() {
    std::vector<int> test1 = {2, 1};
    std::cout << std::boolalpha << validMountainArray(test1) << std::endl;  // false

    std::vector<int> test2 = {3, 5, 5};
    std::cout << std::boolalpha << validMountainArray(test2) << std::endl;  // false

    std::vector<int> test3 = {0, 3, 2, 1};
    std::cout << std::boolalpha << validMountainArray(test3) << std::endl;  // true

    return 0;
}
```