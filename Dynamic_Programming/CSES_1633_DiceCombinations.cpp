/**
 * Problem: Dice Combinations (CSES 1633)
 * Link: https://cses.fi/problemset/task/1633
 */

#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

// --- Optimal Solution (Tabulation) ---
// Time Complexity: O(N)
// Space Complexity: O(N)
void solve() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int die = 1; die <= 6; die++) {
            if (i - die >= 0) {
                dp[i] = (dp[i] + dp[i - die]) % MOD;
            }
        }
    }
    cout << dp[n] << endl;
}

int main() {
    // solve();
    return 0;
}
































