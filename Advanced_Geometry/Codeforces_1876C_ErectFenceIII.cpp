```cpp
// Codeforces_1876C_ErectFenceIII
// https://codeforces.com/contest/1876/problem/C
// Given a set of points on a plane, find the minimum area of a convex polygon that contains all the points.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Structure to represent a point
struct Point {
    long long x, y;
};

// Function to calculate the orientation of three points
int orientation(const Point& p, const Point& q, const Point& r) {
    long long val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // Collinear
    return (val > 0) ? 1 : 2;  // Clockwise or counterclockwise
}

// Function to calculate the convex hull using the Graham's scan algorithm
vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    if (n < 3) return {};

    // Find the leftmost point
    int leftmost = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[leftmost].x) {
            leftmost = i;
        }
    }

    // Swap the leftmost point with the first point
    swap(points[0], points[leftmost]);

    // Sort the remaining points based on the polar angle with the leftmost point
    sort(points.begin() + 1, points.end(), [&](const Point& p, const Point& q) {
        int o = orientation(points[0], p, q);
        if (o == 0) {
            return (p.x - points[0].x) * (p.x - points[0].x) + (p.y - points[0].y) * (p.y - points[0].y) <
                   (q.x - points[0].x) * (q.x - points[0].x) + (q.y - points[0].y) * (q.y - points[0].y);
        }
        return o == 2;
    });

    // Initialize the convex hull with the first two points
    vector<Point> hull = {points[0], points[1]};

    // Iterate over the remaining points to build the convex hull
    for (int i = 2; i < n; i++) {
        while (hull.size() > 1 && orientation(hull[hull.size() - 2], hull.back(), points[i]) != 2) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    return hull;
}

// Function to calculate the area of a polygon using the Shoelace formula
long long polygonArea(const vector<Point>& points) {
    int n = points.size();
    long long area = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += points[i].x * points[j].y;
        area -= points[j].x * points[i].y;
    }
    return abs(area) / 2;
}

int main() {
    // Test case 1
    vector<Point> points1 = {{0, 0}, {0, 2}, {2, 2}, {2, 0}};
    vector<Point> hull1 = convexHull(points1);
    cout << "Area of convex hull: " << polygonArea(hull1) << endl;

    // Test case 2
    vector<Point> points2 = {{0, 0}, {0, 3}, {3, 3}, {3, 0}, {1, 1}, {2, 2}};
    vector<Point> hull2 = convexHull(points2);
    cout << "Area of convex hull: " << polygonArea(hull2) << endl;

    // Test case 3
    vector<Point> points3 = {{-2, -2}, {-2, 2}, {2, 2}, {2, -2}, {-1, -1}, {1, 1}};
    vector<Point> hull3 = convexHull(points3);
    cout << "Area of convex hull: " << polygonArea(hull3) << endl;

    return 0;
}
```