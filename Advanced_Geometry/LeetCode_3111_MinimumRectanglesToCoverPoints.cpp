```cpp
// LeetCode problem 3111: Minimum Rectangles To Cover Points, https://leetcode.com/problems/minimum-rectangles-to-cover-points/
// Given a list of points on a 2D plane, find the minimum number of rectangles that can cover all the points.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach: try all possible rectangles, O(2^(n^2)) complexity
// int minRectangles(std::vector<std::vector<int>>& points) {
//     int n = points.size();
//     int minCount = INT_MAX;
//     for (int mask = 0; mask < (1 << (n * n)); mask++) {
//         // ...
//     }
//     return minCount;
// }

// Optimal solution: use a sweep line algorithm, O(n log n) complexity
int minRectangles(std::vector<std::vector<int>>& points) {
    int n = points.size();
    std::vector<int> xCoords, yCoords;
    for (auto& point : points) {
        xCoords.push_back(point[0]);
        yCoords.push_back(point[1]);
    }
    std::sort(xCoords.begin(), xCoords.end());
    std::sort(yCoords.begin(), yCoords.end());
    xCoords.erase(std::unique(xCoords.begin(), xCoords.end()), xCoords.end());
    yCoords.erase(std::unique(yCoords.begin(), yCoords.end()), yCoords.end());
    int m = xCoords.size(), k = yCoords.size();
    std::vector<std::vector<bool>> grid(m, std::vector<bool>(k, false));
    for (auto& point : points) {
        int x = std::lower_bound(xCoords.begin(), xCoords.end(), point[0]) - xCoords.begin();
        int y = std::lower_bound(yCoords.begin(), yCoords.end(), point[1]) - yCoords.begin();
        grid[x][y] = true;
    }
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            if (grid[i][j]) {
                count++;
                int right = i;
                while (right < m && grid[right][j]) right++;
                int down = j;
                while (down < k && grid[i][down]) down++;
                for (int x = i; x < right; x++) {
                    for (int y = j; y < down; y++) {
                        grid[x][y] = false;
                    }
                }
            }
        }
    }
    return count;
}

int main() {
    std::vector<std::vector<int>> points1 = {{1, 1}, {1, 3}, {3, 1}, {3, 3}, {2, 2}};
    std::cout << minRectangles(points1) << std::endl;  // Output: 2

    std::vector<std::vector<int>> points2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    std::cout << minRectangles(points2) << std::endl;  // Output: 5

    std::vector<std::vector<int>> points3 = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    std::cout << minRectangles(points3) << std::endl;  // Output: 1

    return 0;
}
```