```cpp
// Codeforces_869D_WallsAndGatesVariant, https://codeforces.com/contest/869/problem/D
// Given a grid with walls and gates, find the shortest distance from each cell to the nearest gate.

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

// Brute force approach with O(n*m*max_distance) complexity
void bruteForce(std::vector<std::vector<int>>& rooms) {
    int n = rooms.size();
    int m = rooms[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (rooms[i][j] == INT_MAX) {
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < m; l++) {
                        if (rooms[k][l] == 0) {
                            int distance = abs(i - k) + abs(j - l);
                            if (distance < rooms[i][j]) {
                                rooms[i][j] = distance;
                            }
                        }
                    }
                }
            }
        }
    }
}

// Optimal solution with O(n*m) complexity
void optimalSolution(std::vector<std::vector<int>>& rooms) {
    int n = rooms.size();
    int m = rooms[0].size();
    std::queue<std::pair<int, int>> queue;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (rooms[i][j] == 0) {
                queue.push({i, j});
            }
        }
    }
    int directions[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!queue.empty()) {
        int x = queue.front().first;
        int y = queue.front().second;
        queue.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && rooms[nx][ny] > rooms[x][y] + 1) {
                rooms[nx][ny] = rooms[x][y] + 1;
                queue.push({nx, ny});
            }
        }
    }
}

int main() {
    // Test case 1
    std::vector<std::vector<int>> rooms1 = {
        {INT_MAX, -1, 0, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, -1},
        {INT_MAX, -1, INT_MAX, -1},
        {0, -1, INT_MAX, INT_MAX}
    };
    optimalSolution(rooms1);
    for (const auto& row : rooms1) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    // Test case 2
    std::vector<std::vector<int>> rooms2 = {
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, 0, INT_MAX, -1},
        {INT_MAX, INT_MAX, INT_MAX, -1},
        {INT_MAX, -1, INT_MAX, INT_MAX}
    };
    optimalSolution(rooms2);
    for (const auto& row : rooms2) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    // Test case 3
    std::vector<std::vector<int>> rooms3 = {
        {INT_MAX, -1, 0, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, -1},
        {INT_MAX, -1, INT_MAX, -1},
        {0, -1, INT_MAX, INT_MAX}
    };
    optimalSolution(rooms3);
    for (const auto& row : rooms3) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```