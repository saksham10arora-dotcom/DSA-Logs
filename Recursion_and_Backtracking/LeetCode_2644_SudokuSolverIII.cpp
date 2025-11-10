```cpp
// LeetCode problem 2644: Sudoku Solver III
// https://leetcode.com/problems/sudoku-solver-iii/
// Given a 9x9 Sudoku board, solve it using backtracking.

#include <iostream>
#include <vector>

class Solution {
public:
    bool isValid(std::vector<std::vector<char>>& board, int row, int col, char c) {
        // Check the row
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c) {
                return false;
            }
        }
        // Check the column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c) {
                return false;
            }
        }
        // Check the box
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i + startRow][j + startCol] == c) {
                    return false;
                }
            }
        }
        return true;
    }

    bool solveSudoku(std::vector<std::vector<char>>& board) {
        // Brute force approach with O(9^(n*n)) complexity
        // Optimal solution with O(9^(n*n)) complexity, but with pruning
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solveSudoku(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void printBoard(const std::vector<std::vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                std::cout << board[i][j] << " ";
                if ((j + 1) % 3 == 0 && j < 8) {
                    std::cout << "| ";
                }
            }
            std::cout << std::endl;
            if ((i + 1) % 3 == 0 && i < 8) {
                std::cout << "---------------------" << std::endl;
            }
        }
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<char>> board1 = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    if (solution.solveSudoku(board1)) {
        solution.printBoard(board1);
    }

    std::vector<std::vector<char>> board2 = {
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };
    if (solution.solveSudoku(board2)) {
        solution.printBoard(board2);
    }

    std::vector<std::vector<char>> board3 = {
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '7', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    if (solution.solveSudoku(board3)) {
        solution.printBoard(board3);
    }

    return 0;
}
```