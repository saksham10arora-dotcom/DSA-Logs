```cpp
// LeetCode problem 1898: Point In Polygon Optimized
// https://leetcode.com/problems/point-in-polygon-optimized/
// Determine if a point is inside a polygon.

#include <vector>
#include <iostream>

// Brute force approach: O(n) complexity
class Solution {
public:
    bool isPointInside(std::vector<std::vector<int>>& polygon, std::vector<int>& point) {
        int x = point[0], y = point[1];
        int n = polygon.size();
        int inside = 0;
        for (int i = 0, j = n - 1; i < n; j = i++) {
            int xi = polygon[i][0], yi = polygon[i][1];
            int xj = polygon[j][0], yj = polygon[j][1];
            bool intersect = ((yi > y) != (yj > y)) && (x < (xj - xi) * (y - yi) / (yj - yi) + xi);
            if (intersect) inside ^= 1;
        }
        return inside;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> polygon1 = {{0, 0}, {0, 5}, {5, 5}, {5, 0}};
    std::vector<int> point1 = {3, 3};
    std::cout << std::boolalpha << solution.isPointInside(polygon1, point1) << std::endl;  // Expected output: true

    std::vector<std::vector<int>> polygon2 = {{0, 0}, {0, 5}, {5, 5}, {5, 0}};
    std::vector<int> point2 = {6, 3};
    std::cout << std::boolalpha << solution.isPointInside(polygon2, point2) << std::endl;  // Expected output: false

    std::vector<std::vector<int>> polygon3 = {{0, 0}, {5, 0}, {5, 5}, {0, 5}};
    std::vector<int> point3 = {3, 3};
    std::cout << std::boolalpha << solution.isPointInside(polygon3, point3) << std::endl;  // Expected output: true

    return 0;
}
```