/**
 * Problem: Interesting Drink (Codeforces 706B)
 * Link: https://codeforces.com/problemset/problem/706/B
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// --- Optimal Solution (Using upper_bound / Binary Search) ---
// Time Complexity: O((N + Q) log N)
// Space Complexity: O(N)
void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    sort(x.begin(), x.end());

    int q;
    cin >> q;
    while (q--) {
        int m;
        cin >> m;
        // Find first element > m
        auto it = upper_bound(x.begin(), x.end(), m);
        cout << distance(x.begin(), it) << "\n";
    }
}

int main() {
    // solve();
    return 0;
}



































