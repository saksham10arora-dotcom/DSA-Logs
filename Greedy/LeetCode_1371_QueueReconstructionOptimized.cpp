```cpp
// LeetCode problem 1371: Queue Reconstruction by Height (https://leetcode.com/problems/queue-reconstruction-by-height/)
// Brief description: Reconstruct a queue from a list of people with their heights and the number of people in front of them who are taller or the same height.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(n^2) complexity
// std::vector<std::vector<int>> reconstructQueueBruteForce(std::vector<std::vector<int>>& people) {
//     std::vector<std::vector<int>> result;
//     for (const auto& person : people) {
//         int insertIndex = 0;
//         for (int i = 0; i < result.size(); ++i) {
//             if (result[i][0] >= person[0]) {
//                 insertIndex++;
//             }
//         }
//         result.insert(result.begin() + insertIndex, person);
//     }
//     return result;
// }

// Optimal solution with O(n^2) complexity
std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>& people) {
    std::sort(people.begin(), people.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
    });
    std::vector<std::vector<int>> result;
    for (const auto& person : people) {
        result.insert(result.begin() + person[1], person);
    }
    return result;
}

int main() {
    std::vector<std::vector<int>> people1 = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    std::vector<std::vector<int>> result1 = reconstructQueue(people1);
    for (const auto& person : result1) {
        std::cout << "[" << person[0] << ", " << person[1] << "] ";
    }
    std::cout << std::endl;

    std::vector<std::vector<int>> people2 = {{6, 0}, {5, 0}, {4, 0}, {3, 2}, {2, 2}, {1, 4}};
    std::vector<std::vector<int>> result2 = reconstructQueue(people2);
    for (const auto& person : result2) {
        std::cout << "[" << person[0] << ", " << person[1] << "] ";
    }
    std::cout << std::endl;

    std::vector<std::vector<int>> people3 = {{1, 0}};
    std::vector<std::vector<int>> result3 = reconstructQueue(people3);
    for (const auto& person : result3) {
        std::cout << "[" << person[0] << ", " << person[1] << "] ";
    }
    std::cout << std::endl;

    return 0;
}
```