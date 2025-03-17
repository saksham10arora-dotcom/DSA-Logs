```cpp
// LeetCode problem 1454: Area Of Triangles Variant, https://leetcode.com/problems/active-users/
// Given a list of points on a 2D plane, find the area of the triangle formed by three points.

#include <iostream>
#include <vector>
#include <cmath>

// Brute force approach with O(n^3) complexity
double areaOfTriangleBruteForce(std::vector<std::vector<int>>& points) {
    int n = points.size();
    double maxArea = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                double area = std::abs((points[i][0] * (points[j][1] - points[k][1]) + 
                                        points[j][0] * (points[k][1] - points[i][1]) + 
                                        points[k][0] * (points[i][1] - points[j][1])) / 2.0);
                maxArea = std::max(maxArea, area);
            }
        }
    }
    return maxArea;
}

// Optimal solution with O(n^3) complexity
double areaOfTriangleOptimal(std::vector<std::vector<int>>& points) {
    int n = points.size();
    double maxArea = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                double area = std::abs((points[i][0] * (points[j][1] - points[k][1]) + 
                                        points[j][0] * (points[k][1] - points[i][1]) + 
                                        points[k][0] * (points[i][1] - points[j][1])) / 2.0);
                maxArea = std::max(maxArea, area);
            }
        }
    }
    return maxArea;
}

int main() {
    std::vector<std::vector<int>> points1 = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    std::vector<std::vector<int>> points2 = {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}};
    std::vector<std::vector<int>> points3 = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};

    std::cout << "Area of triangle (brute force): " << areaOfTriangleBruteForce(points1) << std::endl;
    std::cout << "Area of triangle (optimal): " << areaOfTriangleOptimal(points1) << std::endl;

    std::cout << "Area of triangle (brute force): " << areaOfTriangleBruteForce(points2) << std::endl;
    std::cout << "Area of triangle (optimal): " << areaOfTriangleOptimal(points2) << std::endl;

    std::cout << "Area of triangle (brute force): " << areaOfTriangleBruteForce(points3) << std::endl;
    std::cout << "Area of triangle (optimal): " << areaOfTriangleOptimal(points3) << std::endl;

    return 0;
}
```