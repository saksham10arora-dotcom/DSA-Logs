```cpp
// LeetCode 529: Minesweeper, https://leetcode.com/problems/minesweeper/, 
// Given an m x n matrix board where each element can only be 0 or 1, 
// representing empty space or mine, return the board after revealing all mines.

#include <iostream>
#include <vector>

// Brute force approach with O(m*n) complexity
class Solution_Brute {
public:
    std::vector<std::vector<char>> updateBoard(std::vector<std::vector<char>>& board, std::vector<int>& click) {
        int m = board.size();
        int n = board[0].size();
        int x = click[0];
        int y = click[1];
        
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        
        std::vector<std::vector<int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
        
        dfs(board, x, y, directions, visited);
        
        return board;
    }
    
    void dfs(std::vector<std::vector<char>>& board, int x, int y, std::vector<std::vector<int>>& directions, std::vector<std::vector<bool>>& visited) {
        int m = board.size();
        int n = board[0].size();
        
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || board[x][y] == 'M') {
            return;
        }
        
        visited[x][y] = true;
        
        int count = 0;
        for (auto& dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'M') {
                count++;
            }
        }
        
        if (count > 0) {
            board[x][y] = '0' + count;
        } else {
            board[x][y] = 'B';
            for (auto& dir : directions) {
                dfs(board, x + dir[0], y + dir[1], directions, visited);
            }
        }
    }
};

// Optimal solution with O(m*n) complexity
class Solution {
public:
    std::vector<std::vector<char>> updateBoard(std::vector<std::vector<char>>& board, std::vector<int>& click) {
        int m = board.size();
        int n = board[0].size();
        int x = click[0];
        int y = click[1];
        
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        
        std::vector<std::vector<int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
        
        dfs(board, x, y, directions, visited);
        
        return board;
    }
    
    void dfs(std::vector<std::vector<char>>& board, int x, int y, std::vector<std::vector<int>>& directions, std::vector<std::vector<bool>>& visited) {
        int m = board.size();
        int n = board[0].size();
        
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || board[x][y] == 'M') {
            return;
        }
        
        visited[x][y] = true;
        
        int count = 0;
        for (auto& dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'M') {
                count++;
            }
        }
        
        if (count > 0) {
            board[x][y] = '0' + count;
        } else {
            board[x][y] = 'B';
            for (auto& dir : directions) {
                dfs(board, x + dir[0], y + dir[1], directions, visited);
            }
        }
    }
};

int main() {
    Solution solution;
    
    std::vector<std::vector<char>> board1 = {{'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'}, 
                                          {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'}, 
                                          {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'}, 
                                          {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'}, 
                                          {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'}};
    std::vector<int> click1 = {3, 0};
    std::vector<std::vector<char>> result1 = solution.updateBoard(board1, click1);
    for (auto& row : result1) {
        for (char c : row) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }
    
    std::vector<std::vector<char>> board2 = {{'B', '1', 'E', '1', 'B'}, 
                                          {'B', '1', 'M', '1', 'B'}, 
                                          {'B', '1', '1', '1', 'B'}, 
                                          {'B', 'B', 'B', 'B', 'B'}};
    std::vector<int> click2 = {1, 2};
    std::vector<std::vector<char>> result2 = solution.updateBoard(board2, click2);
    for (auto& row : result2) {
        for (char c : row) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
```