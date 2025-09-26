```cpp
// LeetCode problem 1746: Snakes And Ladders I I I
// https://leetcode.com/problems/snakes-and-ladders-iii/
// Given an n x n board and a list of snakes and ladders, find the least number of moves to reach the square n*n.

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>

// Brute force approach with O(n^6) complexity
// int snakesAndLadders(std::vector<std::vector<int>>& board) {
//     int n = board.size();
//     std::queue<std::pair<int, int>> q;
//     std::unordered_set<int> visited;
//     q.push({1, 0});
//     while (!q.empty()) {
//         int pos = q.front().first;
//         int step = q.front().second;
//         q.pop();
//         if (pos == n * n) return step;
//         for (int i = 1; i <= 6; i++) {
//             int next = pos + i;
//             if (next > n * n) continue;
//             int row = (next - 1) / n;
//             int col = (next - 1) % n;
//             if (row % 2 == 0) col = n - 1 - col;
//             if (board[n - 1 - row][col] != -1) next = board[n - 1 - row][col];
//             if (visited.find(next) == visited.end()) {
//                 q.push({next, step + 1});
//                 visited.insert(next);
//             }
//         }
//     }
//     return -1;
// }

// Optimal solution with O(n^2) complexity
int snakesAndLadders(std::vector<std::vector<int>>& board) {
    int n = board.size();
    std::queue<std::pair<int, int>> q;
    std::unordered_set<int> visited;
    q.push({1, 0});
    visited.insert(1);
    while (!q.empty()) {
        int pos = q.front().first;
        int step = q.front().second;
        q.pop();
        if (pos == n * n) return step;
        for (int i = 1; i <= 6; i++) {
            int next = pos + i;
            if (next > n * n) continue;
            int row = (next - 1) / n;
            int col = (next - 1) % n;
            if (row % 2 == 0) col = n - 1 - col;
            if (board[n - 1 - row][col] != -1) next = board[n - 1 - row][col];
            if (visited.find(next) == visited.end()) {
                q.push({next, step + 1});
                visited.insert(next);
            }
        }
    }
    return -1;
}

int main() {
    std::vector<std::vector<int>> board1 = {{-1, -1, -1, -1, -1, -1},
                                           {-1, -1, -1, -1, -1, -1},
                                           {-1, -1, -1, -1, -1, -1},
                                           {-1, 35, -1, -1, 13, -1},
                                           {20, -1, -1, -1, 12, 11},
                                           {-1, 24, -1, 1, -1, 19}};
    std::cout << snakesAndLadders(board1) << std::endl;  // Output: 4

    std::vector<std::vector<int>> board2 = {{-1, -1},
                                           {-1, 3}};
    std::cout << snakesAndLadders(board2) << std::endl;  // Output: 1

    std::vector<std::vector<int>> board3 = {{-1, -1, -1},
                                           {-1, 9, 8},
                                           {-1, 8, 9}};
    std::cout << snakesAndLadders(board3) << std::endl;  // Output: 2

    return 0;
}
```