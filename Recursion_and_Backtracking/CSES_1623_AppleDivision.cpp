/**
 * Problem: Apple Division (CSES 1623)
 * Link: https://cses.fi/problemset/task/1623
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// --- Optimal Solution (Recursive Subset Search) ---
// Time Complexity: O(2^N)
// Space Complexity: O(N)
long long minDiff(int i, long long s1, long long s2, int n, const vector<int>& a) {
    if (i == n) {
        return abs(s1 - s2);
    }
    return min(
        minDiff(i + 1, s1 + a[i], s2, n, a),
        minDiff(i + 1, s1, s2 + a[i], n, a)
    );
}

void solve() {
    int n;
    // cin >> n;
    vector<int> a(n);
    // for (int i = 0; i < n; i++) cin >> a[i];
    // cout << minDiff(0, 0, 0, n, a) << endl;
}

int main() {
    // solve();
    return 0;
}


















