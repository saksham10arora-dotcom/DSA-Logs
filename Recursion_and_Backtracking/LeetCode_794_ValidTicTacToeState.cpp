```cpp
// LeetCode problem 794: Valid Tic Tac Toe State
// https://leetcode.com/problems/valid-tic-tac-toe-state/
// A valid Tic Tac Toe state is one where the game is not over and the number of X's is either equal to the number of O's or one more.

#include <vector>
#include <string>

class Solution {
public:
    bool validTicTacToe(std::vector<std::string>& board) {
        int countX = 0, countO = 0;
        for (const auto& row : board) {
            for (char c : row) {
                if (c == 'X') countX++;
                else if (c == 'O') countO++;
            }
        }
        
        if (countX < countO || countX > countO + 1) return false;
        
        int winX = checkWin(board, 'X');
        int winO = checkWin(board, 'O');
        
        if (winX && winO) return false;
        if (winX && countX == countO) return false;
        if (winO && countX > countO) return false;
        
        return true;
    }
    
    int checkWin(const std::vector<std::string>& board, char c) {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == c && board[i][1] == c && board[i][2] == c) return 1;
            if (board[0][i] == c && board[1][i] == c && board[2][i] == c) return 1;
        }
        if (board[0][0] == c && board[1][1] == c && board[2][2] == c) return 1;
        if (board[0][2] == c && board[1][1] == c && board[2][0] == c) return 1;
        return 0;
    }
};

// Brute force approach: O(3^9) - checking all possible board configurations
// Optimal solution: O(1) - checking the counts of X's and O's and the winning conditions

int main() {
    Solution solution;
    std::vector<std::string> board1 = {"XOX", "OXO", "XOX"};
    std::vector<std::string> board2 = {"XOX", "XOX", "XOX"};
    std::vector<std::string> board3 = {"XXX", "   ", "   "};
    
    std::cout << std::boolalpha << solution.validTicTacToe(board1) << std::endl;  // true
    std::cout << std::boolalpha << solution.validTicTacToe(board2) << std::endl;  // false
    std::cout << std::boolalpha << solution.validTicTacToe(board3) << std::endl;  // false
    
    return 0;
}
```