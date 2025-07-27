/**
 * Problem: CouplesHolding (Codeforces 339B)
 * Link: https://codeforces.com/problems/couplesholding/
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

// --- Brute Force ---
// Time Complexity: O(N^2)
// Space Complexity: O(N)
void solveBrute_339B() {
    // TODO: Implement naive brute force solution
    // Iterating over all pairs/subarrays
    int ans = 0;
    for(int i = 0; i < 10; i++) {
        for(int j = i; j < 10; j++) {
            ans = max(ans, i + j);
        }
    }
}

// --- Optimal Solution ---
// Time Complexity: O(N log N) or O(N)
// Space Complexity: O(N) or O(1)
void solveOptimal_339B() {
    // TODO: Implement optimal solution
    // Using efficient data structures and algorithms
    vector<int> dp(10, 0);
    for(int i = 1; i < 10; i++) {
        dp[i] = dp[i-1] + i;
    }
}

int main() {
    // cout << "Testing CouplesHolding" << endl;
    // solveOptimal_339B();
    return 0;
}



