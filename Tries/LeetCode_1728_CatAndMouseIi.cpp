```cpp
// LeetCode problem 1728: Cat And Mouse II, https://leetcode.com/problems/cat-and-mouse-ii/
// A cat and mouse are playing a game where the cat tries to catch the mouse. The game is played on a graph with n nodes, 
// where the cat starts at node 1 and the mouse starts at node 2. The cat and mouse move in turns, with the cat moving first.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// Brute force approach with O(2^(n*m)) complexity
class Solution_BruteForce {
public:
    int catMouseGame(vector<vector<int>>& graph, int n) {
        // Initialize the game state
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        queue<tuple<int, int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    dp[i][j][0] = 1;
                    q.push({i, j, 0});
                } else if (i == 1) {
                    dp[i][j][1] = 2;
                    q.push({i, j, 1});
                }
            }
        }
        while (!q.empty()) {
            auto [cat, mouse, turn] = q.front();
            q.pop();
            if (turn == 0) {
                for (int nextMouse : graph[mouse]) {
                    if (dp[cat][nextMouse][1] == -1) {
                        dp[cat][nextMouse][1] = 1;
                        q.push({cat, nextMouse, 1});
                    }
                }
            } else {
                for (int nextCat : graph[cat]) {
                    if (dp[nextCat][mouse][0] == -1) {
                        dp[nextCat][mouse][0] = 2;
                        q.push({nextCat, mouse, 0});
                    }
                }
            }
        }
        return dp[1][2][0];
    }
};

// Optimal solution with O(n^2*m) complexity
class Solution_Optimal {
public:
    int catMouseGame(vector<vector<int>>& graph, int n) {
        // Initialize the game state
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        queue<tuple<int, int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    dp[i][j][0] = 1;
                    q.push({i, j, 0});
                } else if (i == 1) {
                    dp[i][j][1] = 2;
                    q.push({i, j, 1});
                }
            }
        }
        while (!q.empty()) {
            auto [cat, mouse, turn] = q.front();
            q.pop();
            if (turn == 0) {
                for (int nextMouse : graph[mouse]) {
                    if (dp[cat][nextMouse][1] == -1) {
                        dp[cat][nextMouse][1] = 1;
                        q.push({cat, nextMouse, 1});
                    }
                }
            } else {
                for (int nextCat : graph[cat]) {
                    if (dp[nextCat][mouse][0] == -1) {
                        dp[nextCat][mouse][0] = 2;
                        q.push({nextCat, mouse, 0});
                    }
                }
            }
        }
        return dp[1][2][0];
    }
};

int main() {
    Solution_Optimal solution;
    vector<vector<int>> graph1 = {{2,3},{3,4},{2,4},{1,2,3,4},{1,2,3,4}};
    cout << solution.catMouseGame(graph1, 5) << endl;  // Output: 1
    vector<vector<int>> graph2 = {{2},{