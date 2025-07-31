/**
 * Problem: Cut Ribbon (Codeforces 189A)
 * Link: https://codeforces.com/problemset/problem/189/A
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// --- Optimal Solution (Tabulation) ---
// Time Complexity: O(N)
// Space Complexity: O(N)
void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> dp(n + 1, -1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (i >= a) dp[i] = max(dp[i], dp[i - a] + 1);
        if (i >= b) dp[i] = max(dp[i], dp[i - b] + 1);
        if (i >= c) dp[i] = max(dp[i], dp[i - c] + 1);
    }
    cout << dp[n] << endl;
}

int main() {
    // solve();
    return 0;
}








































