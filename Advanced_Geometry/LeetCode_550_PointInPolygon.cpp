```cpp
/**
 * LeetCode 550: Point In Polygon
 * https://leetcode.com/problems/dot-product-of-two-sparse-vectors/
 * Given a list of (x, y) coordinates and a query point (x, y), 
 * determine if the point is inside the polygon.
 */

#include <iostream>
#include <vector>

// Brute force approach: O(n) complexity
bool pointInPolygonBruteForce(const std::vector<std::vector<int>>& points, const std::vector<int>& query) {
    int n = points.size();
    int x = query[0];
    int y = query[1];
    int inside = 0;
    for (int i = 0, j = n - 1; i < n; j = i++) {
        if (((points[i][1] > y) != (points[j][1] > y)) && 
            (x < (points[j][0] - points[i][0]) * (y - points[i][1]) / (points[j][1] - points[i][1]) + points[i][0])) {
            inside = !inside;
        }
    }
    return inside;
}

// Optimal solution: O(n) complexity
bool pointInPolygonOptimal(const std::vector<std::vector<int>>& points, const std::vector<int>& query) {
    int n = points.size();
    int x = query[0];
    int y = query[1];
    int inside = 0;
    for (int i = 0, j = n - 1; i < n; j = i++) {
        if (((points[i][1] > y) != (points[j][1] > y)) && 
            (x < (points[j][0] - points[i][0]) * (y - points[i][1]) / (points[j][1] - points[i][1]) + points[i][0])) {
            inside = !inside;
        }
    }
    return inside;
}

int main() {
    std::vector<std::vector<int>> points1 = {{1, 1}, {1, 5}, {5, 5}, {5, 1}};
    std::vector<int> query1 = {3, 3};
    std::cout << std::boolalpha << pointInPolygonOptimal(points1, query1) << std::endl;  // True

    std::vector<std::vector<int>> points2 = {{1, 1}, {1, 5}, {5, 5}, {5, 1}};
    std::vector<int> query2 = {0, 0};
    std::cout << std::boolalpha << pointInPolygonOptimal(points2, query2) << std::endl;  // False

    std::vector<std::vector<int>> points3 = {{1, 1}, {1, 5}, {5, 5}, {5, 1}};
    std::vector<int> query3 = {3, 6};
    std::cout << std::boolalpha << pointInPolygonOptimal(points3, query3) << std::endl;  // False

    return 0;
}
```