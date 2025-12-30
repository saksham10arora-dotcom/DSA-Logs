```cpp
// Problem: Sudoku Solver Variant
// Link: https://cses.fi/problemset/task/1848
// Description: Solve a Sudoku puzzle with a given grid.

#include <iostream>
#include <vector>

// Brute force approach with O(9^(n*n)) complexity
bool isValid(const std::vector<std::vector<int>>& grid, int row, int col, int num) {
    // Check the row
    for (int x = 0; x < 9; x++) {
        if (grid[row][x] == num) {
            return false;
        }
    }

    // Check the column
    for (int x = 0; x < 9; x++) {
        if (grid[x][col] == num) {
            return false;
        }
    }

    // Check the box
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

// Optimal solution with O(9^(n*n)) complexity
bool solveSudoku(std::vector<std::vector<int>>& grid) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isValid(grid, i, j, num)) {
                        grid[i][j] = num;
                        if (solveSudoku(grid)) {
                            return true;
                        }
                        grid[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printGrid(const std::vector<std::vector<int>>& grid) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << grid[i][j] << " ";
            if ((j + 1) % 3 == 0 && j < 8) {
                std::cout << "| ";
            }
        }
        std::cout << std::endl;
        if ((i + 1) % 3 == 0 && i < 8) {
            std::cout << "- - - - - - - - - - -" << std::endl;
        }
    }
}

int main() {
    // Test case 1
    std::vector<std::vector<int>> grid1 = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    if (solveSudoku(grid1)) {
        printGrid(grid1);
    } else {
        std::cout << "No solution exists" << std::endl;
    }

    // Test case 2
    std::vector<std::vector<int>> grid2 = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    if (solveSudoku(grid2)) {
        printGrid(grid2);
    } else {
        std::cout << "No solution exists" << std::endl;
    }

    // Test case 3
    std::vector<std::vector<int>> grid3 = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {4, 5, 6, 7, 8, 9, 1, 2, 3},
        {7, 8, 9, 1, 2, 3, 4, 5, 6},
        {2, 1, 4, 3, 6, 5, 8, 9, 7},
        {3, 6, 5, 8, 9, 7, 2, 1, 4},
        {8, 9, 7, 2, 1, 4, 3, 6, 5},
        {5, 3, 1, 6, 4, 2, 9, 7, 8},
        {6, 4, 2, 9, 7, 8, 5, 3, 1},
        {9, 7, 8, 5, 3, 1, 6, 4, 2}
    };
    if (solveSudoku(grid3)) {
        printGrid(grid3);
    } else {
        std::cout