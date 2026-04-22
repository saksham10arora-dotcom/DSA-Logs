```cpp
// Walls And Gates Optimized, https://leetcode.com/problems/walls-and-gates/, 
// You are given an m x n grid rooms, where rooms[i][j] may be one of three values:
// -1 A wall or obstacle.
// 0 A gate.
// INF Infinity / 2147483647, an empty room. 
// We need to fill each empty room with the number of steps to reach the nearest gate. 
// If it is impossible to reach a gate, the value remains as INF.

#include <iostream>
#include <vector>
#include <queue>

// Brute force approach: O(m * n * (m * n)) complexity
// class Solution {
// public:
//     void wallsAndGates(std::vector<std::vector<int>>& rooms) {
//         int m = rooms.size();
//         int n = rooms[0].size();
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (rooms[i][j] == 2147483647) {
//                     rooms[i][j] = bfs(rooms, i, j);
//                 }
//             }
//         }
//     }
// private:
//     int bfs(const std::vector<std::vector<int>>& rooms, int x, int y) {
//         int m = rooms.size();
//         int n = rooms[0].size();
//         std::queue<std::pair<int, int>> q;
//         std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
//         q.push({x, y});
//         visited[x][y] = true;
//         int steps = 0;
//         while (!q.empty()) {
//             int size = q.size();
//             for (int i = 0; i < size; i++) {
//                 int currX = q.front().first;
//                 int currY = q.front().second;
//                 q.pop();
//                 if (rooms[currX][currY] == 0) {
//                     return steps;
//                 }
//                 std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//                 for (const auto& dir : directions) {
//                     int newX = currX + dir.first;
//                     int newY = currY + dir.second;
//                     if (newX >= 0 && newX < m && newY >= 0 && newY < n && !visited[newX][newY] && rooms[newX][newY] != -1) {
//                         q.push({newX, newY});
//                         visited[newX][newY] = true;
//                     }
//                 }
//             }
//             steps++;
//         }
//         return 2147483647;
//     }
// };

// Optimal solution: O(m * n) complexity
class Solution {
public:
    void wallsAndGates(std::vector<std::vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();
        std::queue<std::pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        int steps = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int currX = q.front().first;
                int currY = q.front().second;
                q.pop();
                std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                for (const auto& dir : directions) {
                    int newX = currX + dir.first;
                    int newY = currY + dir.second;
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n && rooms[newX][newY] == 2147483647) {
                        rooms[newX][newY] = steps;
                        q.push({newX, newY});
                    }
                }
            }
            steps++;
        }
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> rooms1 = {{-1, -1, 2147483647}, {-1, 0, -1}, {2147483647, -1, -1}};
    solution.wallsAndGates(rooms1);
    for (const auto& row : rooms1) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::vector<std::vector<int>> rooms2 = {{2147483647, -1, 0, 2147483647}, {2147483647, 2147483647, 2147483647, -1}, {2147483647, -1, 2147483647, -1}, {0, -1, 2147483647, 2147483647}};
    solution.wallsAndGates(rooms2);
    for (const auto& row : rooms2) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::vector<std::vector<int>> rooms3 = {{-1}};
    solution.wallsAndGates(rooms3);
    for (const auto& row : rooms3) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
```