```cpp
// Trapping Rain Water I I I
// https://cses.fi/problemset/task/2020
// Given an array of non-negative integers representing the height of bars in a histogram,
// find the total amount of water that can be trapped between the bars.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach: O(n^2) complexity
// int trap(std::vector<int>& height) {
//     int n = height.size();
//     int total_water = 0;
//     for (int i = 0; i < n; i++) {
//         int max_left = 0, max_right = 0;
//         for (int j = 0; j < i; j++) {
//             max_left = std::max(max_left, height[j]);
//         }
//         for (int j = i + 1; j < n; j++) {
//             max_right = std::max(max_right, height[j]);
//         }
//         int min_height = std::min(max_left, max_right);
//         if (min_height > height[i]) {
//             total_water += min_height - height[i];
//         }
//     }
//     return total_water;
// }

// Optimal solution: O(n) complexity
int trap(std::vector<int>& height) {
    int n = height.size();
    int total_water = 0;
    std::vector<int> max_left(n), max_right(n);
    max_left[0] = height[0];
    max_right[n - 1] = height[n - 1];
    for (int i = 1; i < n; i++) {
        max_left[i] = std::max(max_left[i - 1], height[i]);
        max_right[n - 1 - i] = std::max(max_right[n - i], height[n - 1 - i]);
    }
    for (int i = 0; i < n; i++) {
        int min_height = std::min(max_left[i], max_right[i]);
        if (min_height > height[i]) {
            total_water += min_height - height[i];
        }
    }
    return total_water;
}

int main() {
    std::vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::cout << trap(height1) << std::endl;  // Output: 6

    std::vector<int> height2 = {4, 2, 0, 3, 2, 5};
    std::cout << trap(height2) << std::endl;  // Output: 9

    std::vector<int> height3 = {5, 5, 5, 1, 1, 5, 5, 5};
    std::cout << trap(height3) << std::endl;  // Output: 10

    return 0;
}
```