/**
 * Problem: N-Queens (LeetCode 51)
 * Link: https://leetcode.com/problems/n-queens/
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// --- Optimal Solution (Backtracking with bitmask/sets) ---
// Time Complexity: O(N!)
// Space Complexity: O(N^2)
void backtrack(int r, int n, vector<string>& board, vector<bool>& cols, 
               vector<bool>& posDiag, vector<bool>& negDiag, vector<vector<string>>& res) {
    if (r == n) {
        res.push_back(board);
        return;
    }
    for (int c = 0; c < n; c++) {
        if (cols[c] || posDiag[r + c] || negDiag[r - c + n]) continue;
        
        board[r][c] = 'Q';
        cols[c] = posDiag[r + c] = negDiag[r - c + n] = true;
        
        backtrack(r + 1, n, board, cols, posDiag, negDiag, res);
        
        board[r][c] = '.';
        cols[c] = posDiag[r + c] = negDiag[r - c + n] = false;
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    vector<bool> cols(n, false), posDiag(2 * n, false), negDiag(2 * n, false);
    backtrack(0, n, board, cols, posDiag, negDiag, res);
    return res;
}

int main() {
    int n = 4;
    vector<vector<string>> res = solveNQueens(n);
    for (auto& b : res) {
        for (string row : b) cout << row << endl;
        cout << "---" << endl;
    }
    return 0;
}


























