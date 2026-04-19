```cpp
// Falling Squares, https://leetcode.com/problems/falling-squares/, 
// On an infinite number line, there are n squares. Each square is represented as [position, size]. 
// We drop the first square on the line, and every k-th square (k >= 2) will be dropped on the top of the highest square already dropped.

#include <iostream>
#include <vector>
#include <algorithm>

// Brute force approach with O(n^2) complexity
class Solution_BruteForce {
public:
    std::vector<int> fallingSquares(std::vector<std::vector<int>>& positions) {
        std::vector<int> heights(positions.size(), 0);
        std::vector<int> max_heights;
        for (int i = 0; i < positions.size(); i++) {
            int max_height = 0;
            for (int j = 0; j < i; j++) {
                if (positions[j][0] < positions[i][0] + positions[i][1] && 
                    positions[i][0] < positions[j][0] + positions[j][1]) {
                    max_height = std::max(max_height, heights[j]);
                }
            }
            heights[i] = max_height + positions[i][1];
            max_heights.push_back(std::max(max_heights.empty() ? 0 : max_heights.back(), heights[i]));
        }
        return max_heights;
    }
};

// Optimal solution with O(n) complexity
class Solution {
public:
    std::vector<int> fallingSquares(std::vector<std::vector<int>>& positions) {
        std::vector<int> max_heights;
        int max_height = 0;
        for (auto& position : positions) {
            int height = 0;
            for (int i = 0; i < max_heights.size(); i++) {
                if (position[0] < i + max_heights[i] && i < position[0] + position[1]) {
                    height = std::max(height, max_heights[i]);
                }
            }
            height += position[1];
            max_height = std::max(max_height, height);
            max_heights.push_back(height);
        }
        std::vector<int> result;
        for (int i = 0; i < max_heights.size(); i++) {
            max_height = std::max(max_height, max_heights[i]);
            result.push_back(max_height);
        }
        return result;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> positions1 = {{1, 2}, {2, 3}, {6, 1}};
    std::vector<int> result1 = solution.fallingSquares(positions1);
    for (int height : result1) {
        std::cout << height << " ";
    }
    std::cout << std::endl;

    std::vector<std::vector<int>> positions2 = {{100, 100}, {200, 100}};
    std::vector<int> result2 = solution.fallingSquares(positions2);
    for (int height : result2) {
        std::cout << height << " ";
    }
    std::cout << std::endl;

    std::vector<std::vector<int>> positions3 = {{1, 2}, {2, 3}, {6, 1}, {7, 2}};
    std::vector<int> result3 = solution.fallingSquares(positions3);
    for (int height : result3) {
        std::cout << height << " ";
    }
    std::cout << std::endl;

    return 0;
}
```