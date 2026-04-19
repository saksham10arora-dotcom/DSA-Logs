```cpp
// LeetCode problem 3047: Find The Largest Area Of Square Inside Two Rectangles
// https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/
// Given two rectangles, find the largest area of a square that can be inscribed in both rectangles.

#include <iostream>
#include <algorithm>

// Brute force approach: O(n^2) complexity
int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int overlap_x = std::max(0, std::min(ax2, bx2) - std::max(ax1, bx1));
    int overlap_y = std::max(0, std::min(ay2, by2) - std::max(ay1, by1));
    return overlap_x * overlap_y;
}

// Optimal solution: O(1) complexity
int largestAreaOfSquareInsideRectangles(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int x = std::min(ax2, bx2) - std::max(ax1, bx1);
    int y = std::min(ay2, by2) - std::max(ay1, by1);
    int side = std::min(x, y);
    return side * side;
}

int main() {
    std::cout << largestAreaOfSquareInsideRectangles(0, 0, 2, 2, 1, 1, 3, 3) << std::endl;  // Output: 1
    std::cout << largestAreaOfSquareInsideRectangles(0, 0, 2, 2, 1, 0, 2, 2) << std::endl;  // Output: 1
    std::cout << largestAreaOfSquareInsideRectangles(-3, -2, 2, 2, -2, -2, 3, 3) << std::endl;  // Output: 16
    return 0;
}
```