```cpp
// LeetCode problem 406: Queue Reconstruction By Height, https://leetcode.com/problems/queue-reconstruction-by-height/
// Given the array of people where people[i] = [hi, ki] represents a person of height hi and in front of and including them ki other people with the same or greater height.
// Reconstruct and return the queue that is represented by the input array.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(n^2) complexity
// std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>& people) {
//     std::vector<std::vector<int>> result;
//     for (auto& person : people) {
//         int count = 0;
//         for (int i = 0; i < result.size(); ++i) {
//             if (result[i][0] >= person[0]) {
//                 count++;
//             }
//             if (count == person[1]) {
//                 result.insert(result.begin() + i, person);
//                 break;
//             }
//         }
//         if (count < person[1]) {
//             result.push_back(person);
//         }
//     }
//     return result;
// }

// Optimal solution with O(n^2) complexity
std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>& people) {
    std::sort(people.begin(), people.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] > b[0];
    });
    std::vector<std::vector<int>> result;
    for (auto& person : people) {
        result.insert(result.begin() + person[1], person);
    }
    return result;
}

int main() {
    std::vector<std::vector<int>> people1 = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    std::vector<std::vector<int>> result1 = reconstructQueue(people1);
    for (auto& person : result1) {
        std::cout << "[" << person[0] << ", " << person[1] << "] ";
    }
    std::cout << std::endl;

    std::vector<std::vector<int>> people2 = {{6, 0}, {5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}};
    std::vector<std::vector<int>> result2 = reconstructQueue(people2);
    for (auto& person : result2) {
        std::cout << "[" << person[0] << ", " << person[1] << "] ";
    }
    std::cout << std::endl;

    std::vector<std::vector<int>> people3 = {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}};
    std::vector<std::vector<int>> result3 = reconstructQueue(people3);
    for (auto& person : result3) {
        std::cout << "[" << person[0] << ", " << person[1] << "] ";
    }
    std::cout << std::endl;

    return 0;
}
```