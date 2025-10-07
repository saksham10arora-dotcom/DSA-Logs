```cpp
// Number Of Pairs Of Interchangeable Rectangles, https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/
// Given a list of rectangles, find the number of pairs of interchangeable rectangles.

#include <iostream>
#include <vector>
#include <unordered_map>

// Brute force approach: O(n^2) complexity
// int interchangeableRectangles(std::vector<std::vector<int>>& rectangles) {
//     int count = 0;
//     for (int i = 0; i < rectangles.size(); i++) {
//         for (int j = i + 1; j < rectangles.size(); j++) {
//             if (rectangles[i][0] * rectangles[j][1] == rectangles[j][0] * rectangles[i][1]) {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// Optimal solution: O(n) complexity
int interchangeableRectangles(std::vector<std::vector<int>>& rectangles) {
    std::unordered_map<double, int> ratioCount;
    int count = 0;
    for (const auto& rectangle : rectangles) {
        double ratio = static_cast<double>(rectangle[0]) / rectangle[1];
        count += ratioCount[ratio];
        ratioCount[ratio]++;
    }
    return count;
}

int main() {
    std::vector<std::vector<int>> test1 = {{4, 8}, {3, 6}, {10, 20}, {15, 30}};
    std::vector<std::vector<int>> test2 = {{4, 5}, {7, 8}};
    std::vector<std::vector<int>> test3 = {{1, 1}, {1, 1}, {1, 1}, {1, 1}};

    std::cout << interchangeableRectangles(test1) << std::endl;  // Output: 6
    std::cout << interchangeableRectangles(test2) << std::endl;  // Output: 0
    std::cout << interchangeableRectangles(test3) << std::endl;  // Output: 6

    return 0;
}
```