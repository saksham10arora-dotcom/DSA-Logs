```cpp
// LeetCode problem 52: N Queens II, https://leetcode.com/problems/n-queens-ii/
// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

class Solution {
public:
    // Brute force approach with O(N!) complexity
    int totalNQueensBruteForce(int n) {
        int count = 0;
        vector<string> board(n, string(n, '.'));
        function<void(int)> solve = [&](int row) {
            if (row == n) {
                count++;
                return;
            }
            for (int col = 0; col < n; col++) {
                if (isValid(board, row, col)) {
                    board[row][col] = 'Q';
                    solve(row + 1);
                    board[row][col] = '.';
                }
            }
        };
        solve(0);
        return count;
    }

    // Optimal solution with O(N!) complexity
    int totalNQueens(int n) {
        int count = 0;
        vector<int> cols(n, -1);
        function<void(int)> solve = [&](int row) {
            if (row == n) {
                count++;
                return;
            }
            for (int col = 0; col < n; col++) {
                if (isValid(cols, row, col)) {
                    cols[row] = col;
                    solve(row + 1);
                    cols[row] = -1;
                }
            }
        };
        solve(0);
        return count;
    }

    bool isValid(vector<int>& cols, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (cols[i] == col || cols[i] - i == col - row || cols[i] + i == col + row) {
                return false;
            }
        }
        return true;
    }

    bool isValid(vector<string>& board, int row, int col) {
        int n = board.size();
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    cout << solution.totalNQueens(4) << endl;  // Output: 2
    cout << solution.totalNQueens(8) << endl;  // Output: 92
    cout << solution.totalNQueens(1) << endl;  // Output: 1
    return 0;
}
```