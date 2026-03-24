```cpp
// LeetCode problem 638: Valid Square I I
// https://leetcode.com/problems/valid-square/
// Given the coordinates of four points in 2D space, return whether the four points could construct a square.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// Brute force approach with O(1) complexity
bool validSquareBruteForce(std::vector<int>& p1, std::vector<int>& p2, std::vector<int>& p3, std::vector<int>& p4) {
    std::vector<std::vector<int>> points = {p1, p2, p3, p4};
    std::vector<double> distances;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            double distance = sqrt(pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2));
            distances.push_back(distance);
        }
    }
    std::sort(distances.begin(), distances.end());
    return distances[0] == distances[1] && distances[1] == distances[2] && distances[2] == distances[3] && distances[4] == distances[5];
}

// Optimal solution with O(1) complexity
bool validSquareOptimal(std::vector<int>& p1, std::vector<int>& p2, std::vector<int>& p3, std::vector<int>& p4) {
    std::vector<std::vector<int>> points = {p1, p2, p3, p4};
    double d[6];
    int index = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            d[index++] = pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2);
        }
    }
    std::sort(d, d + 6);
    return d[0] == d[1] && d== d[2] && d[2] == d[3] && d[4] == d[5] && d[0] < d[4];
}

int main() {
    std::vector<int> p1 = {1, 1};
    std::vector<int> p2 = {3, 0};
    std::vector<int> p3 = {1, 0};
    std::vector<int> p4 = {3, 1};
    std::cout << std::boolalpha << validSquareOptimal(p1, p2, p3, p4) << std::endl;  // Output: true

    p1 = {1, 2};
    p2 = {2,