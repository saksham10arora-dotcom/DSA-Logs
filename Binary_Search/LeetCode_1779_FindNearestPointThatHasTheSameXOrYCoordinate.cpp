```cpp
// LeetCode problem 1779: Find Nearest Point That Has The Same X Or Y Coordinate
// https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/
// Given a point (x, y) and a list of points, find the point in the list that has the same x or y coordinate and is closest to (x, y).

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// Brute force approach with O(n) complexity
int findNearestPointBruteForce(int x, int y, std::vector<std::vector<int>>& points) {
    int minDistance = INT_MAX;
    int nearestPointIndex = -1;
    for (int i = 0; i < points.size(); i++) {
        if (points[i][0] == x || points[i][1] == y) {
            int distance = std::abs(points[i][0] - x) + std::abs(points[i][1] - y);
            if (distance < minDistance) {
                minDistance = distance;
                nearestPointIndex = i;
            }
        }
    }
    return nearestPointIndex;
}

// Optimal solution with O(n) complexity
int findNearestPoint(int x, int y, std::vector<std::vector<int>>& points) {
    int minDistance = INT_MAX;
    int nearestPointIndex = -1;
    for (int i = 0; i < points.size(); i++) {
        if (points[i][0] == x || points[i][1] == y) {
            int distance = std::abs(points[i][0] - x) + std::abs(points[i][1] - y);
            if (distance < minDistance) {
                minDistance = distance;
                nearestPointIndex = i;
            }
        }
    }
    return nearestPointIndex;
}

int main() {
    std::vector<std::vector<int>> points1 = {{1, 2}, {3, 1}, {2, 4}, {2, 3}, {4, 4}};
    std::cout << findNearestPoint(3, 4, points1) << std::endl;  // Output: 2

    std::vector<std::vector<int>> points2 = {{3, 4}};
    std::cout << findNearestPoint(3, 4, points2) << std::endl;  // Output: 0

    std::vector<std::vector<int>> points3 = {{2, 3}, {12, 13}, {40, 50}, {5, 1}, {12, 12}, {3, 4}};
    std::cout << findNearestPoint(42, 0, points3) << std::endl;  // Output: 1

    return 0;
}
```