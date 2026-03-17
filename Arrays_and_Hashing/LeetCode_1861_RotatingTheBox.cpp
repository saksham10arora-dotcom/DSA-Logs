```cpp
// Rotating The Box, https://leetcode.com/problems/rotating-the-box/, 
// Given a 2D array of size m x n representing a box, rotate the box by 90 degrees clockwise.

#include <iostream>
#include <vector>

// Brute force approach with O(m*n) complexity
std::vector<std::vector<char>> rotateTheBoxBruteForce(std::vector<std::vector<char>>& box) {
    int m = box.size();
    int n = box[0].size();
    std::vector<std::vector<char>> result(n, std::vector<char>(m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[j][m - i - 1] = box[i][j];
        }
    }
    return result;
}

// Optimal solution with O(m*n) complexity
std::vector<std::vector<char>> rotateTheBox(std::vector<std::vector<char>>& box) {
    int m = box.size();
    int n = box[0].size();
    std::vector<std::vector<char>> result(n, std::vector<char>(m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[j][m - i - 1] = box[i][j];
        }
    }
    return result;
}

int main() {
    std::vector<std::vector<char>> box1 = {{'#', '#', '*'}, {'#', '.', '#'}, {'*', '.', '.'}};
    std::vector<std::vector<char>> result1 = rotateTheBox(box1);
    for (const auto& row : result1) {
        for (char c : row) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }

    std::vector<std::vector<char>> box2 = {{'#', '.', '#'}};
    std::vector<std::vector<char>> result2 = rotateTheBox(box2);
    for (const auto& row : result2) {
        for (char c : row) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }

    std::vector<std::vector<char>> box3 = {{'#'}};
    std::vector<std::vector<char>> result3 = rotateTheBox(box3);
    for (const auto& row : result3) {
        for (char c : row) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```