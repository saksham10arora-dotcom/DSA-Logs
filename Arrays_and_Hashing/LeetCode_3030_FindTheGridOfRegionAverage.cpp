```cpp
// LeetCode problem 3030: Find The Grid Of Region Average
// https://leetcode.com/problems/find-the-grid-of-region-average/
// Given a 2D grid of integers and a list of queries, find the average of each query region.

#include <iostream>
#include <vector>

// Brute force approach with O(n*m*q) complexity
class SolutionBrute {
public:
    std::vector<double> regionAverage(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& queries) {
        std::vector<double> result;
        for (auto& query : queries) {
            int x1 = query[0], y1 = query[1], x2 = query[2], y2 = query[3];
            int sum = 0, count = 0;
            for (int i = x1; i <= x2; i++) {
                for (int j = y1; j <= y2; j++) {
                    sum += grid[i][j];
                    count++;
                }
            }
            result.push_back((double)sum / count);
        }
        return result;
    }
};

// Optimal solution with O(n*m + q) complexity
class SolutionOptimal {
public:
    std::vector<double> regionAverage(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& queries) {
        int n = grid.size(), m = grid[0].size();
        std::vector<std::vector<int>> prefixSum(n + 1, std::vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        }
        std::vector<double> result;
        for (auto& query : queries) {
            int x1 = query[0], y1 = query[1], x2 = query[2], y2 = query[3];
            int sum = prefixSum[x2 + 1][y2 + 1] - prefixSum[x1][y2 + 1] - prefixSum[x2 + 1][y1] + prefixSum[x1][y1];
            int count = (x2 - x1 + 1) * (y2 - y1 + 1);
            result.push_back((double)sum / count);
        }
        return result;
    }
};

int main() {
    SolutionOptimal solution;
    std::vector<std::vector<int>> grid1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<int>> queries1 = {{0, 0, 1, 1}, {1, 1, 2, 2}, {0, 0, 2, 2}};
    for (double avg : solution.regionAverage(grid1, queries1)) {
        std::cout << avg << " ";
    }
    std::cout << std::endl;

    std::vector<std::vector<int>> grid2 = {{1, 2}, {3, 4}};
    std::vector<std::vector<int>> queries2 = {{0, 0, 1, 1}};
    for (double avg : solution.regionAverage(grid2, queries2)) {
        std::cout << avg << " ";
    }
    std::cout << std::endl;

    std::vector<std::vector<int>> grid3 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    std::vector<std::vector<int>> queries3 = {{0, 0, 3, 3}};
    for (double avg : solution.regionAverage(grid3, queries3)) {
        std::cout << avg << " ";
    }
    std::cout << std::endl;

    return 0;
}
```