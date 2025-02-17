```cpp
// LeetCode problem 2857: Count Pairs Of Points With Distance K
// https://leetcode.com/problems/count-pairs-of-points-with-distance-k/
// Given an array of points and an integer k, count the number of pairs of points with distance k.

#include <iostream>
#include <vector>
#include <unordered_map>

// Brute force approach with O(n^2) complexity
int countPairsOfPointsWithDistanceKBruteForce(std::vector<std::vector<int>>& points, int k) {
    int count = 0;
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            int distance = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
            if (distance == k * k) {
                count++;
            }
        }
    }
    return count;
}

// Optimal solution with O(n) complexity
int countPairsOfPointsWithDistanceKOptimal(std::vector<std::vector<int>>& points, int k) {
    std::unordered_map<int, std::unordered_map<int, int>> pointCounts;
    for (const auto& point : points) {
        pointCounts[point[0]][point[1]]++;
    }
    int count = 0;
    for (const auto& point : points) {
        for (int dx = -k; dx <= k; dx++) {
            for (int dy = -k; dy <= k; dy++) {
                if (dx * dx + dy * dy == k * k && pointCounts[point[0] + dx].find(point[1] + dy) != pointCounts[point[0] + dx].end()) {
                    count += pointCounts[point[0] + dx][point[1] + dy];
                }
            }
        }
    }
    // Subtract the cases where the same point is counted twice
    for (const auto& point : points) {
        if (pointCounts[point[0]][point[1]] > 1) {
            count -= pointCounts[point[0]][point[1]] - 1;
        }
    }
    return count / 2;
}

int main() {
    std::vector<std::vector<int>> points1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}};
    int k1 = 2;
    std::cout << "Test case 1: " << countPairsOfPointsWithDistanceKOptimal(points1, k1) << std::endl;

    std::vector<std::vector<int>> points2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}};
    int k2 = 3;
    std::cout << "Test case 2: " << countPairsOfPointsWithDistanceKOptimal(points2, k2) << std::endl;

    std::vector<std::vector<int>> points3 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}};
    int k3 = 5;
    std::cout << "Test case 3: " << countPairsOfPointsWithDistanceKOptimal(points3, k3) << std::endl;

    return 0;
}
```